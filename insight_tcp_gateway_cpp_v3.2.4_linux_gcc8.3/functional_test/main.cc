#include "InsightHandle.h"
#include "BaseFunction.h"

std::string user = "UATUSER013558";
std::string password = "3j3c#92jc";
std::string ip = "168.61.2.39";
int port = 9072;
std::string cert_folder = "./cert";
std::string export_folder = "./export_folder";
int test_type = 1;

ClientInterface* client = NULL;
InsightHandle* handle = NULL;

/**
* 初始化配置
*/
void test_init() {
	open_trace();//打开trace，输出流量日志消息，默认打开
	open_heartbeat_trace();//打开heartbeat_trace，输出心跳日志消息，默认打开
	open_response_callback();//打开response_callback，自行处理response消息	
	//open_cout_log();
	//close_cout_log();
	//close_trace();
	//close_file_log();
	//close_heartbeat_trace();//关闭heartbeat_trace，不输出心跳日志消息
	//close_response_callback();//关闭response_callback，程序自动处理response消息
	
}

/**
* 登录
* @return 返回值 true 成功 false 失败
*/
bool test_login() {
	client = ClientFactory::Instance()->CreateClient(true, cert_folder.c_str());
	if (!client) {
		error_print("create client failed!");
		ClientFactory::Uninstance();
		client = NULL;
		return false;
	}
	//注册句柄
	handle = new InsightHandle(export_folder);
	client->set_handle_pool_thread_count(10);
	client->RegistHandle(handle);
	//添加备用发现网关地址
	std::vector<std::string> backup_list;
	backup_list.push_back("221.6.24.39:8262");
	backup_list.push_back("112.4.154.165:8262");
	backup_list.push_back("221.131.138.171:9242");
	//登录
	int ret = client->LoginByServiceDiscovery(ip, port, user, password, false, backup_list);
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		ClientFactory::Uninstance();
		client = NULL;
		DELETE_P(handle);
		return false;
	}
	return true;
}

/**
* 退出
*/
void test_logout() {
	ClientFactory::Uninstance();
	client = NULL;
	DELETE_P(handle);
}

/**
* 订阅全市场证券数据并通过ID剔除部分证券
* 效率低，不推荐使用
*/
void test_subscribe_by_all_and_decrease() {
	if (client == NULL || handle == NULL) {
		error_print("create client failed!");
		return;
	}
	//订阅 SubscribeAll
	ESubscribeActionType action_type = COVERAGE;
	std::unique_ptr<SubscribeAll> subscribe_all(new SubscribeAll());
	subscribe_all->add_marketdatatypes(MD_TICK);
	subscribe_all->add_marketdatatypes(MD_TRANSACTION);
	subscribe_all->add_marketdatatypes(MD_ORDER);
	if ((client->SubscribeAll(action_type, &(*subscribe_all)) < 0)) {
		return;
	}
	//通过DECREASE减少订阅
	action_type = DECREASE;
	std::unique_ptr<SubscribeByID> subscribe_decrease(new SubscribeByID());
	SubscribeByIDDetail* id_detail = subscribe_decrease->add_subscribebyiddetails();
	id_detail->set_htscsecurityid("000002.SZ");
	id_detail->add_marketdatatypes(MD_TICK);
	//订阅
	int ret = client->SubscribeByID(action_type, &(*subscribe_decrease));
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		return;
	}
	std::cout << "input any key to quit...>>";
	char a[4096];
	std::cin >> a;
	return;
}

