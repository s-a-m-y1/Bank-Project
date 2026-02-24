#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include<iostream>
using namespace std;	
class TransferScreen :protected clsScreen
{
private:
	static void _WelcomeTransferScreen()
	{
		cout << "\n\n\t\t\t\t\tWelcome To Transfer Screen :)\n\n";
	}
	static void _Print( clsBankClient client )
	{
		cout << "*==============*Card*=================*" << endl;
		cout << "full name . : " << client.FullName() << endl;
		cout << "Acc.number. : " << client.Accoountnumber() << endl;
		cout << "Balance   . " << client.Accountbalance << endl;
		cout << "*================**=================*" << endl;
	}
public:
	static void ShowTransferScreen()
	{
		clsScreen::_DrawScreenHeader("\t Trnsfare Screen");
		string accountnumber = "";
		cout << "\nPlease enter account number from transfer : ";
		accountnumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsclientExist(accountnumber))
		{
			cout << "\nAccount number is not exist, Enter again : ";
			accountnumber = clsInputValidate::ReadString();
		}
		clsBankClient transferclientfrom = clsBankClient::Find(accountnumber);
		_WelcomeTransferScreen();
		_Print(transferclientfrom);
		///_________________transfare to layer____________________///
		cout << "please enter account number to transfer : ";
		accountnumber = clsInputValidate::ReadString();
		while(!clsBankClient::IsclientExist(accountnumber))
		{
			cout << "\nAccount number is not exist, Enter again : ";
			accountnumber = clsInputValidate::ReadString();
		}
		clsBankClient transferclientTo = clsBankClient::Find(accountnumber);
		_Print(transferclientTo);
		float amount = 0.0;
		cout << "Enter amount to transfer : ";
		amount = clsInputValidate::ReadFloatNumber();
		while (amount<=0||amount> transferclientfrom.Accountbalance)
		{
			cout << " Invaled Number balance please Enter negtive number : ";
			amount = clsInputValidate::ReadFloatNumber();
		}

		char answer = 'n';
		cout << "Are you sure to transfer (y/n) ? ";
		cin >>ws>> answer;
		if (answer=='Y'||answer=='y' && amount != 0 && amount <= transferclientfrom.Accountbalance)
		{
			if (transferclientfrom.Transfer(transferclientTo, amount))
			{
				cout << "Done Transfer :) " << endl;
				_Print(transferclientfrom);
				_Print(transferclientTo);
			
			}
			else
			{
				cout << "Error in transfer :) " << endl;
			}
			//transferclientfrom.Withdraw(amount);
			//transferclientTo.Deposit(amount);
		
			
		}
		else
		{
			cout << "Is not transfer :) " << endl;
		}
		
		
	}
	
};



