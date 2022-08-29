#ifndef INSIGHTHANDLE_H
#define INSIGHTHANDLE_H
#include "BaseFunction.h"

#include "base_define.h"
#include "mdc_client_factory.h"
#include "client_interface.h"
#include "message_handle.h"
#include <mutex>
#include <map>

using namespace com::htsc::mdc::gateway;
using namespace com::htsc::mdc::model;
using namespace com::htsc::mdc::insight::model;

//测试版处理类
class InsightHandle : public MessageHandle {
public:
	/**
	* 构造函数
	*/
	InsightHandle(const std::string& forder_name) :base_forder_(forder_name), service_value_(0), query_exit_(false),
		reconnect_(false), login_success_(false), reconnect_count_(0), no_connections_(false) {
		//验证基础目录，如果不存在则创建创建目录
		if (!folder_exist(base_forder_.c_str())) {
			debug_print("input folder[%s] not exists!\n", base_forder_.c_str());
			if (!create_folder(base_forder_)) {
				error_print("mkdir base folder[%s] failed! maybe exists!\n", base_forder_.c_str());
			} else {
				debug_print("mkdir base folder[%s] successfully!\n", base_forder_.c_str());
			}
		}
	}

	/**
	* 析构函数
	*/
	virtual ~InsightHandle() {}

public:
	/**
	* 发送订阅请求后服务端回复消息，查看是否订阅成功
	* @param[in] data_stream
	*/
	void OnServiceMessage(const ::com::htsc::mdc::insight::model::MarketDataStream& data_stream) {
		debug_print("==========> NewHandle: process a Service message");
		service_value_ = 1;
	}

	/**
	* 处理订阅后推送的实时行情数据
	* @param[in] data
	*/
	void OnMarketData(const com::htsc::mdc::insight::model::MarketData& data) {
		static unsigned int count = 0;
		++count;
		if (count % 10000 == 0) {
			debug_print("==========> NewHandle: process %d MarketData message", count);
		}
		//获取数据类型
		std::string data_type = get_data_type_name(data.marketdatatype());
		switch (data.marketdatatype()) {
		case MD_TICK:
		{//快照
			if (data.has_mdstock()) {//股票
				//获取证券类型
				std::string security_type = get_security_type_name(data.mdstock().securitytype());
				//写文件
				save_debug_string(base_forder_, data_type, security_type,
					data.mdstock().htscsecurityid(), data.mdstock().ShortDebugString());
				//访问股票数据部分字段
				if (false) {
					MDStock stock = data.mdstock();
					debug_print("HTSCSecurityID : %s", stock.htscsecurityid().c_str());
					debug_print("MDDate : %d", stock.mddate());
					//访问队列(queue)数据方式
					for (int i = 0; i < stock.buypricequeue_size(); i++) {
						debug_print("Buy%dPrice : %d", i + 1, stock.buypricequeue(i));
					}
				}
			} else if (data.has_mdbond()) {//债券
				std::string security_type = get_security_type_name(data.mdbond().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdbond().htscsecurityid(), data.mdbond().ShortDebugString());
			} else if (data.has_mdindex()) {//指数
				std::string security_type = get_security_type_name(data.mdindex().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdindex().htscsecurityid(), data.mdindex().ShortDebugString());
			} else if (data.has_mdfund()) {//基金
				std::string security_type = get_security_type_name(data.mdfund().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdfund().htscsecurityid(), data.mdfund().ShortDebugString());
			} else if (data.has_mdoption()) {//期权
				std::string security_type = get_security_type_name(data.mdoption().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdoption().htscsecurityid(), data.mdoption().ShortDebugString());
			} else if (data.has_mdfuture()) {//期货
				std::string security_type = get_security_type_name(data.mdfuture().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdfuture().htscsecurityid(), data.mdfuture().ShortDebugString());
			} else if (data.has_mdforex()) {//外汇
				std::string security_type = get_security_type_name(data.mdforex().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdforex().htscsecurityid(), data.mdforex().ShortDebugString());
			} else if (data.has_mdspot()) {//现货
				std::string security_type = get_security_type_name(data.mdspot().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdspot().htscsecurityid(), data.mdspot().ShortDebugString());
			} else if (data.has_mdwarrant()) {//权证
				std::string security_type = get_security_type_name(data.mdwarrant().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdwarrant().htscsecurityid(), data.mdwarrant().ShortDebugString());
			}
			break;
		}
		case MD_TRANSACTION:
		{//逐笔成交
			if (data.has_mdtransaction()) {
				std::string security_type = get_security_type_name(data.mdtransaction().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdtransaction().htscsecurityid(), data.mdtransaction().ShortDebugString());
			}
			break;
		}
		case MD_ORDER:
		{//逐笔委托
			if (data.has_mdorder()) {
				std::string security_type = get_security_type_name(data.mdorder().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdorder().htscsecurityid(), data.mdorder().ShortDebugString());
			}
			break;
		}
		case MD_CONSTANT:
		{//静态信息
			if (data.has_mdconstant()) {
				std::string security_type = get_security_type_name(data.mdconstant().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdconstant().htscsecurityid(), data.mdconstant().ShortDebugString());
			}
		}
		case MD_KLINE_15S:
		case MD_KLINE_1MIN:
		case MD_KLINE_5MIN:
		case MD_KLINE_15MIN:
		case MD_KLINE_30MIN:
		case MD_KLINE_60MIN:
		case MD_KLINE_1D:
		{//实时数据只提供15S和1MIN K线
			if (data.has_mdkline()) {
				std::string security_type = get_security_type_name(data.mdkline().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdkline().htscsecurityid(), data.mdkline().ShortDebugString());
			}
			break;
		}
		case MD_TWAP_1MIN:
		{//TWAP数据
			if (data.has_mdtwap()) {
				std::string security_type = get_security_type_name(data.mdtwap().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdtwap().htscsecurityid(), data.mdtwap().ShortDebugString());
			}
			break;
		}
		case MD_VWAP_1MIN:
		case MD_VWAP_1S:
		{//VWAP数据
			if (data.has_mdvwap()) {
				std::string security_type = get_security_type_name(data.mdvwap().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdvwap().htscsecurityid(), data.mdvwap().ShortDebugString());
			}
			break;
		}
		case AD_FUND_FLOW_ANALYSIS:
		{//资金流向分析数据
			if (data.has_mdfundflowanalysis()) {
				std::string security_type = get_security_type_name(data.mdfundflowanalysis().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdfundflowanalysis().htscsecurityid(), data.mdfundflowanalysis().ShortDebugString());
			}
			break;
		}
		case MD_ETF_BASICINFO:
		{//ETF的基础信息
			if (data.has_mdetfbasicinfo()) {
				std::string security_type = get_security_type_name(data.mdetfbasicinfo().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.mdetfbasicinfo().htscsecurityid(), data.mdetfbasicinfo().ShortDebugString());
			}
		}
		case AD_ORDERBOOK_SNAPSHOT:
		{
			if (data.has_orderbooksnapshot()) {
				std::string security_type = get_security_type_name(data.orderbooksnapshot().securitytype());
				save_debug_string(base_forder_, data_type, security_type,
					data.orderbooksnapshot().htscsecurityid(), data.orderbooksnapshot().ShortDebugString());
			}
		}
		default:
			break;
		}
	}