/**
* 根据证券数据来源订阅行情数据,由三部分确定行情数据
* 行情源(SecurityIdSource):XSHG(沪市)|XSHE(深市)|...，不填默认全选
* 证券类型(SecurityType):BondType(债)|StockType(股)|FundType(基)|IndexType(指)|OptionType(期权)|...
* 数据类型(MarketDataTypes):MD_TICK(快照)|MD_TRANSACTION(逐笔成交)|MD_ORDER(逐笔委托)|...
*/
void test_subscribe_by_source_type() {
	if (client == NULL || handle == NULL) {
		error_print("create client failed!");
		return;
	}
	//订阅 SubscribeBySourceType
	ESubscribeActionType action_type = COVERAGE;
	std::unique_ptr<SubscribeBySourceType> source_type(new SubscribeBySourceType());

	//////债券
	//SubscribeBySourceTypeDetail* detail_1 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_1 = new SecuritySourceType();
	//security_source_type_1->set_securityidsource(XSHG);
	//security_source_type_1->set_securitytype(BondType);
	//detail_1->set_allocated_securitysourcetypes(security_source_type_1);
	//detail_1->add_marketdatatypes(MD_TICK);

	//SubscribeBySourceTypeDetail* detail_2 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_2 = new SecuritySourceType();
	//security_source_type_2->set_securityidsource(XSHE);
	//security_source_type_2->set_securitytype(BondType);
	//detail_2->set_allocated_securitysourcetypes(security_source_type_2);
	//detail_2->add_marketdatatypes(MD_TICK);

	////股票
	SubscribeBySourceTypeDetail* detail_3 = source_type->add_subscribebysourcetypedetail();
	SecuritySourceType* security_source_type_3 = new SecuritySourceType();
	security_source_type_3->set_securitytype(StockType);
	security_source_type_3->set_securityidsource(XSHG);
	detail_3->set_allocated_securitysourcetypes(security_source_type_3);
	detail_3->add_marketdatatypes(MD_TICK);
	detail_3->add_marketdatatypes(MD_TRANSACTION);
	//detail_3->add_marketdatatypes(MD_ORDER);

	SubscribeBySourceTypeDetail* detail_4 = source_type->add_subscribebysourcetypedetail();
	SecuritySourceType* security_source_type_4 = new SecuritySourceType();
	security_source_type_4->set_securityidsource(XSHE);
	security_source_type_4->set_securitytype(StockType);
	detail_4->set_allocated_securitysourcetypes(security_source_type_4);
	detail_4->add_marketdatatypes(MD_TICK);
	detail_4->add_marketdatatypes(MD_TRANSACTION);
	//detail_4->add_marketdatatypes(MD_ORDER);

	//////基金
	//SubscribeBySourceTypeDetail* detail_5 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_5 = new SecuritySourceType();
	//security_source_type_5->set_securityidsource(XSHG);
	//security_source_type_5->set_securitytype(FundType);
	//detail_5->set_allocated_securitysourcetypes(security_source_type_5);
	//detail_5->add_marketdatatypes(MD_TICK);
	////detail_5->add_marketdatatypes(MD_TRANSACTION);
	////detail_5->add_marketdatatypes(MD_ORDER);

	//SubscribeBySourceTypeDetail* detail_6 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_6 = new SecuritySourceType();
	//security_source_type_6->set_securityidsource(XSHE);
	//security_source_type_6->set_securitytype(FundType);
	//detail_6->set_allocated_securitysourcetypes(security_source_type_6);
	//detail_6->add_marketdatatypes(MD_TICK);
	////detail_6->add_marketdatatypes(MD_TRANSACTION);
	////detail_6->add_marketdatatypes(MD_ORDER);

	//////指数
	//SubscribeBySourceTypeDetail* detail_7 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_7 = new SecuritySourceType();
	//security_source_type_7->set_securityidsource(XSHG);
	//security_source_type_7->set_securitytype(IndexType);
	//detail_7->set_allocated_securitysourcetypes(security_source_type_7);
	//detail_7->add_marketdatatypes(MD_TICK);

	//SubscribeBySourceTypeDetail* detail_8 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_8 = new SecuritySourceType();
	//security_source_type_8->set_securityidsource(XSHE);
	//security_source_type_8->set_securitytype(IndexType);
	//detail_8->set_allocated_securitysourcetypes(security_source_type_8);
	//detail_8->add_marketdatatypes(MD_TICK);

	//////期权
	//SubscribeBySourceTypeDetail* detail_9 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_9 = new SecuritySourceType();
	//security_source_type_9->set_securityidsource(XSHG);
	//security_source_type_9->set_securitytype(OptionType);
	//detail_9->set_allocated_securitysourcetypes(security_source_type_9);
	//detail_9->add_marketdatatypes(MD_TICK);

	//SubscribeBySourceTypeDetail* detail_10 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_10 = new SecuritySourceType();
	//security_source_type_10->set_securityidsource(XSHE);
	//security_source_type_10->set_securitytype(OptionType);
	//detail_10->set_allocated_securitysourcetypes(security_source_type_10);
	//detail_10->add_marketdatatypes(MD_TICK);

	////期货
	//SubscribeBySourceTypeDetail* detail_11 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_11 = new SecuritySourceType();
	//security_source_type_11->set_securitytype(FuturesType);
	//detail_11->set_allocated_securitysourcetypes(security_source_type_11);
	//detail_11->add_marketdatatypes(MD_TICK);

	////现货行情
	//SubscribeBySourceTypeDetail* detail_12 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_12 = new SecuritySourceType();
	//security_source_type_12->set_securitytype(SpotType);
	//detail_12->set_allocated_securitysourcetypes(security_source_type_12);
	//detail_12->add_marketdatatypes(MD_TICK);

	////汇率
	//SubscribeBySourceTypeDetail* detail_13 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_13 = new SecuritySourceType();
	//security_source_type_13->set_securitytype(ForexType);
	//detail_13->set_allocated_securitysourcetypes(security_source_type_13);
	//detail_13->add_marketdatatypes();

	//权证
	//SubscribeBySourceTypeDetail* datail_14 = source_type->add_subscribebysourcetypedetail();
	//SecuritySourceType* security_source_type_14 = new SecuritySourceType();
	//security_source_type_14->set_securitytype(WarrantType);
	//security_source_type_14->set_securityidsource(XHKG);
	//datail_14->set_allocated_securitysourcetypes(security_source_type_14);
	//datail_14->add_marketdatatypes(MD_TICK);

	//订阅
	int ret = client->SubscribeBySourceType(action_type, &(*source_type));
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		return;
	}
	std::cout << "input any key to quit...>>";
	char a[4096];
	std::cin >> a;
	return;
}

