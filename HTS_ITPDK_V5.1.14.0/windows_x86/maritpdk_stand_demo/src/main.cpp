#include "stdafx.h"


using namespace std;

const int PRODUCER_THREAD_NUM  = 50;

void producer_thread_1(ITPDK_CusReqInfo cusreqinfo)
{
	
	for (size_t i = 0; i < 10; i++)
	{
		char msg[1024] = { 0 };
		int64 nRet = MARITPDK_MarginEntrustEx(cusreqinfo, "SZ", "000001", 1, 200, 9.24, DDLX_XJWT, 2, "", 0, 0);


		if (nRet > 0)
			cout << "order success. wth:" << nRet << endl;
		else {
			MARITPDK_GetLastError(msg);
			cout << "order failed. msg:" << msg << " err code:" << nRet << endl;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1500));
	}
	
}

void producer_thread_2(ITPDK_CusReqInfo cusreqinfo)
{
	char msg[1024] = { 0 };
	strncpy(cusreqinfo.Password, "123456", sizeof(cusreqinfo.Password) - 1);
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	int64 bRet = MARITPDK_TradeLoginEx("A5_RS", cusreqinfo);
	if (bRet <= 0)
	{
		MARITPDK_GetLastError(msg);
		cout << "longin failed. msg:" << msg << " err code:" << bRet << endl;
	}
}

void producer_thread_3(ITPDK_CusReqInfo cusreqinfo)
{
	char msg[1024] = { 0 };

	for (size_t i = 0; i < 30000; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(5));

		int64 nRet = MARITPDK_MarginEntrust_ASync(cusreqinfo.AccountId, "SZ", "000001", JYLB_RZMR, 100, 9.20, 0, cusreqinfo.SecuAccount, 0, "", 0, 0);
		if (nRet > 0)
			cout << "MARITPDK_MarginEntrust_ASync success. record num:" << nRet << endl;
		else
		{
			MARITPDK_GetLastError(msg);
			cout << "MARITPDK_MarginEntrust_ASync failed! error:" << msg << "error no" << nRet << endl;
		}
	}
	
}
void producer_thread_4(ITPDK_CusReqInfo cusreqinfo)
{
	vector<ITPDK_XYDRWT> drwtRecord;
	for (size_t i = 0; i < 20000; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		char msg[1024] = { 0 };
		int64 nRet = MARITPDK_QueryOrders_MR_DRWT(cusreqinfo.AccountId, 0, 0, 200, 0, "", "", 0, "", 0, drwtRecord);
		if (nRet >= 0)
			cout << "query orders success. num:" << nRet << endl;
		else {
			MARITPDK_GetLastError(msg);
			cout << "query orders failed. msg:" << msg << endl;
		}
	}
}



