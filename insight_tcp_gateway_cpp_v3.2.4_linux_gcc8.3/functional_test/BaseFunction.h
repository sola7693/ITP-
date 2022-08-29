#ifndef BASEFUNCTION_H
#define BASEFUNCTION_H

#include <string>
#include <cassert>
#include <iostream>
#include <memory>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <chrono>
#include <ctime>
#include  <stdlib.h>

#if defined(WIN32) || defined(_WIN32)
#include <windows.h> 
#include <direct.h>
#include <sys/types.h>
#include <sys/stat.h>
#else
#include <sys/stat.h> 
#include <unistd.h> 
#endif

#include "base_define.h"
#include "mdc_client_factory.h"
#include "client_interface.h"
#include "message_handle.h"

using namespace com::htsc::mdc::gateway;
using namespace com::htsc::mdc::model;
using namespace com::htsc::mdc::insight::model;

#if defined(_MSC_VER) && (_MSC_VER < 1900)
#define snprintf _snprintf
#endif

void msleep(int ms);
std::string get_security_type_name(const ESecurityType& securityType);
std::string get_data_type_name(const EMarketDataType& type);
bool create_folder(const std::string& folder_path);
bool folder_exist(const std::string& dir);
void save_debug_string(std::string base_forder, std::string data_type,
	std::string security_type, std::string SecurityId, const std::string& debug_string);

void save_debug_string(std::string base_forder, std::string data_type,
	std::string security_type, std::string SecurityId, const std::string& debug_string) {
	char file_name[128] = { 0 };
	snprintf(file_name, 128, "%s/%s_%s_%s.csv",
		base_forder.c_str(), data_type.c_str(), security_type.c_str(), SecurityId.c_str());
	std::ofstream ofs(file_name, std::fstream::out | std::fstream::app);
	//输出到文件
	if (ofs.good()) {
		ofs << debug_string << std::endl;
	}
	ofs.close();
}

std::string get_security_type_name(const ESecurityType& securityType) {
	std::string security_type;
	switch (securityType) {
	case StockType:
	{
		security_type = "StockType";
		break;
	}
	case IndexType:
	{
		security_type = "IndexType";
		break;
	}
	case BondType:
	{
		security_type = "BondType";
		break;
	}
	case FundType:
	{
		security_type = "FundType";
		break;
	}
	case OptionType:
	{
		security_type = "OptionType";
		break;
	}
	case FuturesType:
	{
		security_type = "FuturesType";
		break;
	}
	case SpotType:
	{
		security_type = "SpotType";
		break;
	}
	case ForexType:
	{
		security_type = "ForexType";
		break;
	}
	case WarrantType:
	{
		security_type = "WarrantType";
		break;
	}
	default:
	{
		security_type = "UnknownType";
		break;
	}
	}
	return security_type;
}

std::string get_data_type_name(const EMarketDataType& type) {
	std::string data_type;
	switch (type) {
	case MD_TICK:
	{
		data_type = "MD_TICK";
		break;
	}
	case MD_TRANSACTION:
	{
		data_type = "MD_TRANSACTION";
		break;
	}
	case MD_ORDER:
	{
		data_type = "MD_ORDER";
		break;
	}
	case MD_CONSTANT:
	{
		data_type = "MD_CONSTANT";
		break;
	}
	case MD_KLINE_1MIN:
	{
		data_type = "MD_KLINE_1MIN";
		break;
	}
	case MD_KLINE_5MIN:
	{
		data_type = "MD_KLINE_5MIN";
		break;
	}
	case MD_KLINE_15MIN:
	{
		data_type = "MD_KLINE_15MIN";
		break;
	}
	case MD_KLINE_30MIN:
	{
		data_type = "MD_KLINE_30MIN";
		break;
	}
	case MD_KLINE_60MIN:
	{
		data_type = "MD_KLINE_60MIN";
		break;
	}
	case MD_KLINE_1D:
	{
		data_type = "MD_KLINE_1D";
		break;
	}
	case MD_TWAP_1MIN:
	{
		data_type = "MD_TWAP_1MIN";
		break;
	}
	case MD_VWAP_1MIN:
	{
		data_type = "MD_VWAP_1MIN";
		break;
	}
	case MD_VWAP_1S:
	{
		data_type = "MD_VWAP_1S";
		break;
	}
	case MD_SIMPLE_TICK:
	{
		data_type = "MD_SIMPLE_TICK";
		break;
	}
	case AD_UPSDOWNS_ANALYSIS:
	{
		data_type = "AD_UPSDOWNS_ANALYSIS";
		break;
	}
	case AD_INDICATORS_RANKING:
	{
		data_type = "AD_INDICATORS_RANKING";
		break;
	}
	case DYNAMIC_PACKET:
	{
		data_type = "DYNAMIC_PACKET";
		break;
	}
	case AD_FUND_FLOW_ANALYSIS:
	{
		data_type = "AD_FUND_FLOW_ANALYSIS";
		break;
	}
	case AD_VOLUME_BYPRICE:
	{
		data_type = "AD_VOLUME_BYPRICE";
		break;
	}
	case MD_ETF_BASICINFO:
	{
		data_type = "MD_ETF_BASICINFO";
		break;
	}
	case AD_ORDERBOOK_SNAPSHOT:
	{
		data_type = "AD_ORDERBOOK_SNAPSHOT";
		break;
	}
	default:
	{
		data_type = "UnknownDataType";
	}
	}
	return data_type;
}

/**
* 创建目录
*/
bool create_folder(const std::string& folder_path) {
	int ret = 0;
#if defined(_WIN32) || defined(WIN32)
	ret = _mkdir(folder_path.c_str());
#else
	ret = mkdir(folder_path.c_str(), 0777);
#endif
	return ret == 0;
}

bool folder_exist(const std::string& dir) {
#if defined(_WIN32) || defined(WIN32)
#if defined(_MSC_VER) && _MSC_VER >= 1900
	struct _stat fileStat;
	if ((_stat(dir.c_str(), &fileStat) == 0) && (fileStat.st_mode & _S_IFDIR)) {
		return true;
	} else {
		return false;
	}
#else
	struct _stat fileStat;
	if ((_stat(dir.c_str(), &fileStat) == 0) && (fileStat.st_mode & _S_IFDIR)) {
		return true;
	} else {
		return false;
	}
#endif
#else
	struct stat fileStat;
	if ((stat(dir.c_str(), &fileStat) == 0) && S_ISDIR(fileStat.st_mode)) {
		return true;
	} else {
		return false;
	}
#endif
}

void msleep(int ms) {
#if defined(WIN32) || defined(_WIN32)
	Sleep(ms);
#else
	sleep(ms / 1000);
#endif
}

#endif