/**
* 根据证券ID来源订阅行情数据
*/
void test_subscribe_by_id() {
	if (client == NULL || handle == NULL) {
		error_print("create client failed!");
		return;
	}
	//订阅 SubscribeByID
	ESubscribeActionType action_type = COVERAGE;
	std::unique_ptr<SubscribeByID> id(new SubscribeByID());
	//list1订阅MD_TRANSACTION、MD_ORDER
	std::vector<std::string> securityIdList1;
	securityIdList1.clear();
	securityIdList1.push_back("000014.SZ");
	securityIdList1.push_back("000015.SZ");
	securityIdList1.push_back("000016.SZ");
	for (unsigned int index = 0; index < securityIdList1.size(); index++) {
		SubscribeByIDDetail* id_detail = id->add_subscribebyiddetails();
		id_detail->set_htscsecurityid(securityIdList1[index]);
		id_detail->add_marketdatatypes(MD_TICK);
		id_detail->add_marketdatatypes(MD_TRANSACTION);
	}
	//list2订阅MD_ORDER
	std::vector<std::string> securityIdList2;
	securityIdList2.clear();
	securityIdList2.push_back("000017.SZ");
	securityIdList2.push_back("000018.SZ");
	securityIdList2.push_back("000019.SZ");
	securityIdList2.push_back("000020.SZ");
	for (unsigned int index = 0; index < securityIdList2.size(); index++) {
		SubscribeByIDDetail* id_detail = id->add_subscribebyiddetails();
		id_detail->set_htscsecurityid(securityIdList2[index]);
		id_detail->add_marketdatatypes(MD_TICK);
		id_detail->add_marketdatatypes(MD_ORDER);
	}
	//add_globalmarketdatatypes会覆盖所有的数据类型设置
	id->add_globalmarketdatatypes(MD_TRANSACTION);

	//订阅
	int ret = client->SubscribeByID(action_type, &(*id));
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		return;
	}
	std::cout << "input any key to quit...>>";
	char a[4096];
	std::cin >> a;
	return;
}