void  producer_thread(int thread_id)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
    string sErrMsg = "aaaaaa:" + to_string(thread_id);
	MARITPDK_SetLastError(thread_id,sErrMsg.c_str(),nullptr);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
    char cMsg[1024] = {0};
    int nRetCode  = MARITPDK_GetLastError(cMsg);
    string sErr = "�߳�id :" +  to_string(thread_id) + ", ������룺" + to_string(nRetCode) +  "������Ϣ: " + string(cMsg);
    cout << sErr << endl;
    
}
int splitStringToVect(const string& srcStr, vector<string>& destVect, const string& strFlag)
{
	int pos = srcStr.find(strFlag, 0);
	int startPos = 0;
	int splitN = pos;
	string lineText(strFlag);

	while (pos > -1)
	{
		lineText = srcStr.substr(startPos, splitN);
		startPos = pos + 1;
		pos = srcStr.find(strFlag, pos + 1);
		splitN = pos - startPos;
		destVect.push_back(lineText);
	}

	lineText = srcStr.substr(startPos, srcStr.length() - startPos);
	destVect.push_back(lineText);

	return destVect.size();
}
int main(int argc, char* argv[])
{
    cout.setf(ios::fixed, ios::floatfield);


    int64 nRet = 0;
	int64 nCount = 0;
	string sItem="";
	string sTemp="";
	int nItem=100;
	int nWTH=0;
    char msg[1024];

    int nJYLB=0;
    int nTCLX=0;
    int nIndex = 0;
    int nSearchCount = 0;
	int nSortType = 0;
	int nFLag = 0;
    double dKQZJ =0.0;
	long lfssl;
	long lyysl;
	long lflag;
    string sDBZJZH;

	string error;
	string sKHH;
	string sPwd;
	string sShGdh;
	string sSzGdh;
	string sZJZH;
	string sYYB;
	string sWTFS;

	vector<ITPDK_XYSSCJ> sscjRecord;
	vector<ITPDK_XYZQGL> zqglRecord;
	vector<ITPDK_XYDRWT> drwtRecord;
	vector<ITPDK_XYZC> XYZCRecord;
	vector<ITPDK_XYFZ> XYFZRecord;
	vector<ITPDK_XYDRBD> XYDRBDRecord;
	vector<ITPDK_XYGDH> gdhRecord;
	vector<ITPDK_XYZJZH> fundRecord;
	vector<ITPDK_ZGZQ> zgzq;
	vector<ITPDK_RQZQ> rqzq;
	vector<ITPDK_XYPSQY> psqy;
	vector<ITPDK_XYZQDM> xyzqdm;
	vector<ITPDK_XYRQFZHZ> XYRQFZHZRecord;
	vector<ITPDK_XYDBHRSL> DBHRSLRecord;
	vector<ITPDK_ZXTCZQDB> ZQDBRecord;
	vector<ITPDK_ZQHMD> ZQHMDRecord;
	vector<ITPDK_XGSG> XGSGRecord;
	vector<ITPDK_FZBDMX> FZBDMXRecord;
	vector<ITPDK_RZCDMX> RZCDMXRecord;
	vector<ITPDK_RQCDMX> RQCDMXRecord;
	vector<ITPDK_CDBGSQJJYYCX> CDBGSQJJYYRecord;
	vector<ITPDK_CDBGSQCX> CDBGSQRecord;
	vector<ITPDK_XGZQ> XGZQRecord;
	vector<ITPDK_PHCX> PHCXRecord;
	vector<ITPDK_YZYWLS> YZYWLSRecord;
	vector<ITPDK_YHDM> YHDMRecord;
	vector<ITPDK_YHYE> YHYERecord;

	CConfig config;
	config.SetFilePath("config.ini");
	config.GetValue("CONFIG", "sKHH", sKHH, error);
	config.GetValue("CONFIG", "sPwd", sPwd, error);
	config.GetValue("CONFIG", "sShGdh", sShGdh, error);
	config.GetValue("CONFIG", "sSzGdh", sSzGdh, error);
	config.GetValue("CONFIG", "sZJZH", sZJZH, error);
	config.GetValue("CONFIG", "sYYB", sYYB, error);
	config.GetValue("CONFIG", "sWTFS", sWTFS, error);


	cout << "sKHH: " << sKHH << endl;
	cout << "sPwd: " << sPwd << endl;
	cout << "sShGdh: " << sShGdh << endl;
	cout << "sSzGdh: " << sSzGdh << endl;
	cout << "sZJZH: " << sZJZH << endl;
	cout << "sYYB: " << sYYB << endl;
	cout << "sWTFS: " << sWTFS << endl;

    string sJYS;
    string sGdh;
    string sZQDM;
    string sWTJG;
    string sTCBH;
    string sJYLB;
    string sTCLX;
	string sWTSL;
    string sZQSL;
    string sZQTS;
    string sZQCS1;
    string sZQCS2;
	string sKFSBDBH;
	string sCXKFSBDBH;
	string sTip;
	string sRQ;
	string sLSH;
	string sHYBH;
	string sLogin;
	string sLoginPwd;
	string sBZ;
	string sKSRQ;
	string sJSRQ;
	string sFLAG;
	string sJGDM;
	string sHYLX;
	string sYHZH;
	string sYHMM;
	string sQKMM;
	vector<string> sTipsOper;
    double dWTJG=0.0;
    long bRet = -1;
	bool bExFlag = false;

	cout << "Current Version: " << MARITPDK_GetVersion() << endl;

    MARITPDK_SetProfilePath("../cfg/");
	MARITPDK_Init(0);

	MARITPDK_SetMsgCallback(
        [](const char *pTime, const char *pMsg, int nType)
        {
			printf("\n");	
			cout<<"======ί����Ϣ�ص�======"<< endl;
            cout << pMsg << endl;
        }
    );
	MARITPDK_SetFuncCallback(
		[](const char* pTime, const char* pMsg, int nType)
		{
			printf("\n");
			cout << "======�첽ί�лص�======" << endl;
			cout << pMsg << endl;
		}
	);
    /*
    ITPDK_SetConnEventCallback(
        [](const char* pKhh, const char* pConnKey, int nEvent,void * pData)
        {
			printf("\n");	
			cout<<"======�����¼���Ϣ�ص�======"<< endl;
            cout << pKhh << " "<< pConnKey << " "<< nEvent<< " pData: "  << (long)pData << " time :"<< ITPDK_GetTickCount() <<   endl;
        }
    );
	*/
	MARITPDK_SetWTFS(sWTFS.c_str());
	ITPDK_CusReqInfo cusreqinfo;

	strncpy(cusreqinfo.AccountId, sKHH.c_str(), sizeof(cusreqinfo.AccountId) - 1);
	strncpy(cusreqinfo.FundAccount, sZJZH.c_str(), sizeof(cusreqinfo.FundAccount) - 1);
	strncpy(cusreqinfo.Password, sPwd.c_str(), sizeof(cusreqinfo.Password) - 1);
	strncpy(cusreqinfo.OrgCode, sYYB.c_str(), sizeof(cusreqinfo.OrgCode) - 1);
	strncpy(cusreqinfo.SecuAccount, sSzGdh.c_str(), sizeof(cusreqinfo.SecuAccount) - 1);
    cout << "=========== ��¼ ===========" << endl;
    printf("�������½��ʽ�� 1 �ͻ��ŵ�½ 2�ʽ��˻���½ 3 �ͻ��ŵ�½(�ṹ�����) 4 �ʽ��˺ŵ�½(�ṹ�����) \n");
    string sType;
		getline(cin,sType);
	long	nDLFS = atoi(sType.c_str());
    if( nDLFS == 2)
    {
       
        bRet = MARITPDK_TradeLoginByFundAcc("A5_RS",sZJZH.c_str(),sYYB.c_str(), sPwd.c_str(),sKHH);
         
    }
    else if(nDLFS == 1)
    {
        bRet = MARITPDK_TradeLogin("A5_RS", sKHH.c_str(), sPwd.c_str());
    }

	else if (nDLFS == 3)
	{
		bRet = MARITPDK_TradeLoginEx("A5_RS", cusreqinfo);
		bExFlag = true;
	}

	else if (nDLFS ==4)
	{
		//bRet = MARITPDK_TradeLoginByFundAccEx("A5_RS", cusreqinfo);
	}
	else
	{
		bRet = MARITPDK_TradeLogin("A5_RS", sKHH.c_str(), sPwd.c_str());
	}
    
   
    if (bRet <= 0) {
		MARITPDK_GetLastError(msg);
        cout << "Login failed. Msg:" << msg << endl;
        return 0;
    }
    else 
        cout << "Login success token :" << cusreqinfo.Token << endl;
    
	/*
    printf("���̲߳��� \n");
	
    std::thread arrRroducerThread[PRODUCER_THREAD_NUM];
    for (int i = 0; i < PRODUCER_THREAD_NUM; i++)
    {
        arrRroducerThread[i] = std::thread(producer_thread, i);
    }
    for (int i = 0; i < PRODUCER_THREAD_NUM; i++)
    {
        arrRroducerThread[i].join();
    }
    
	
	std::thread arrRroducerThread[2];
	arrRroducerThread[0] = std::thread(producer_thread_3,  cusreqinfo);
	arrRroducerThread[1] = std::thread(producer_thread_4, cusreqinfo);
	for (int i = 0; i < 2; i++)
	{
		arrRroducerThread[i].join();
	}
	*/
	 /*
	���ý���

	lpKhh		[in]		�ͻ���
	lpJys		[in]		������
	lpZqdm		[in]		֤ȯ����
	nJylb		[in]		�������(JYLB_BUY��JYLB_SALE)
	lWtsl		[in]		ί������
	lfWtjg		[in]		ί�м۸�(��������Ϊ�м�ʱ���ò�������Ч)
	lDdlx		[in]		��������(DDLX_XJWT,DDLX_SJWT)
	lpGdh		[in]		�ɶ���
	nTCLX		[in]		ͷ������  1��ͨͷ�� 2ר��ͷ��
	lpFzlshfw	[in]		ָ��������ծ��ˮ�ŷ�Χ
	nChbz		[in]		������־: 0-���� 1-��ͨ 2-ר��
	nChlx		[in]		��������: 0-���˽᷽ʽ) 1-ֻ����Ϣ
	return				�ɹ�����ί�кţ�ʧ�ܷ���<0
	
	case 1:    //��������
	case 2:    //��������
	case 62:   //��ȯ����
	case 63:   //��ȯ��ȯ
	case 61:   //��������
	case 64:   //��ȯ����
	case 65:   //�������ύ
	case 66:   //�����ﷵ��
	case 70:   //��ȯ��ת
*/
	sTip = "  ��������ί�У�1;\n  ��������������2;\n  �����������룺3;\n  ������ȯ������4;\n  ������ȯ���5;\n";
	sTip += "  ������ȯ���6;\n  ����ί�г�����8;\n  ��ѯ����ί�У�9;\n  ��ѯ�ֱʳɽ���10;\n";
	sTip += "  ��ѯ֤ȯ�ֲ֣�11;\n  ���ÿ�ί��������12;\n  ��ѯ�����ʲ���13;\n  ��ѯ���ø�ծ��14;\n";
	sTip += "  ��ѯ�ɶ��ţ�16;\n  ��ѯ�ʽ��˺ţ�17;\n  ��ѯ�ʸ�֤ȯ��18;\n  ��ѯ�ͻ�����ȯ��19;\n  ��ѯ�ͻ�����Ȩ�棺20;\n";
	sTip += "  �¹��깺��21;\n  ��ѯ֤ȯ���룺22;\n  ��ѯ����ҵ����Ϲ�������23;\n  �ͻ��ʽ���룺24;\n  �ͻ��ʽ������25;\n";
	sTip += "  �ͻ����н����ʽ��ѯ��26;\n  �ͻ��ŵ�½��27;\n  �ʽ��˻���½��28;\n  ��ѯ��ȯ��ծ���ܣ�29;\n  �̺󶨼����룺30;\n";
	sTip += "  �̺󶨼�������31;\n  ���������첽��32;\n    ����ҵ��33;\n   �첽������34;\n   ��ѯA�ɿɵ�������������35;\n";
	sTip += "  ר��ͷ��֤ȯ������36;\n  ר��ͷ���ʽ������37;\n  ��ѯ֤ȯ��������38;\n  ��ѯ�¹��깺��39;\n  ��ѯ��ծ�䶯��ϸ��40;\n";
	sTip += "  ���ʲֵ���ϸ��ѯ(���)��41;\n  ��ȯ�ֵ���ϸ��ѯ(���)��42;\n  ������ȯչ��(���)��43;\n  �ֵ��������ܾ�ԭ���ѯ(���)��44;\n  �ֵ���������ѯ(���)��45;\n";
	sTip += "  �¹���ǩ��ѯ(���)��46;\n  �¹���Ų�ѯ(���)��47;\n  ��֤ҵ��ת����ˮ��ѯ(���)��48;\n  ��֤ת��ҵ��(���)��49;\n  ��ѯ�ͻ����д���(���)��50;\n";
	sTip += "  ��ѯ�������(���)��51;\n  �˳���0;\n";

	splitStringToVect(sTip, sTipsOper, "\n");
	while (nItem)
	{
		cout << "============��������Ҫִ�е�ί��============" << endl;
		
		for (size_t i = 0; i < sTipsOper.size(); i++)
		{
			cout << sTipsOper[i] << endl;
		}

		getline(cin,sItem);
		nItem = atoi(sItem.c_str());
		switch(nItem)
		{
		case 1:
		
			cout << "=========== ��������ί��===========" << endl;
            printf("�����뽻���� ֤ȯ���� ί�м۸� ������� ί������\n");
            getline(cin,sJYS);
            if(sJYS == "SH")
            {
                sGdh = sShGdh;
            }
            else
            {
                sGdh = sSzGdh;
            }
            getline(cin,sZQDM);
            getline(cin,sWTJG);
			getline(cin, sJYLB);
            dWTJG = atof(sWTJG.c_str());
			getline(cin, sWTSL);
            
			nRet = MARITPDK_MarginEntrust(sKHH.c_str(),sJYS.c_str(),sZQDM.c_str(), atoi(sJYLB.c_str()), atoi(sWTSL.c_str()),dWTJG,DDLX_XJWT,sGdh.c_str(),2,"",0,0);
			  

			if (nRet > 0)
				cout << "order success. wth:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "order failed. msg:" << msg   << " err code:"<< nRet  << endl;
			}
			break;
		case 32:
			cout << "=========== �����첽��������==========" << endl;
			printf("�����뽻���� ֤ȯ���� ί�м۸� ͷ������\n");
			getline(cin, sJYS);
			if (sJYS == "SH")
			{
				sGdh = sShGdh;
			}
			else
			{
				sGdh = sSzGdh;
			}
			getline(cin, sZQDM);
			getline(cin, sWTJG);
			getline(cin, sTCLX);
			dWTJG = atof(sWTJG.c_str());
			nRet = MARITPDK_MarginEntrust_ASync(sKHH.c_str(), sJYS.c_str(), sZQDM.c_str(), JYLB_RZMR, 100, dWTJG, 0, sGdh.c_str(), atol(sTCLX.c_str()), "", 0, 0);
			if (nRet > 0)
				cout << "MARITPDK_MarginEntrust_ASync success. record num:" << nRet << endl;
			else
			{
				MARITPDK_GetLastError(msg);
				cout << "MARITPDK_MarginEntrust_ASync failed! error:" << msg  << "error no" << nRet << endl;
			}
			break;
		case 33:
			cout << "=========== ����ҵ�� ==========" << endl;
			printf("�����뽻���� ֤ȯ���� ί�м۸� ������� ͷ������ ί������ �����̱������\n");
			getline(cin, sJYS);
			if (sJYS == "SH")
			{
				sGdh = sShGdh;
			}
			else
			{
				sGdh = sSzGdh;
			}
			getline(cin, sZQDM);
			getline(cin, sWTJG);
			getline(cin, sJYLB);
			getline(cin, sTCLX);
			getline(cin, sWTSL);
			getline(cin, sKFSBDBH);
			dWTJG = atof(sWTJG.c_str());
			nRet = MARITPDK_MarginEntrust_ASync(sKHH.c_str(), sJYS.c_str(), sZQDM.c_str(), atol(sJYLB.c_str()), atol(sWTSL.c_str()), dWTJG, 0, sGdh.c_str(), atol(sTCLX.c_str()), "", 0, 0 , atoll(sKFSBDBH.c_str()));
			if (nRet > 0)
				cout << "MARITPDK_MarginEntrust_ASync success. record num:" << nRet << endl;
			else
			{
				MARITPDK_GetLastError(msg);
				cout << "MARITPDK_MarginEntrust_ASync failed! error:" << msg << "error no" << nRet << endl;
			}
			break;
		case 34:
			cout << "=========== �첽�����̴��볷�� ==========" << endl;
			printf("�����뽻���� ������� �����̱������ ���������̱������\n");
			getline(cin, sJYS);
			if (sJYS == "SH")
			{
				sGdh = sShGdh;
			}
			else
			{
				sGdh = sSzGdh;
			}

			getline(cin, sJYLB);
			getline(cin, sKFSBDBH);
			getline(cin, sCXKFSBDBH);


			nRet = MARITPDK_MarginOrderKFSDMWithdraw_ASync(sKHH.c_str(), sGdh.c_str(), atoll(sKFSBDBH.c_str()), atol(sJYLB.c_str()), atoll(sCXKFSBDBH.c_str()));
			if (nRet > 0)
				cout << "MARITPDK_MarginOrderKFSDMWithdraw_ASync success. record num:" << nRet << endl;
			else
			{
				MARITPDK_GetLastError(msg);
				cout << "MARITPDK_MarginOrderKFSDMWithdraw_ASync failed! error:" << msg << "error no" << nRet << endl;
			}
			break;
		case 2:
			cout << "=========== ������������===========" << endl;
            printf("�����뽻���� ֤ȯ���� ί�м۸�\n");
            getline(cin,sJYS);
            if(sJYS == "SH")
            {
                sGdh = sShGdh;
            }
            else
            {
                sGdh = sSzGdh;
            }
            getline(cin,sZQDM);
            getline(cin,sWTJG);
            dWTJG = atof(sWTJG.c_str());
            nRet = MARITPDK_MarginEntrust(sKHH.c_str(),sJYS.c_str(),sZQDM.c_str(),2,200,dWTJG,DDLX_XJWT,sGdh.c_str(),2,"",0,0);

			  

			if (nRet > 0)
				cout << "order success. wth:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "order failed. msg:" << msg << endl;
			}
			break;

		case 3:
			cout << "=========== ������������===========" << endl;
            
            printf("�����뽻���� ֤ȯ���� ί�м۸�\n");
            getline(cin,sJYS);
            if(sJYS == "SH")
            {
                sGdh = sShGdh;
            }
            else
            {
                sGdh = sSzGdh;
            }
            getline(cin,sZQDM);
            getline(cin,sWTJG);
            dWTJG = atof(sWTJG.c_str());
            nRet = MARITPDK_MarginEntrust(sKHH.c_str(),sJYS.c_str(),sZQDM.c_str(),61,200,dWTJG,DDLX_XJWT,sGdh.c_str(),2,"",0,0);

			  
			if (nRet > 0)
				cout << "order success. wth:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);

				cout << "order failed. msg:" << msg << endl;
			}
			break;

		case 4:
			cout << "=========== ������ȯ����===========" << endl;
            printf("�����뽻���� ֤ȯ���� ί�м۸�\n");
            getline(cin,sJYS);
            if(sJYS == "SH")
            {
                sGdh = sShGdh;
            }
            else
            {
                sGdh = sSzGdh;
            }
            getline(cin,sZQDM);
            getline(cin,sWTJG);
            dWTJG = atof(sWTJG.c_str());
            nRet = MARITPDK_MarginEntrust(sKHH.c_str(),sJYS.c_str(),sZQDM.c_str(),64,200,dWTJG,DDLX_XJWT,sGdh.c_str(),2,"",0,0);
			  

			if (nRet > 0)
				cout << "order success. wth:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "order failed. msg:" << msg << endl;
			}
			break;

		case 5:
			cout << "=========== ������ȯ����===========" << endl;
            printf("�����뽻���� ֤ȯ���� ί�м۸� ͷ������(1 ��ͨ 2ר��)\n");
            getline(cin,sJYS);
            if(sJYS == "SH")
            {
                sGdh = sShGdh;
            }
            else
            {
                sGdh = sSzGdh;
            }
            getline(cin,sZQDM);
            getline(cin,sWTJG);
            dWTJG = atof(sWTJG.c_str());
			getline(cin, sTCLX);
			nTCLX = atoi(sTCLX.c_str());
            nRet = MARITPDK_MarginEntrust(sKHH.c_str(),sJYS.c_str(),sZQDM.c_str(),62,200,dWTJG,DDLX_XJWT,sGdh.c_str(), nTCLX,"",0,0);
            
			  

			if (nRet > 0)
				cout << "order success. wth:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "order failed. msg:" << msg << endl;
			}
			break;

		case 6:	
			cout << "=========== ������ȯ��ȯ===========" << endl;
            printf("�����뽻���� ֤ȯ���� ί�м۸�\n");
            getline(cin,sJYS);
            if(sJYS == "SH")
            {
                sGdh = sShGdh;
            }
            else
            {
                sGdh = sSzGdh;
            }
            getline(cin,sZQDM);
            getline(cin,sWTJG);
            dWTJG = atof(sWTJG.c_str());
            nRet = MARITPDK_MarginEntrust(sKHH.c_str(),sJYS.c_str(),sZQDM.c_str(),63,200,dWTJG,DDLX_XJWT,sGdh.c_str(),2,"",0,0);
			  

			if (nRet > 0)
				cout << "order success. wth:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "order failed. msg:" << msg << endl;
			}
			break;
		

		case 8:
			cout << "=========== ����ί�г���===========" << endl;
			printf("��������Ҫ������ί�кţ�  ");
			getline(cin,sTemp);
			nWTH=atoi(sTemp.c_str());
            printf("�����뽻���� �������\n");
            getline(cin,sJYS);
            getline(cin,sTemp);
			nJYLB=atoi(sTemp.c_str());
            if(sJYS == "SH")
            {
                sGdh = sShGdh;
            }
            else
            {
                sGdh = sSzGdh;
            }
            
			if (bExFlag)
			{

				ITPDK_CusReqInfo cusreqinfo_temp;

				strncpy(cusreqinfo_temp.AccountId, sKHH.c_str(), sizeof(cusreqinfo_temp.AccountId) - 1);
	
				strncpy(cusreqinfo_temp.SecuAccount, sGdh.c_str(), sizeof(cusreqinfo_temp.SecuAccount) - 1);
				cusreqinfo_temp.Token = cusreqinfo.Token;
				nRet = MARITPDK_MarginOrderWithdrawEx(cusreqinfo_temp, nWTH, nJYLB);

			}
			else
			{

				nRet = MARITPDK_MarginOrderWithdraw(sKHH.c_str(),sGdh.c_str(),nWTH,nJYLB);
			}
			if (nRet > 0)
				cout << "order success. wth:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				
				cout << "order failed. msg:" << msg   << "error code " << nRet << endl;
			}
			break;
		case 9:
			cout << "=========== ��ѯ����ί�� ===========" << endl;
            printf("�����뽻�����  \n");
			getline(cin,sTemp);
			nJYLB=atoi(sTemp.c_str());
            printf("��������ʼ������browindex��  \n");
			getline(cin,sTemp);
			nIndex=atoi(sTemp.c_str());
            printf("�������ѯ������  \n");
			getline(cin,sTemp);
			nSearchCount=atoi(sTemp.c_str());
			printf("�������ѯ�������� 0���� 1 ����  \n");
			getline(cin, sTemp);
			nSortType = atoi(sTemp.c_str());
			printf("�������Ƿ��ѯ�ɳ�ί�б�־ 0���� 1 �ɳ���  \n");
			getline(cin, sTemp);
			nFLag = atoi(sTemp.c_str());
			
			nRet = MARITPDK_QueryOrders_MR_DRWT( sKHH.c_str(), nFLag, nSortType, nSearchCount,nIndex, "", "",nJYLB,"", 0 , drwtRecord);
			if (nRet >= 0)
				cout << "query orders success. num:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "query orders failed. msg:" << msg << endl;
			}
			for (int index = 0; index < (int)drwtRecord.size(); ++index) {
				 
				printf("WTH:%d -- CXWTH:%d SBWTH:%s;StockCode:%s;JYS:%s;CXBZ:%s;WTJG:%.2f;CurrentQty:%d;JGSM:%s ; BrowIndex:%d ;; kfsdmbh:%s;EntrustTime:%s;ReportTime:%s;\n",
					drwtRecord[index].OrderId,drwtRecord[index].CancelOrderId, drwtRecord[index].SBWTH, drwtRecord[index].StockCode, drwtRecord[index].Market, drwtRecord[index].WithdrawFlag,
					drwtRecord[index].OrderPrice, drwtRecord[index].OrderQty, drwtRecord[index].ResultInfo , drwtRecord[index].BrowIndex ,  drwtRecord[index].KfsOrderNum, drwtRecord[index].EntrustTime, drwtRecord[index].ReportTime);
				
			}

			break;	
		
		case 10:
			cout << "=========== ��ѯʵʱ�ɽ� ===========" << endl;
            printf("��������ʼ������browindex��  \n");
			getline(cin,sTemp);
			nIndex=atoi(sTemp.c_str());
            printf("�������ѯ������  \n");
			getline(cin,sTemp);
			nSearchCount=atoi(sTemp.c_str());
			printf("�������ѯ�������� 0���� 1 ����  \n");
			getline(cin, sTemp);
			nSortType = atoi(sTemp.c_str());
			
			//ITPDK_QueryMatchs_MR_SSCJ(const char *tablename, const char *khh, int nType, int nSortType, int nRowcount, long nBrowindex, const char *jys, const char *zqdm,int nJylb, long lWth);
			//ITPDK_QueryMatchs_MR_SSCJ(const char *tablename, const char *khh, int nType, int nSortType, int nRowcount, long nBrowindex, const char *jys, const char *zqdm,int nJylb, long lWth);

			nRet = MARITPDK_QueryMatchs_MR_SSCJ( sKHH.c_str(), 0, nSortType, nSearchCount, nIndex, "", "", 1,0, sscjRecord);
			if (nRet >= 0)
				cout << "query sscj success. num:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "query sscj failed. msg:" << msg << endl;
			}
			for (int index = 0; index < (int)sscjRecord.size(); ++index) {

					printf("HBXH:%I64d ;StockName:%s; WTH:%I64d; StockCode:%s; JYS:%s; CJSL:%I64d; CJBH:%s; BrowIndex:%I64d\n",
						sscjRecord[index].ReportSerialNo,sscjRecord[index].StockName, sscjRecord[index].OrderId, sscjRecord[index].StockCode, sscjRecord[index].Market, sscjRecord[index].MatchQty,sscjRecord[index].MatchSerialNo, sscjRecord[index].BrowIndex);

			}
			break;

		case 11:
			cout << "=========== ��ѯ�ֲ� ===========" << endl;
            printf("��������ʼ������browindex��  \n");
			getline(cin,sTemp);
			nIndex=atoi(sTemp.c_str());
            printf("�������ѯ������  \n");
			getline(cin,sTemp);
			nSearchCount=atoi(sTemp.c_str());
			//long ITPDK_QueryPosition_MR_ZQGL(const char *tablename, const char *khh, int nFlag, int nSortType, int nRowcount, long nBrowindex,const char * gdh, const char *jys, const char *zqdm);

			nRet = MARITPDK_QueryPosition_MR_ZQGL( sKHH.c_str(),0,SORT_TYPE_DESC,nSearchCount,nIndex,"","","", zqglRecord);
			cout << "�ֲּ�¼�� " << nRet << endl;
			for (int index = 0; index < nRet; ++index) {

				printf("StockName:%s; AccountId:%s; StockCode:%s; CurrentQty:%ld; OrderFrozenQty:%ld; BrowIndex:%ld\n",
					zqglRecord[index].StockName, zqglRecord[index].AccountId, zqglRecord[index].StockCode, zqglRecord[index].CurrentQty, zqglRecord[index].OrderFrozenQty, zqglRecord[index].BrowIndex);
			}
			break;

		case 12:
			cout << "=========== ���ÿ�ί�м������� ===========" << endl;
            printf("�����뽻���� ֤ȯ���� ί�м۸� �������  ͷ������\n");
            getline(cin,sJYS);
            if(sJYS == "SH")
            {
                sGdh = sShGdh;
            }
            else
            {
                sGdh = sSzGdh;
            }
            getline(cin,sZQDM);
            getline(cin,sWTJG);
            dWTJG = atof(sWTJG.c_str());
            getline(cin,sJYLB);
            nJYLB = atoi(sJYLB.c_str());
            getline(cin,sTCLX);
            nTCLX = atoi(sTCLX.c_str());
			//ITPDK_MarginTradableQty(const char *lpKhh,const char *lpJys,const char *lpZqdm,int nJylb,double lfWtjg,long lDdlx,const char *lpGdh,const char * lpDfGdh ,int nTCLX)
			// ����������̺󶨼۵Ļ�  nTCLX ���� �ض���־
            nRet = MARITPDK_MarginTradableQty(sKHH.c_str(), sJYS.c_str(),sZQDM.c_str(),nJYLB,dWTJG,0,sGdh.c_str(),"",nTCLX, nTCLX,"");
		
			if (nRet >= 0)
				cout << "���ÿ�ί�м������� " << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "query orders failed. msg:" << msg << endl;
			}
			break;

		case 13:
			cout << "=========== ��ѯ�����ʲ� ===========" << endl;
			//long ITPDK_QueryTradeData_MR_XYZC(const char *tablename, const char *khh, int nFlag);

			nRet = MARITPDK_QueryTradeData_MR_XYZC( sKHH.c_str(),"","",1, XYZCRecord);
			if (nRet >= 0)
				cout << "query orders success. num:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "query orders failed. msg:" << msg << endl;
			}
            //double dZFZ;        //�ܸ�ծ

			for (int index = 0; index < nRet; ++index) {

			printf("KHH:%s   dKYBZJ:%.2f -- dZHYE:%f;dKYZJ:%f;dQSZJ:%f; dZQSZ_DBZS:%.2f;dZQSZ_DBZS_BD:%.2f; dZYBZJ_RZ:%.2f;dZYBZJ_RQ:%.2f;dRQSYZJ:%.2f;dRZLX:%f;dRQLX:%f; dQTFY:%f; dRZYK:%f;dRQYK:%f; dYJBL1:%f;dYJBL2:%f; dRZED:%f;dRQED:%f;dRZZY:%f;dRQZY:%f;dRZFZ:%f;dRQFZ:%f;dZQSZ:%f;dKQZJ:%f; dZFZ:%f;dRQMCJE:%f; dRQMCQSJE:%f\n",
				XYZCRecord[index].AccountId, XYZCRecord[index].dKYBZJ,
				XYZCRecord[index].dZHYE, XYZCRecord[index].dKYZJ, XYZCRecord[index].dQSZJ,
				XYZCRecord[index].dZQSZ_DBZS, XYZCRecord[index].dZQSZ_DBZS_BD,
				XYZCRecord[index].dZYBZJ_RZ, XYZCRecord[index].dZYBZJ_RQ,
				XYZCRecord[index].dRQSYZJ,
				XYZCRecord[index].dRZLX, XYZCRecord[index].dRQLX, XYZCRecord[index].dQTFY,
				XYZCRecord[index].dRZYK, XYZCRecord[index].dRQYK,
				//XYZCRecord[index].dZQSZ_DBHC,
				XYZCRecord[index].dYJBL1, XYZCRecord[index].dYJBL2,
				XYZCRecord[index].dRZED, XYZCRecord[index].dRQED, XYZCRecord[index].dRZZY, XYZCRecord[index].dRQZY,
				XYZCRecord[index].dRZFZ, XYZCRecord[index].dRQFZ, XYZCRecord[index].dZQSZ, XYZCRecord[index].dKQZJ, XYZCRecord[index].dZFZ,
				XYZCRecord[index].dRQMCJE, XYZCRecord[index].dRQMCQSJE);
			

			printf("KHH:%s   dKYBZJ:%.2f \n",
				XYZCRecord[index].AccountId, 
				XYZCRecord[index].dZHYE + XYZCRecord[index].dQSZJ+
				XYZCRecord[index].dZQSZ_DBZS- XYZCRecord[index].dZQSZ_DBZS_BD-
				XYZCRecord[index].dZYBZJ_RZ- XYZCRecord[index].dZYBZJ_RQ-
				XYZCRecord[index].dRQSYZJ-
				XYZCRecord[index].dRZLX- XYZCRecord[index].dRQLX- XYZCRecord[index].dQTFY+
				XYZCRecord[index].dRZYK + XYZCRecord[index].dRQYK
				);
			}

			break;	

		case 14:
			cout << "=========== ��ѯ���ø�ծ ===========" << endl;
			//long ITPDK_QueryDebts(const char *tablename, const char *lpKhh, const char * lpJys,const char * lpGdh,const char * lpZqdm ,const char * lpHybh, int nJylb,int nRowcount, const char * nBrowindex, int nKsrq,int nJsrq,int lWth);
			printf("�������ѯ������  \n");
			getline(cin,sTemp);
			nSearchCount = atoi(sTemp.c_str());
			printf("�������˽����� �Ƿ��˽�(0 ���к�Լ,1 ���˽� 2δ�˽�)��  \n");
			getline(cin, sTemp);
			nSortType = atoi(sTemp.c_str());
			printf("������ͷ������(0 �������� 1 ��ͨ 2 ר��)��  \n");
			getline(cin, sTemp);
			nFLag =atoi(sTemp.c_str());

			printf("��������ʼ������browindex��  \n");
			getline(cin, sTemp);
			printf("������֤ȯ���룺  \n");
			getline(cin, sZQDM);


            nRet = MARITPDK_QueryDebts( sKHH.c_str(),"","", sZQDM.c_str(),"",0,nSearchCount, sTemp.c_str(),0,0,0, nSortType,nFLag, XYFZRecord);
			if (nRet >= 0)
				cout << "order success. wth:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				
				cout << "order failed. msg:" << msg << endl;
			}
			cout << "��ѯ���ø�ծ " << nRet << endl;
			for (int index = 0; index < nRet; ++index) {

					printf("m_nZT :%d ,m_szBrowIndex:%s , KHH:%s --WTH:%d;HYDM:%s;HTBH:%s;JYS:%s;ZQDM:%s;FSSJ:%s\n",
						XYFZRecord[index].m_nZT,XYFZRecord[index].m_szBrowIndex,XYFZRecord[index].AccountId, XYFZRecord[index].m_nWTH,XYFZRecord[index].m_szHYBH, XYFZRecord[index].m_szHTBH,
						XYFZRecord[index].m_szJYS, XYFZRecord[index].m_szZQDM, XYFZRecord[index].m_szFSSJ);

			}
			break;

		case 16:
			cout << "=========== ��ѯ�ɶ�����Ϣ ===========" << endl;

			nRet = MARITPDK_QueryAccInfo( sKHH.c_str(), gdhRecord);

			if (nRet >= 0)
				cout << "�ɶ�����Ϣ��ѯ�ɹ�" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "�ɶ�����Ϣ��ѯʧ��:" << msg << endl;
			}
			for (int index = 0; index < nRet; ++index)
			{

			printf("AccountId:%s; SecuAccount:%s; Market:%s; FundAccount:%s; OrgCode:%s; TradeAccess:%s; HolderType:%I64d;\n",
				gdhRecord[index].AccountId, gdhRecord[index].SecuAccount, gdhRecord[index].Market, gdhRecord[index].FundAccount, gdhRecord[index].OrgCode,
                    gdhRecord[index].TradeAccess, gdhRecord[index].HolderType);

				if (index >5) break;
			}

			break;

		case 17:
			cout << "=========== ��ѯ�ʽ���Ϣ ===========" << endl;

			nRet = MARITPDK_QueryFundInfo( sKHH.c_str(), fundRecord);
			if (nRet >= 0)
				cout << "��ѯ�ʽ���Ϣ��ѯ�ɹ�" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "��ѯ�ʽ���Ϣ��ѯʧ��:" << msg << endl;
			}
			for (int index = 0; index < nRet; ++index)
			{
	
					printf("AccountId:%s -- FundAcc:%s; MoneyType:%s; FundAvl:%f;FrozenBalance:%f  ;SettleBalance:%lf; ContractPosiValue:%lf;LastPositionValue:%lf;\n",
						fundRecord[index].AccountId, fundRecord[index].FundAccount, fundRecord[index].MoneyType, fundRecord[index].FundAvl, fundRecord[index].FrozenBalance,fundRecord[index].SettleBalance,
                        fundRecord[index].ContractPosiValue,fundRecord[index].LastPositionValue);
				
			}

			break;
        case 18:
            
			cout << "=========== ��ѯ�ʸ�֤ȯ ===========" << endl;
			printf("�������ѯ������  \n");
			getline(cin, sTemp);
			nSearchCount = atoi(sTemp.c_str());
			printf("�������ѯ������  \n");
			getline(cin, sTemp);
			nCount = nSearchCount > 200 ? 200 : nSearchCount;

			nRet = MARITPDK_QueryTradeData_MR_ZGZQ("", "", nCount, atol(sTemp.c_str()), zgzq);

			for (int index = 0; index < nRet; ++index)
			{
				printf("BrowIndex:%I64d; ZQDM:%s; ZQMC:%s; ZSL:%f; RZBL:%f; RQBL:%f; JYZT:%d; ZQSX:%d; TYPE:%d; DBZT:%d;\n",
					zgzq[index].BrowIndex, zgzq[index].StockCode, zgzq[index].StockName, zgzq[index].ConversionRate, zgzq[index].MarginBailRate, zgzq[index].ShortBailRate,
					zgzq[index].TradeStatus, zgzq[index].StockProperty, zgzq[index].Type, zgzq[index].CollateralStatus);
			}

			break;
        case 19:
            
			cout << "=========== ��ѯ�ͻ�����ȯ��Ϣ ===========" << endl;
			printf("�������ѯ������  \n");
			getline(cin, sTemp);
			nSearchCount = atoi(sTemp.c_str());
			printf("�������ѯ������  \n");
			getline(cin, sTemp);
			printf("�������ѯͷ�����ͣ�  \n");
			getline(cin, sTCLX);
			nTCLX = atoi(sTCLX.c_str());
			printf("������֤ȯ���룺  \n");
			getline(cin, sZQDM);

			nRet = MARITPDK_QueryTradeData_MR_KRQXX( sKHH.c_str(), "", sZQDM.c_str(), nTCLX, nSearchCount,atol(sTemp.c_str()), rqzq);
			if (nRet >= 0)
            {
                cout << "��ѯ�ͻ�����ȯ��Ϣ" << nRet << endl;
            }
				
			else {
				MARITPDK_GetLastError(msg);
				cout << "�ͻ�����ȯ��Ϣ��ѯʧ��:" << msg << endl;
			}
			for (int index = 0; index < nRet; ++index)
			{
 
				printf("Browindex:%I64d; TCXZ:%d; AccountId:%s; Market:%s; SecuAccount:%s; StockCode:%s; TotalQty:%I64d; SurplusQty:%I64d;\n",
					rqzq[index].BrowIndex, rqzq[index].nTCXZ,rqzq[index].AccountId,rqzq[index].sJYS,rqzq[index].sZQDM,rqzq[index].sZQMC,rqzq[index].nZQSL,rqzq[index].nDJSL);
			}

			break;
        case 20:
            
			cout << "=========== ��ѯ�ͻ�����Ȩ�� ===========" << endl;

			nRet = MARITPDK_QueryTradeData_MR_PSQY( sKHH.c_str(), psqy);
			if (nRet >= 0)
            {
                cout << "��ѯ�ͻ�����Ȩ��" << nRet << endl;
            }
				
			else {
				MARITPDK_GetLastError(msg);
				cout << "�ͻ�����Ȩ���ѯʧ��:" << msg << endl;
			}
			for (int index = 0; index < nRet; ++index)
			{
					printf("AccountId:%s; Market:%s; SecuAccount:%s; StarQty:%d; EquityQty:%d; SettleMentDate:%d;\n",
						psqy[index].AccountId,psqy[index].Market,psqy[index].SecuAccount,psqy[index].StarQty,psqy[index].EquityQty,psqy[index].SettleMentDate);
                        
			}
			
			break;
            
        case 21:
		
			cout << "=========== �����¹��깺===========" << endl;

			printf("�����뽻���� ֤ȯ���� ί�м۸� ί������\n");
			getline(cin, sJYS);
			if (sJYS == "SH")
			{
				sGdh = sShGdh;
			}
			else
			{
				sGdh = sSzGdh;
			}
			getline(cin, sZQDM);
			getline(cin, sWTJG);
			getline(cin, sWTSL);
			dWTJG = atof(sWTJG.c_str());

			nRet = MARITPDK_MarginEntrust(sKHH.c_str(), sJYS.c_str(), sZQDM.c_str(), 14, atol(sWTSL.c_str()), dWTJG, DDLX_XJWT, sShGdh.c_str(), 2, "", 0, 0);
			  

			if (nRet > 0)
				cout << "order success. wth:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "order failed. msg:" << msg << endl;
			}
			break;
            
        case 22:
            
			cout << "=========== ��ѯ֤ȯ���� ===========" << endl;
			printf("�������ѯ������  \n");
			getline(cin, sTemp);
			nRet = MARITPDK_QueryTradeData_MR_ZQDM( "", "",5, atol(sTemp.c_str()), xyzqdm);
			if (nRet >= 0)
            {
                cout << "��ѯ֤ȯ����ɹ�" << nRet << endl;
            }
				
			else {
				MARITPDK_GetLastError(msg);
				cout << "��ѯ֤ȯ����ʧ��:" << msg << endl;
			}
			for (int index = 0; index < nRet; ++index)
			{

					printf("BrowIndex:%ld; MoneyType:%s; StockCode:%s; StockName:%s; StockType:%s; PriceTick:%f; TradeUnit:%f; MaxMarketTradeAmt:%ld; MinMarketTradeAmt:%ld; MaxTradeAmt:%ld; MinTradeAmt:%ld; LastClosePrice:%f; HighLimitPrice:%f; LowLimitPrice:%f; NetPriceFlag:%ld; InterestPrice:%f;\n",
					xyzqdm[index].BrowIndex,xyzqdm[index].MoneyType,xyzqdm[index].StockCode,xyzqdm[index].StockName,xyzqdm[index].StockType,xyzqdm[index].PriceTick,xyzqdm[index].TradeUnit, xyzqdm[index].MaxMarketTradeAmt, xyzqdm[index].MinMarketTradeAmt,
                        xyzqdm[index].MaxTradeAmt,xyzqdm[index].MinTradeAmt,xyzqdm[index].LastClosePrice,xyzqdm[index].HighLimitPrice,xyzqdm[index].LowLimitPrice,
                        xyzqdm[index].NetPriceFlag,xyzqdm[index].InterestPrice);
                        
			
			}

			break;
		
        case 23:
            
			cout << "=========== ��ѯ����ҵ����Ϲ�������23 ===========" << endl;
			printf("�����뽻���� ֤ȯ���� ί�м۸� �������  \n");
			getline(cin, sJYS);
			if (sJYS == "SH")
			{
				sGdh = sShGdh;
			}
			else
			{
				sGdh = sSzGdh;
			}
			getline(cin, sZQDM);
			getline(cin, sWTJG);
			dWTJG = atof(sWTJG.c_str());
			getline(cin, sJYLB);
			nJYLB = atoi(sJYLB.c_str());
			
			
			nRet = MARITPDK_FXYWTradableQty(sKHH.c_str(), sJYS.c_str(), sZQDM.c_str(), nJYLB, dWTJG, 0, sGdh.c_str());

			if (nRet >= 0)
				cout << "��ѯ����ҵ����Ϲ����� " << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "query amount failed. msg:" << msg << endl;
			}
			break;
		
        case 24:
            
			cout << "=========== �ͻ��ʽ���룺24 ===========" << endl;
            printf("�����뽻�����룺  \n");
            getline(cin,sType);
            printf("�������ʽ��˻���  \n");
            getline(cin,sDBZJZH);
			printf("����������  \n");
			getline(cin, sWTJG);
			dWTJG = atof(sWTJG.c_str());

            bRet = false;
            if(sDBZJZH.empty())
            {
				bRet = MARITPDK_FundTransIn(sKHH.c_str(), sType.c_str(), dWTJG);
            }
            else
            {
				bRet = MARITPDK_FundTransIn(sKHH.c_str(), sType.c_str(), dWTJG, sDBZJZH.c_str());
            }
			
			if (bRet > 0)
            {
                cout << "�ͻ��ʽ����ɹ���24" << bRet << endl;

            }		
			else {
				MARITPDK_GetLastError(msg);
				cout << "�ͻ��ʽ����ʧ�ܣ�24:" << msg << endl;
			}
			
			break;
        case 25:
            
			cout << "=========== �ͻ��ʽ������25 ===========" << endl;
            printf("�����뽻�����룺  \n");
            getline(cin,sType);
            printf("�������ʽ��˻���  \n");
            getline(cin,sDBZJZH);
			printf("�����������  \n");
			getline(cin, sWTJG);
			dWTJG = atof(sWTJG.c_str());

            bRet = false;
            if(sDBZJZH.empty())
            {
				bRet = MARITPDK_FundTransOut(sKHH.c_str(), sType.c_str(), dWTJG);
            }
            else
            {
				bRet = MARITPDK_FundTransOut(sKHH.c_str(), sType.c_str(), dWTJG, sDBZJZH.c_str());
            }
			if (bRet > 0)
            {
                cout << "�ͻ��ʽ�����ɹ���25" << bRet << endl;

            }				
			else {
				MARITPDK_GetLastError(msg);
				cout << "�ͻ��ʽ����ʧ�ܣ�25:" << msg << endl;
			}
			
			break;
        case 26:
            
			cout << "=========== ��ѯ���н��׿����ʽ� ===========" << endl;
            printf("�����뽻�����룺  \n");
            getline(cin,sType);
            bRet = false;
            bRet = MARITPDK_QueryCentreFundAvl( sKHH.c_str(),sPwd.c_str(), sZJZH.c_str(),dKQZJ,"","");
			if (bRet)
            {
                cout << "��ѯ���н��׿����ʽ�ɹ�" << bRet << "dKYZJ:" << dKQZJ << endl;

            }
				
			else {
				MARITPDK_GetLastError(msg);
				cout << "��ѯ���н��׿����ʽ�ʧ��:" << msg << endl;
			}
			
			break;
			
          case 27:  
          cout << "=========== �ͻ��ŵ�¼ ===========" << endl;
            printf("������ͻ��� \n");
        getline(cin,sKHH);
        bRet = MARITPDK_TradeLogin("A5_RS", sKHH.c_str(), sPwd.c_str());
        break;
        case 28:  
        cout << "=========== �ʽ��˺ŵ�¼ ===========" << endl;
        printf("�������ʽ��˺� \n");
        getline(cin,sZJZH);
        printf("������Ӫҵ�� \n");
        getline(cin,sYYB);

        {
            //bRet = MARITPDK_TradeLoginByFundAcc("A5_RS",sZJZH.c_str(),sYYB.c_str(), sPwd.c_str(),sKHH);
        }
        break;
        case 29:
			/*
			cout << "=========== ��ѯ������ȯ��ծ���� ===========" << endl;
			printf("�����뽻���� \n");
            getline(cin,sZJZH);
            printf("������֤ȯ���� \n");
            getline(cin,sYYB);

			nRet = MARITPDK_QueryTradeData_MR_RQFZHZ( sKHH.c_str(),sZJZH.c_str(),sYYB.c_str(), XYRQFZHZRecord);
			if (nRet >= 0)
				cout << "query rqfzhz success. num:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "query rqfzhz failed. msg:" << msg << endl;
			}
			for (int index = 0; index < nRet; ++index) {

					printf("AccountId:%s --m_szJYS:%s;m_szZQDM:%s;m_nFZSL:%d;m_nDRRQCJSL:%d;m_nHQWTSL:%d;m_nHQCJSL:%d;m_nYQWTSL:%d;m_nYQSL:%d\n",
						XYRQFZHZRecord[index].AccountId, XYRQFZHZRecord[index].m_szJYS, XYRQFZHZRecord[index].m_szZQDM,
						XYRQFZHZRecord[index].m_nFZSL, XYRQFZHZRecord[index].m_nDRRQCJSL,XYRQFZHZRecord[index].m_nHQWTSL,XYRQFZHZRecord[index].m_nHQCJSL,XYRQFZHZRecord[index].m_nYQWTSL,XYRQFZHZRecord[index].m_nYQSL);

			}
			*/
			break;
       
      
         
            case 30:
		
			cout << "=========== �̺󶨼�����===========" << endl;
            printf("�����뽻���� ֤ȯ���� ί�м۸�\n");
            getline(cin,sJYS);
            if(sJYS == "SH")
            {
                sGdh = sShGdh;
            }
            else
            {
                sGdh = sSzGdh;
            }
            getline(cin,sZQDM);
            getline(cin,sWTJG);
            dWTJG = atof(sWTJG.c_str());
            
			nRet = MARITPDK_MarginEntrust(sKHH.c_str(),sJYS.c_str(),sZQDM.c_str(),JYLB_PHDJMR,200,dWTJG,DDLX_XJWT,sGdh.c_str(),0,"",0,0);
			  

			if (nRet > 0)
				cout << "order success. wth:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "order failed. msg:" << msg   << " err code:"<< nRet  << endl;
			}
			break;

            case 31:
			cout << "=========== �̺󶨼�����===========" << endl;
            printf("�����뽻���� ֤ȯ���� ί�м۸�\n");
            getline(cin,sJYS);
            if(sJYS == "SH")
            {
                sGdh = sShGdh;
            }
            else
            {
                sGdh = sSzGdh;
            }
            getline(cin,sZQDM);
            getline(cin,sWTJG);
            dWTJG = atof(sWTJG.c_str());
            nRet = MARITPDK_MarginEntrust(sKHH.c_str(),sJYS.c_str(),sZQDM.c_str(),JYLB_PHDJMC,200,dWTJG,DDLX_XJWT,sGdh.c_str(),0,"",0,0);

			  

			if (nRet > 0)
				cout << "order success. wth:" << nRet << endl;
			else {
				MARITPDK_GetLastError(msg);
				cout << "order failed. msg:" << msg << endl;
			}
			break;
			case 35:
			cout << "=========== ��ѯA�ɿɵ������������б�===========" << endl;
			nRet = MARITPDK_QueryPosition_DBHR_All(sKHH.c_str(), DBHRSLRecord);

			if (nRet > 0)
			{
				cout << "�ֲּ�¼�� " << nRet << endl;
				for (int index = 0; index < nRet; ++index) {

					printf("index:%d; AccountId:%s; MarKet:%s; SecuAccount:%s; StockCode:%s; StockName:%s; KDBHRSL:%ld; KMCSL:%ld; MRCJSL:%ld\n",
						index, DBHRSLRecord[index].AccountId, DBHRSLRecord[index].m_szJYS, DBHRSLRecord[index].m_szGDH, DBHRSLRecord[index].m_szZQDM, DBHRSLRecord[index].m_szZQMC, DBHRSLRecord[index].m_nKWTSL, DBHRSLRecord[index].m_nKMCSL, DBHRSLRecord[index].m_nMRCJSL);

				}
			}
			else {
				MARITPDK_GetLastError(msg);
				cout << "order failed. msg:" << msg << endl;
			}
			break;
			case 36:

				cout << "=========== ר��ͷ��֤ȯ���� ===========" << endl;
				printf("�����뽻���� ֤ȯ���� �������� ԤԼ������������ ��������\n");
				getline(cin, sJYS);
				if (sJYS == "SH")
				{
					sGdh = sShGdh;
				}
				else
				{
					sGdh = sSzGdh;
				}
				getline(cin, sZQDM);
				getline(cin, sWTSL);
				getline(cin, sZQSL);
				getline(cin, sTCLX);
				lfssl = atol(sWTSL.c_str());
				lyysl = atol(sZQSL.c_str());
				lflag = atol(sTCLX.c_str());
				bRet = MARITPDK_SpecialPosition_ZQDB(sKHH.c_str(), sJYS.c_str(), sZQDM.c_str(), lfssl, lyysl, lflag, ZQDBRecord);
				if (bRet>0)
				{
					cout << "�ͻ�֤ȯ�ⶳ�ɹ�" << bRet << endl;
					for (int index = 0; index < bRet; ++index)
					{
						printf("m_nSQH:%ld; m_nLSH:%ld; m_nJCCL:%ld; m_nKMCSL:%ld; m_nDBSL:%ld; m_nFSSL:%ld;\n",
							ZQDBRecord[index].m_nSQH, ZQDBRecord[index].m_nLSH, ZQDBRecord[index].m_nJCCL, ZQDBRecord[index].m_nKMCSL, ZQDBRecord[index].m_nBDSL, ZQDBRecord[index].m_nFSSL);
					}
				}
				else {
					MARITPDK_GetLastError(msg);
					cout << "�ͻ�֤ȯ�ⶳʧ��:" << msg << endl;
				}

				break;
			case 37:

				cout << "=========== ר��ͷ���ʽ���� ===========" << endl;
				printf("������������ ��������\n");
				getline(cin, sWTJG);
				getline(cin, sTCLX);
				dWTJG = atof(sWTJG.c_str());
				lflag = atol(sTCLX.c_str());
				bRet = MARITPDK_SpecialPosition_ZJDB(sKHH.c_str(), dWTJG, lflag);
				if (bRet > 0)
				{
					cout << "�ͻ��ʽ�ⶳ�ɹ�" << bRet << endl;
				}
				else {
					MARITPDK_GetLastError(msg);
					cout << "�ͻ��ʽ�ⶳʧ��:" << msg << endl;
				}

				break;
			case 38:

				cout << "=========== ��ѯ֤ȯ������ ===========" << endl;
				printf("�����뽻���� �������� ����\n");
				getline(cin, sJYS);
				getline(cin, sWTSL);
				getline(cin, sTCLX);
				lflag = atol(sTCLX.c_str());
				bRet = MARITPDK_QueryTradeData_MR_ZQHMD(sJYS.c_str(), sWTSL.c_str(), lflag, ZQHMDRecord);
				if (bRet > 0)
				{
					cout << "��ѯ֤ȯ������" << bRet << endl;
					for (int index = 0; index < bRet; ++index)
					{
						printf("TYPE:%ld; JYS:%s; ZQZBZ:%s; JYLB:%ld; ZQLB:%s; XYSX:%s; XYSXZ:%s;\n",
							ZQHMDRecord[index].m_nTYPE, ZQHMDRecord[index].m_szJYS, ZQHMDRecord[index].m_szZQZBZ, ZQHMDRecord[index].m_nJYLB, ZQHMDRecord[index].m_szZQLB, ZQHMDRecord[index].m_szXYSX, ZQHMDRecord[index].m_szXYSXZ);
					}
				}
				else {
					MARITPDK_GetLastError(msg);
					cout << "��ѯ֤ȯ������ʧ��:" << msg << endl;
				}

				break;
			case 39:

				cout << "=========== ��ѯ�¹��깺 ===========" << endl;
				printf("�����뽻���� ֤ȯ���� �Ϲ����� ���з�ʽ\n");
				getline(cin, sJYS);
				getline(cin, sZQDM);
				getline(cin, sRQ);
				getline(cin, sTip);
				bRet = MARITPDK_QueryNewStockInfo(sJYS.c_str(), sZQDM.c_str(), atol(sRQ.c_str()), sTip.c_str(), XGSGRecord);
				if (bRet > 0)
				{
					cout << "��ѯ�¹��깺�ɹ�" << bRet << endl;
					for (int index = 0; index < bRet; ++index)
					{
						printf("JYS:%s; ZQDM:%s; ZQMC:%s; FXFS:%d; RGJG:%lf; RGDM:%s; RGRQ:%d; WTSX:%d; BDRQ:%d\n",
							XGSGRecord[index].m_szJYS, XGSGRecord[index].m_szZQDM, XGSGRecord[index].m_szZQMC, XGSGRecord[index].m_nFXFS, 
							XGSGRecord[index].m_dRGJG, XGSGRecord[index].m_szRGDM, XGSGRecord[index].m_nRGRQ, XGSGRecord[index].m_nWTSX, XGSGRecord[index].m_nBDRQ);
					}
				}
				else {
					MARITPDK_GetLastError(msg);
					cout << "��ѯ�¹��깺ʧ��:" << msg << endl;
				}

				break;
			case 40:

				cout << "=========== ��ѯ��ծ�䶯��ϸ ===========" << endl;
				printf("�����뽻���� ֤ȯ���� ��ѯ���� ��ҳ������ʼֵ\n");
				getline(cin, sJYS);
				getline(cin, sZQDM);
				getline(cin, sTip);
				getline(cin, sLSH);
				nRet = MARITPDK_QueryTradeData_MR_DRBD(sKHH.c_str(), sJYS.c_str(), sZQDM.c_str(), atoi(sTip.c_str()), atoi(sLSH.c_str()), FZBDMXRecord);
				if (nRet >= 0)
					cout << "��ѯ��ծ�䶯��ϸ�ɹ�. num:" << nRet << endl;
				else {
					MARITPDK_GetLastError(msg);
					cout << "��ѯ��ծ�䶯��ϸʧ��. msg:" << msg << endl;
				}
				for (int index = 0; index < nRet; ++index) {

					printf("KHH:%s\t LSH:%d\t HYBH:%s\t WTH:%d\t HBXH:%d\t JYS:%s\t ZQDM:%s\t FSRQ:%d\t FSSJ:%s\t JYLB:%d\t HYLB:%d\t FSHYSL:%d\t HYSL:%d\t FSHYJE:%lf\t HYJE:%lf\t FSFY:%lf\t HYFY:%lf\t FSLX:%lf\t HYLX:%lf\t FSFX:%lf\t HYFX:%lf\t TCBH:%s\t ZY:%s\t CXBZ:%d\t QSBZ:%d\t BrowIndex:%d\t \n\n",
						FZBDMXRecord[index].AccountId, FZBDMXRecord[index].m_nLSH, FZBDMXRecord[index].m_szHYBH, FZBDMXRecord[index].m_nWTH,
						FZBDMXRecord[index].m_nHBXH, FZBDMXRecord[index].m_szJYS, FZBDMXRecord[index].m_szZQDM, FZBDMXRecord[index].m_nFSRQ,
						FZBDMXRecord[index].m_szFSSJ, FZBDMXRecord[index].m_nJYLB, FZBDMXRecord[index].m_nHYLB, FZBDMXRecord[index].m_nFSHYSL,
						FZBDMXRecord[index].m_nHYSL, FZBDMXRecord[index].m_dFSHYJE, FZBDMXRecord[index].m_dHYJE, FZBDMXRecord[index].m_dFSFY,
						FZBDMXRecord[index].m_dHYFY, FZBDMXRecord[index].m_dFSLX, FZBDMXRecord[index].m_dHYLX, FZBDMXRecord[index].m_dFSFX,
						FZBDMXRecord[index].m_dHYFX, FZBDMXRecord[index].m_szTCBH, FZBDMXRecord[index].m_szZY, FZBDMXRecord[index].m_nCXBZ,
						FZBDMXRecord[index].m_nQSBZ, FZBDMXRecord[index].m_nBrowIndex);
				}

				break;
			case 41:

				cout << "=========== ���ʲֵ���ϸ��ѯ ===========" << endl;
				printf("������ͻ��� �������� Ӫҵ�� ������ ���� ��ʼ���� �������� ί�з�ʽ ������������ �˽��ʶ �Ƿ����ʵʱί�� \n");
				getline(cin, sKHH);
				getline(cin, sPwd);
				getline(cin, sYYB);
				getline(cin, sJYS);
				getline(cin, sBZ);
				getline(cin, sKSRQ);
				getline(cin, sJSRQ);
				getline(cin, sWTFS);
				getline(cin, sTCLX);
				getline(cin, sTip);
				getline(cin, sFLAG);
				nRet = MARITPDK_QueryTradeData_MR_RZCDMX(sKHH.c_str(), sPwd.c_str(), sYYB.c_str(), sJYS.c_str(), sBZ.c_str(), sKSRQ.c_str(), sJSRQ.c_str(), sWTFS.c_str(), sTCLX.c_str(), atoi(sTip.c_str()), sFLAG.c_str(), RZCDMXRecord);
				if (nRet >= 0)
					cout << "���ʲֵ���ϸ��ѯ�ɹ�. num:" << nRet << endl;
				else {
					MARITPDK_GetLastError(msg);
					cout << "���ʲֵ���ϸ��ѯʧ��. msg:" << msg << endl;
				}
				for (int index = 0; index < nRet; ++index) {

					printf("KCLSH:%s\t KCRQ:%s\t CDDQR:%s\t ZQDM:%s\t ZQMC:%s\t LJBS:%s\t \n\n",
						RZCDMXRecord[index].m_sKCLSH, RZCDMXRecord[index].m_sKCRQ, RZCDMXRecord[index].m_sCDDQR, RZCDMXRecord[index].m_sZQDM,
						RZCDMXRecord[index].m_sZQMC, RZCDMXRecord[index].m_sLJBS);
				}

				break;
			case 42:

				cout << "=========== ��ȯ�ֵ���ϸ��ѯ ===========" << endl;
				printf("������ͻ��� �������� Ӫҵ�� ������ ���� ��ʼ���� �������� ί�з�ʽ ������������ �˽��ʶ �Ƿ����ʵʱί�� \n");
				getline(cin, sKHH);
				getline(cin, sPwd);
				getline(cin, sYYB);
				getline(cin, sJYS);
				getline(cin, sBZ);
				getline(cin, sKSRQ);
				getline(cin, sJSRQ);
				getline(cin, sWTFS);
				getline(cin, sTCLX);
				getline(cin, sTip);
				getline(cin, sFLAG);
				nRet = MARITPDK_QueryTradeData_MR_RQCDMX(sKHH.c_str(), sPwd.c_str(), sYYB.c_str(), sJYS.c_str(), sBZ.c_str(), sKSRQ.c_str(), sJSRQ.c_str(), sWTFS.c_str(), sTCLX.c_str(), atoi(sTip.c_str()), sFLAG.c_str(), RQCDMXRecord);
				if (nRet >= 0)
					cout << "��ȯ�ֵ���ϸ��ѯ�ɹ�. num:" << nRet << endl;
				else {
					MARITPDK_GetLastError(msg);
					cout << "��ȯ�ֵ���ϸ��ѯʧ��. msg:" << msg << endl;
				}
				for (int index = 0; index < nRet; ++index) {

					printf("KCLSH:%s\t KCRQ:%s\t CDDQR:%s\t ZQDM:%s\t ZQMC:%s\t QYBCFS:%s\t \n\n",
						RQCDMXRecord[index].m_sKCLSH, RQCDMXRecord[index].m_sKCRQ, RQCDMXRecord[index].m_sCDDQR, RQCDMXRecord[index].m_sZQDM,
						RQCDMXRecord[index].m_sZQMC, RQCDMXRecord[index].m_sQYBCFS);
				}

				break;
			case 43:

				cout << "=========== ������ȯչ�� ===========" << endl;
				printf("������ͻ��� �������� Ӫҵ�� ������ �ֵ��� ��Լ���� �������� ��ʼ���� �������� ί�з�ʽ\n");
				getline(cin, sKHH);
				getline(cin, sPwd);
				getline(cin, sYYB);
				getline(cin, sJYS);
				getline(cin, sLSH);
				getline(cin, sTCLX);
				getline(cin, sRQ);
				getline(cin, sKSRQ);
				getline(cin, sJSRQ);
				getline(cin, sFLAG);
				bRet = MARITPDK_ContractExtension(sKHH.c_str(), sPwd.c_str(), sYYB.c_str(), sJYS.c_str(), sLSH.c_str(), sTCLX.c_str(), sRQ.c_str(), sKSRQ.c_str(), sJSRQ.c_str(), sFLAG.c_str());
				if (bRet > 0)
				{
					cout << "������ȯչ�ڳɹ� " << bRet << endl;
				}
				else {
					MARITPDK_GetLastError(msg);
					cout << "������ȯչ��ʧ��:" << msg << endl;
				}

				break;
			case 44:

				cout << "=========== �ֵ��������ܾ�ԭ���ѯ ===========" << endl;
				printf("������ͻ��� �������� Ӫҵ�� ������ ��ʼ���� �������� ί�з�ʽ\n");
				getline(cin, sKHH);
				getline(cin, sPwd);
				getline(cin, sYYB);
				getline(cin, sJYS);
				getline(cin, sKSRQ);
				getline(cin, sJSRQ);
				getline(cin, sWTFS);
				nRet = MARITPDK_QueryTradeData_CDBGSQ_REFUSE(sKHH.c_str(), sPwd.c_str(), sYYB.c_str(), sJYS.c_str(), sKSRQ.c_str(), sJSRQ.c_str(), sWTFS.c_str(), CDBGSQJJYYRecord);
				if (nRet >= 0)
					cout << "�ֵ��������ܾ�ԭ���ѯ�ɹ�. num:" << nRet << endl;
				else {
					MARITPDK_GetLastError(msg);
					cout << "�ֵ��������ܾ�ԭ���ѯʧ��. msg:" << msg << endl;
				}
				for (int index = 0; index < nRet; ++index) {

					printf("SQRQ:%s\t KHH:%s\t SQXH:%s\t CDLSH:%s\t CDFSR:%s\t CDLX:%s\t TZLX:%s\t YYB:%s\t JYS:%s\t ZQDM:%s\t JJYY:%s\t LSSCSJ:%s\t \n\n",
						CDBGSQJJYYRecord[index].m_sSQRQ, CDBGSQJJYYRecord[index].m_sKHH, CDBGSQJJYYRecord[index].m_sSQXH,
						CDBGSQJJYYRecord[index].m_sCDLSH, CDBGSQJJYYRecord[index].m_sCDFSR, CDBGSQJJYYRecord[index].m_sCDLX,
						CDBGSQJJYYRecord[index].m_sTZLX, CDBGSQJJYYRecord[index].m_sYYB, CDBGSQJJYYRecord[index].m_sJYS, 
						CDBGSQJJYYRecord[index].m_sZQDM, CDBGSQJJYYRecord[index].m_sJJYY, CDBGSQJJYYRecord[index].m_sLSSCSJ);
				}

				break;
			case 45:

				cout << "=========== �ֵ���������ѯ ===========" << endl;
				printf("������ͻ��� �������� Ӫҵ��(Դ) ������ Ӫҵ�� ֤ȯ���� ��ʼ���� �������� ��Լ���� �������� ��Ʒ��� ����״̬ ί�з�ʽ\n");
				getline(cin, sKHH);
				getline(cin, sPwd);
				getline(cin, sYYB);
				getline(cin, sJYS);
				getline(cin, sJGDM);
				getline(cin, sZQDM);
				getline(cin, sKSRQ);
				getline(cin, sJSRQ);
				getline(cin, sHYLX);
				getline(cin, sTCLX);
				getline(cin, sHYBH);
				getline(cin, sFLAG);
				getline(cin, sWTFS);
				nRet = MARITPDK_QueryTradeData_CDBGSQ(sKHH.c_str(), sPwd.c_str(), sYYB.c_str(), sJYS.c_str(), sJGDM.c_str(), sZQDM.c_str(), sKSRQ.c_str(), sJSRQ.c_str(), sHYLX.c_str(), sTCLX.c_str(), sHYBH.c_str(), sFLAG.c_str(), sWTFS.c_str(), CDBGSQRecord);
				if (nRet >= 0)
					cout << "�ֵ���������ѯ�ɹ�. num:" << nRet << endl;
				else {
					MARITPDK_GetLastError(msg);
					cout << "�ֵ���������ѯʧ��. msg:" << msg << endl;
				}
				for (int index = 0; index < nRet; ++index) {

					printf("SQRQ:%s\t KHH:%s\t m_sSQLSH:%s\t SQRQ:%s\t m_sTZLX:%s\t m_sHYLX:%s\t m_sYYB:%s\t m_sSQZG:%s\t m_sSHZG:%s\t m_sSHZT:%s\t m_sSHRQ:%s\t m_sSHSJ:%s\t m_sKCKSRQ:%s\t m_sKCJSRQ:%s\t m_sJYS:%s\t m_sZQDM:%s\t m_sFJSJ:%s\t m_sWTLY:%s\t m_sBZ:%s\t m_nCDBS:%d\t m_nCLBS:%d\t\n\n",
						CDBGSQRecord[index].m_sSQRQ, CDBGSQRecord[index].m_sKHH, CDBGSQRecord[index].m_sSQLSH,
						CDBGSQRecord[index].m_sTZLX, CDBGSQRecord[index].m_sHYLX, CDBGSQRecord[index].m_sYYB,
						CDBGSQRecord[index].m_sSQZG, CDBGSQRecord[index].m_sSQSJ, CDBGSQRecord[index].m_sSHZG,
						CDBGSQRecord[index].m_sSHZT, CDBGSQRecord[index].m_sSHRQ, CDBGSQRecord[index].m_sSHSJ,
						CDBGSQRecord[index].m_sKCKSRQ, CDBGSQRecord[index].m_sKCJSRQ, CDBGSQRecord[index].m_sJYS,
						CDBGSQRecord[index].m_sZQDM, CDBGSQRecord[index].m_sFJSJ, CDBGSQRecord[index].m_sWTLY,
						CDBGSQRecord[index].m_sBZ, CDBGSQRecord[index].m_dCDBS, CDBGSQRecord[index].m_dCLBS);
				}

				break;
			case 46:

				cout << "=========== �¹���ǩ��ѯ ===========" << endl;
				printf("������ͻ��� �������� Ӫҵ�� ������ ֤ȯ���� ��ʼ���� �������� ��ѯ���� �������� ����Ӫҵ������ ������ˮ�� ί�з�ʽ\n");
				getline(cin, sKHH);
				getline(cin, sPwd);
				getline(cin, sYYB);
				getline(cin, sJYS);
				getline(cin, sZQDM);
				getline(cin, sKSRQ);
				getline(cin, sJSRQ);
				getline(cin, sTemp);
				nSearchCount = atoi(sTemp.c_str());
				getline(cin, sRQ);
				getline(cin, sJGDM);
				getline(cin, sLSH);
				getline(cin, sWTFS);
				nRet = MARITPDK_QueryTradeData_XGZQ(sKHH.c_str(), sPwd.c_str(), sYYB.c_str(), sJYS.c_str(), sZQDM.c_str(), sKSRQ.c_str(), sJSRQ.c_str(), nSearchCount, sRQ.c_str(), sJGDM.c_str(), sLSH.c_str(), sWTFS.c_str(), XGZQRecord);
				if (nRet >= 0)
					cout << "�¹���ǩ��ѯ�ɹ�. num:" << nRet << endl;
				else {
					MARITPDK_GetLastError(msg);
					cout << "�¹���ǩ��ѯʧ��. msg:" << msg << endl;
				}
				for (int index = 0; index < nRet; ++index) {

					printf("KHH:%s\t FSRQ:%s\t YYB:%s\t GDH:%s\t GDXM:%s\t SCDM:%s\t SCMC:%s\t ZQDM:%s\t ZQMC:%s\t LSH:%s\t KKRQ:%s\t ZQLB:%s\t CLZT:%s\t ZQSL:%d\t CJJG:%lf\t CJJE:%lf\t ZQGS:%d\t TQDJBZ:%s\t SJZQSL:%lf\t SJZQJE:%lf\t FQSL:%lf\t FQJE:%lf\t \n\n",
						XGZQRecord[index].m_sKHH, XGZQRecord[index].m_sFSRQ, XGZQRecord[index].m_sKHYYB,
						XGZQRecord[index].m_sGDH, XGZQRecord[index].m_sGDXM, XGZQRecord[index].m_sSCDM,
						XGZQRecord[index].m_sSCMC, XGZQRecord[index].m_sZQDM, XGZQRecord[index].m_sZQMC,
						XGZQRecord[index].m_sLSH, XGZQRecord[index].m_sKKRQ, XGZQRecord[index].m_sZQLB,
						XGZQRecord[index].m_sCLZT, XGZQRecord[index].m_nZQSL, XGZQRecord[index].m_dCJJG,
						XGZQRecord[index].m_dCJJE, XGZQRecord[index].m_nZQGS, XGZQRecord[index].m_sTQDJBZ,
						XGZQRecord[index].m_dSJZQSL, XGZQRecord[index].m_dSJZQJE, XGZQRecord[index].m_dFQSL,
						XGZQRecord[index].m_dFQJE);
				}

				break;
			case 47:

				cout << "=========== �¹���Ų�ѯ ===========" << endl;
				printf("������ͻ��� �������� Ӫҵ�� ������ �ɶ��� ��Ŵ��� ��ʼ���� �������� ��ѯ���� ������ˮ�� ί�з�ʽ\n");
				getline(cin, sKHH);
				getline(cin, sPwd);
				getline(cin, sYYB);
				getline(cin, sJYS);
				getline(cin, sGdh);
				getline(cin, sZQDM);
				getline(cin, sKSRQ);
				getline(cin, sJSRQ);
				getline(cin, sTemp);
				nSearchCount = atoi(sTemp.c_str());
				getline(cin, sLSH);
				getline(cin, sWTFS);
				nRet = MARITPDK_QueryTradeData_PHCX(sKHH.c_str(), sPwd.c_str(), sYYB.c_str(), sJYS.c_str(), sGdh.c_str(), sZQDM.c_str(), sKSRQ.c_str(), sJSRQ.c_str(), nSearchCount, sLSH.c_str(), sWTFS.c_str(), PHCXRecord);
				if (nRet >= 0)
					cout << "�¹���Ų�ѯ�ɹ�. num:" << nRet << endl;
				else {
					MARITPDK_GetLastError(msg);
					cout << "�¹���Ų�ѯʧ��. msg:" << msg << endl;
				}
				for (int index = 0; index < nRet; ++index) {

					printf("SCDM:%s\t SCMC:%s\t GDH:%s\t PHDM:%s\t PHMC:%s\t QSPH:%s\t PHRQ:%s\t LSH:%s\t CLXX:%s\t PHGS:%d\t\n\n",
						PHCXRecord[index].m_sSCDM, PHCXRecord[index].m_sSCMC,PHCXRecord[index].m_sGDH, 
						PHCXRecord[index].m_sPHDM, PHCXRecord[index].m_sPHMC,PHCXRecord[index].m_sQSPH, 
						PHCXRecord[index].m_sPHRQ, PHCXRecord[index].m_sLSH,PHCXRecord[index].m_sCLXX, 
						PHCXRecord[index].m_nPHGS);
				}

				break;
			case 48:

				cout << "=========== ��֤ҵ����ˮ��ѯ ===========" << endl;
				printf("������ͻ��� �������� Ӫҵ�� ������ ���д��� �����˺� ��ѯ���� ��ˮ�� ί�з�ʽ ������ˮ�� �Ƿ�ȡ���˻���ˮ \n");
				getline(cin, sKHH);
				getline(cin, sPwd);
				getline(cin, sYYB);
				getline(cin, sJYS);
				getline(cin, sJGDM);
				getline(cin, sTip);
				getline(cin, sTemp);
				nSearchCount = atoi(sTemp.c_str());
				getline(cin, sLSH);
				getline(cin, sWTFS);
				getline(cin, sHYBH);
				getline(cin, sFLAG);
				nRet = MARITPDK_QueryTradeData_YZYWLS(sKHH.c_str(), sPwd.c_str(), sYYB.c_str(), sJYS.c_str(), sJGDM.c_str(), sTip.c_str(),nSearchCount, sLSH.c_str(), sWTFS.c_str(), sHYBH.c_str(), atoi(sFLAG.c_str()), YZYWLSRecord);
				if (nRet >= 0)
					cout << "��֤ҵ����ˮ��ѯ�ɹ�. num:" << nRet << endl;
				else {
					MARITPDK_GetLastError(msg);
					cout << "��֤ҵ����ˮ��ѯʧ��. msg:" << msg << endl;
				}
				for (int index = 0; index < nRet; ++index) {

					printf("YWLB:%s\t YWLBMC:%s\t FSJE:%lf\t ZZDM:%s\t ZZXX:%s\t LSH:%s\t YHMC:%s\t YHDM:%s\t WTSJ:%s\t WTRQ:%s\t \n\n",
						YZYWLSRecord[index].m_sYWLB, YZYWLSRecord[index].m_sYWLBMC, YZYWLSRecord[index].m_dFSJE,
						YZYWLSRecord[index].m_sCLJG, YZYWLSRecord[index].m_sJGSM, YZYWLSRecord[index].m_sLSH,
						YZYWLSRecord[index].m_sYHMC, YZYWLSRecord[index].m_sYHDM, YZYWLSRecord[index].m_sWTSJ,
						YZYWLSRecord[index].m_sWTRQ);
				}

				break;
			case 49:

				cout << "=========== ��֤ת��ҵ�� ===========" << endl;
				printf("������ͻ��� �������� �ʽ��˺� Ӫҵ�� ������ ���д��� �����˺� ҵ����� ת�˽�� �������� ȡ������ ί�з�ʽ\n");
				getline(cin, sKHH);
				getline(cin, sPwd);
				getline(cin, sZJZH);
				getline(cin, sYYB);
				getline(cin, sJYS);
				getline(cin, sJGDM);
				getline(cin, sYHZH);
				getline(cin, sTip);
				getline(cin, sWTJG);
				getline(cin, sYHMM);
				getline(cin, sQKMM);
				getline(cin, sWTFS);
				bRet = MARITPDK_BankBusiness(sKHH.c_str(), sPwd.c_str(), sZJZH.c_str(), sYYB.c_str(), sJYS.c_str(), sJGDM.c_str(), sYHZH.c_str(), atoi(sTip.c_str()), atof(sWTJG.c_str()), sYHMM.c_str(), sQKMM.c_str(), sWTFS.c_str());
				if (bRet > 0)
				{
					cout << "��֤ת��ҵ��ɹ�" << bRet << endl;
				}
				else {
					MARITPDK_GetLastError(msg);
					cout << "��֤ת��ҵ��ʧ��:" << msg << endl;
				}

				break;
			case 50:

				cout << "=========== ��ѯ�ͻ����д��� ===========" << endl;
				printf("������ͻ��� �������� Ӫҵ�� �г����� ί�з�ʽ ������� �Ƿ�ȡ���˻���ˮ\n");
				getline(cin, sKHH);
				getline(cin, sPwd);
				getline(cin, sYYB);
				getline(cin, sJYS);
				getline(cin, sWTFS);
				getline(cin, sTip);
				getline(cin, sFLAG);
				nRet = MARITPDK_QueryTradeData_YHDM(sKHH.c_str(), sPwd.c_str(), sYYB.c_str(), sJYS.c_str(), sWTFS.c_str(), atoi(sTip.c_str()), atoi(sFLAG.c_str()), YHDMRecord);
				if (nRet >= 0)
					cout << "��ѯ�ͻ����д���ɹ�. num:" << nRet << endl;
				else {
					MARITPDK_GetLastError(msg);
					cout << "��ѯ�ͻ����д���ʧ��. msg:" << msg << endl;
				}
				for (int index = 0; index < nRet; ++index) {

					printf("YHDM:%s\t YHJC:%s\t YHZH:%s\t YHBZ:%s\t HBDM:%s\t ZZYMMXX:%s\t YZZMMXX:%s\t ZHH:%s\t ZHLB:%s\t ZHLBMC:%s\t KSQX:%d\t \n\n",
						YHDMRecord[index].m_sYHDM, YHDMRecord[index].m_sYHJC, YHDMRecord[index].m_sYHZH,
						YHDMRecord[index].m_sYHBZ, YHDMRecord[index].m_sHBDM, YHDMRecord[index].m_sZZYMMXX,
						YHDMRecord[index].m_sYZZMMXX, YHDMRecord[index].m_sZHH, YHDMRecord[index].m_sZHLB,
						YHDMRecord[index].m_sZHLBMC, YHDMRecord[index].m_nKSQX);
				}

				break;
			case 51:

				cout << "=========== ��ѯ������� ===========" << endl;
				printf("������ͻ��� �������� �ʽ��˺� ���д��� �����˺� �������� ȡ������\n");
				getline(cin, sKHH);
				getline(cin, sPwd);
				getline(cin, sZJZH);
				getline(cin, sJGDM);
				getline(cin, sYHZH);
				getline(cin, sYHMM);
				getline(cin, sQKMM);
				nRet = MARITPDK_QueryTradeData_YHYE(sKHH.c_str(), sPwd.c_str(), sZJZH.c_str(), sJGDM.c_str(), sYHZH.c_str(), sYHMM.c_str(), sQKMM.c_str(), YHYERecord);
				if (nRet >= 0)
					cout << "��ѯ�������ɹ�. num:" << nRet << endl;
				else {
					MARITPDK_GetLastError(msg);
					cout << "��ѯ�������ʧ��. msg:" << msg << endl;
				}
				for (int index = 0; index < nRet; ++index) {

					printf("LSH:%s\t YHYE:%lf\t \n\n",
						YHYERecord[index].m_sLSH, YHYERecord[index].m_dYHYE);
				}

				break;
		default:
			break;
		}

	} 
    getchar();
    MARITPDK_Exit();
	return 0;
}