	/**
	* 处理回测请求成功后推送的回测数据,多回放任务并发时存在线程冲突风险
	* @param[in] PlaybackPayload 回测数据
	*/
	void OnPlaybackPayload(const PlaybackPayload& payload) {
		debug_print("------- PARSE message Playback payload, id:%s", payload.taskid().c_str());
		//const MarketDataStream& stream = payload.marketdatastream();
		//debug_print("total number=%d, serial=%d, isfinish=%d", stream.totalnumber(), stream.serial(), stream.isfinished());
		//google::protobuf::RepeatedPtrField<MarketData>::const_iterator it
		//	= stream.marketdatalist().marketdatas().begin();
		//while (it != stream.marketdatalist().marketdatas().end()) {
		//	OnMarketData(*it);
		//	++it;
		//}
	}

	/**
	* 处理回测状态
	* @param[in] PlaybackStatus 回测状态
	*/
	void OnPlaybackStatus(const com::htsc::mdc::insight::model::PlaybackStatus& status) {
		//INITIALIZING = 11            // 初始化中
		//PREPARING = 12               // 准备中
		//PREPARED = 13				   // 准备完成
		//RUNNING = 14				   // 运行中
		//APPENDING = 15               // 队列等待中
		//CANCELED = 16                // 已取消
		//COMPLETED = 17               // 已完成
		//FAILED = 18                  // 任务失败
		service_value_ = status.taskstatus();
		int task_status = status.taskstatus();
		if (task_status == CANCELED || task_status == COMPLETED || task_status == FAILED)
		{
			task_id_mutex_.lock();
			task_id_status_.erase(status.taskid());
			task_id_mutex_.unlock();
		}
	}

	/**
	* 处理查询请求返回结果
	* @param[in] MDQueryResponse 查询请求返回结果
	*/
	void OnQueryResponse(const ::com::htsc::mdc::insight::model::MDQueryResponse& response) {
		if (!response.issuccess()) {
			error_print("query response result: FAIL! ERROR INFO[%d,%s]",
				response.errorcontext().errorcode(), response.errorcontext().message().c_str());
			query_exit_ = true;
			return;
		} else {
			const MarketDataStream& stream = response.marketdatastream();
			debug_print("query response total number=%d, serial=%d, isfinish=%d",
				stream.totalnumber(), stream.serial(), stream.isfinished());
			if (stream.isfinished() == 1) {
				query_exit_ = true;
			}
			google::protobuf::RepeatedPtrField<MarketData>::const_iterator it
				= stream.marketdatalist().marketdatas().begin();
			while (it != stream.marketdatalist().marketdatas().end()) {
				OnMarketData(*it);
				++it;
			}
		}
	}

	/**
	* 登录成功
	*/
	void OnLoginSuccess() {
		debug_print("-----------------------------");
		debug_print("------- OnLoginSuccess -------");
		login_success_ = true;
		debug_print("-----------------------------");
	}

	/**
	* 登录失败
	*/
	void OnLoginFailed(int error_no, const std::string& message) {
		error_print("-----------------------------");
		error_print("------- OnLoginFailed -------");
		login_success_ = false;
		error_print("------- server reply:%d,%s", error_no, message.c_str());
		error_print("-----------------------------");
	}

	/**
	* 处理所有服务器都无法连接的情况
	*/
	void OnNoConnections() {
		error_print("-----------------------------");
		error_print("------- OnNoConnections -----");
		no_connections_ = true;
		reconnect_ = true;
		error_print("-----------------------------");
	}

	/**
	* 发生重连时
	*/
	void OnReconnect() {
		error_print("-----------------------------");
		error_print("------- OnReconnect -----");
		++reconnect_count_;
		reconnect_ = true;
		error_print("-----------------------------");
	}

public:
	int service_value_;
	bool query_exit_;
	bool reconnect_;
	bool login_success_;
	bool no_connections_;
	int reconnect_count_;
	std::string base_forder_; //基础目录
	std::mutex task_id_mutex_;
	std::map<std::string, int> task_id_status_;
};

#endif