/**
* 查询证券的基础信息/最新状态
* 需要关闭response_callback，response消息通过查询接口参数返回
*/
void test_query() {
	if (client == NULL || handle == NULL) {
		error_print("create client failed!");
		return;
	}
	//配置查询请求
	std::unique_ptr<MDQueryRequest> request(new MDQueryRequest());
	//设置查询请求类型
	/*
	QUERY_TYPE_BASE_INFORMATION			// 查询历史上所有的指定证券的基础信息(MarketDataTypes = MD_CONSTANT)
	QUERY_TYPE_LATEST_BASE_INFORMATION	// 查询今日最新的指定证券的基础信息(MarketDataTypes = MD_CONSTANT)
	QUERY_TYPE_STATUS					// 查询指定证券的最新一条Tick数据(MarketDataTypes = MD_TICK)
	QUERY_TYPE_ETF_BASE_INFORMATION    //查询ETF的基础信息(MarketDataTypes = MD_ETF_BASICINFO)
	*/
	request->set_querytype(QUERY_TYPE_LATEST_BASE_INFORMATION);
	SecuritySourceType* security_source_type = request->add_securitysourcetype();
	security_source_type->set_securityidsource(XSHE);
	security_source_type->set_securitytype(IndexType);
	request->add_htscsecurityids("601688.SH");

	//接收查询回复
	std::vector<MDQueryResponse*>* responses;
	//发送查询请求并接收回复消息
	int ret = client->RequestMDQuery(&(*request), responses);
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		return;
	}

	//访问responses，成员如下：
	/*
	int32 queryType;             	     //查询类型
	bool isSuccess;                    // 请求是否成功
	InsightErrorContext errorContext;  // 错误信息
	MarketDataStream marketDataStream; //行情数据包
	*/
	debug_print("query return message count=%d\n\n\n", responses->size());
	//处理查询结果
	for (unsigned int i = 0; i < responses->size(); ++i) {
		if (!responses->at(i)->issuccess()) {
			continue;
		}
		if (!responses->at(i)->has_marketdatastream()) {
			continue;
		}
		//遍历constants
		google::protobuf::RepeatedPtrField<MarketData>::const_iterator it
			= responses->at(i)->marketdatastream().marketdatalist().marketdatas().begin();
		google::protobuf::RepeatedPtrField<MarketData>::const_iterator end
			= responses->at(i)->marketdatastream().marketdatalist().marketdatas().end();
		while (it != end) {
			handle->OnMarketData(*it);
			it++;
		}
	}
	//释放空间
	client->ReleaseQueryResult(responses);
	return;
}

/**
* 查询证券的基础信息/最新状态
* 需要打开response_callback，response消息通过回调函数返回
*/
void test_query_callback() {
	if (client == NULL || handle == NULL) {
		error_print("create client failed!");
		return;
	}
	//配置查询请求
	std::unique_ptr<MDQueryRequest> request(new MDQueryRequest());
	//设置查询请求类型
	/*
	QUERY_TYPE_BASE_INFORMATION			// 查询历史上所有的指定证券的基础信息(MarketDataTypes = MD_CONSTANT)
	QUERY_TYPE_LATEST_BASE_INFORMATION	// 查询今日最新的指定证券的基础信息(MarketDataTypes = MD_CONSTANT)
	QUERY_TYPE_STATUS					// 查询指定证券的最新一条Tick数据(MarketDataTypes = MD_TICK)
	QUERY_TYPE_ETF_BASE_INFORMATION    //查询ETF的基础信息(MarketDataTypes = MD_ETF_BASICINFO)
	*/
	//查询601688.SH + 深交所全市场股票的静态信息
	request->set_querytype(QUERY_TYPE_LATEST_BASE_INFORMATION);
	request->add_htscsecurityids("510300.SH");
	SecuritySourceType* source_type1 = request->add_securitysourcetype();
	source_type1->set_securitytype(StockType);
	source_type1->set_securityidsource(XSHE);
	SecuritySourceType* source_type2 = request->add_securitysourcetype();
	source_type2->set_securitytype(StockType);
	source_type2->set_securityidsource(XSHG);

	handle->query_exit_ = false;
	//发送查询请求
	int ret = client->RequestMDQuery(&(*request));
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		return;
	}
	
	while (true) {
		if (handle->query_exit_) {
			break;
		}
		else{
			msleep(1);
		}		
	}
}

