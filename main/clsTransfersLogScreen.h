#pragma once
#include"clsBankClient.h"
#include"clsScreen.h"
#include<iostream>
#include<iomanip>
using namespace std;
class clsTransfersLogScreen :protected clsScreen
{
private:
	static void _PrintHead(clsBankClient::stRecordLog Log)
	{
		cout << "\t| " << setw(25) << left << Log.DateTime;
		cout << "\t| " << setw(12) << left << Log.AccountNumberFrom;
		cout << "\t| " << setw(12) << left << Log.AccountNumberTo;
		cout << "\t| " << setw(10) << left << Log.thidTransfer;
		cout << "\t| " << setw(12) << left << Log.totalBalanceFrom;
		cout << "\t| " << setw(12) << left << Log.totalBalanceTo;
		cout << "\t| " << setw(10) << left << Log.thisUser;


	}
public:
	static void PrintHeader()
	{
		vector<clsBankClient::stRecordLog>VLog = clsBankClient::GetTransferLog();
		string Title = "\tTransfers Log Screen";
		string SubTitle = "\tUsers : ( " + to_string(VLog.size()) + " ) " + "(L)";
		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
		cout << "_______________________________________________________\n" << endl;

		cout << "\t| " << setw(25) << left << "Date|Time";
		cout << "\t| " << setw(12) << left << "S.Acct";
		cout << "\t| " << setw(12) << left << "D.Acct";
		cout << "\t| " << setw(10) << left << "Amount";
		cout << "\t| " << setw(12) << left << "S.Balance";
		cout << "\t| " << setw(12) << left << "D.Balance";
		cout << "\t| " << setw(10) << left << "User";
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
		cout << "_______________________________________________________\n" << endl;
	
		for (clsBankClient::stRecordLog& L : VLog)
		{
			_PrintHead(L);
			cout << endl;
		}

		cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
		cout << "_______________________________________________________\n" << endl;
	}
};