/**
* 进行历史行情回测，单次回测的最大数据量限制请查阅用户使用手册
*/
void test_playback() {
	if (client == NULL || handle == NULL) {
		error_print("create client failed!");
		return;
	}
	//request 需要提前分配空间，并由调用方释放
	std::vector<std::string> securityIdList1;
	securityIdList1.clear();
	securityIdList1.push_back("601688.SH");
	securityIdList1.push_back("000014.SZ");
	securityIdList1.push_back("000016.SZ");
	securityIdList1.push_back("000001.SZ");
	securityIdList1.push_back("000002.SZ");
	securityIdList1.push_back("000004.SZ");
	securityIdList1.push_back("000005.SZ");
	securityIdList1.push_back("000006.SZ");
	for (size_t i = 0; i < securityIdList1.size(); i++)
	{
		std::unique_ptr<PlaybackRequest> request(new PlaybackRequest());
		//设置回放任务号，必须设置
		std::string task_id = get_task_id("");
		request->set_taskid(task_id);
		handle->task_id_mutex_.lock();
		handle->task_id_status_.insert(std::pair<std::string, int>(task_id, 0));
		handle->task_id_mutex_.unlock();
		//===================================================
		// 可配置的参数包括证券id和证券市场，
		//===================================================
		//填写证券id
		request->add_htscsecurityids(securityIdList1[i]);

		//设置回放数据类型，只能配置一个
		request->set_replaydatatype(MD_TICK);
		//设置复权类型，不设置默认不做复权处理
		request->set_exrightstype(NO_EXRIGHTS);
		//设置回放的开始结束时间	
		request->set_starttime("20200312090000");
		request->set_stoptime("20200312150000");
		//同时在线的回放任务不能超过五个
		while (handle->task_id_status_.size() >= 5)
		{
			msleep(1000);
		}
		//发送回放请求	
		int ret = client->RequestPlayback(&(*request));
		if (ret != 0)
		{
			error_print("%s", get_error_code_value(ret).c_str());
			return;
		}
	}
	//等待所有回放任务结束
	while (handle->task_id_status_.size() > 0)
	{
		msleep(1000);
	}
	return;
}

/**
* 盘中回放当天数据，使用需要申请权限
*/
void test_playbackToday() {
	if (client == NULL || handle == NULL) {
		error_print("create client failed!");
		return;
	}
	std::vector<std::string> idList;
	idList.push_back("601688.SH");
	idList.push_back("000001.SZ");

	int ret = client->RequestPlayback(idList, "20200313093000", "20200313103000", MD_KLINE_1MIN, NO_EXRIGHTS);
	if (ret != 0) {
		error_print("%s", get_error_code_value(ret).c_str());
		return;
	}
	//查询回放状态 EPlaybackTaskStatus
	/*
	INITIALIZING = 11            // 初始化中
	PREPARING = 12               // 准备中
	PREPARED = 13				 // 准备完成
	RUNNING = 14				 // 运行中
	APPENDING = 15               // 队列等待中
	CANCELED = 16                // 已取消
	COMPLETED = 17               // 已完成
	FAILED = 18                  // 任务失败
	*/
	handle->service_value_ = 0;
	while (1) {
		if (handle->service_value_ == CANCELED || handle->service_value_ == COMPLETED || handle->service_value_ == FAILED) {
			debug_print("receive playback end message, quit...");
			break;
		}
		else {
			msleep(1000);
		}
	}
	return;

}

int main(int argc, char** argv) {
	printf("\n=======================================================================\n");
	printf("usage: cmd user password ip port cert_folder export_folder test_type\n");
	printf("test_typ(0 test_subscribe_by_all_and_decrease \n");
	printf("test_typ(1 test_subscribe_by_source_type \n");
	printf("test_typ(2 test_subscribe_by_id \n");
	printf("test_typ(3 test_query \n");
	printf("test_typ(4 test_playback \n");
	printf("test_typ(5 test_playback_today \n");
	printf("=========================================================================\n\n");
	if (argc >= 8) {
		user = argv[1];
		password = argv[2];
		ip = argv[3];
		port = atoi(argv[4]);
		cert_folder = argv[5];
		export_folder = argv[6];
		test_type = atoi(argv[7]);
	}
	//环境初始化及常用配置
	open_file_log();	
	init_env();	
	test_init();
	//登录
	if (!test_login()) {
		return 0;
	}
	switch (test_type)
	{
	case 0: {
		test_subscribe_by_all_and_decrease();
		break;
	}
	case 1: {
		test_subscribe_by_source_type();
		break;
	}
	case 2: {
		test_subscribe_by_id();
		break;
	}
	case 3: {
		test_query_callback();
		break;
	}
	case 4: {
		test_playback();
		break;
	}
	case 5: {
		test_playbackToday();
		break;
	}
	default:
		break;
	}
	test_logout();
	fini_env();
}