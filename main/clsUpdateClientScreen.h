#pragma once
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include<iostream>
using namespace std;
class clsUpdateClientScreen :protected clsScreen
{
private:
	static void _printClient(clsBankClient Client)
	{
		cout << "\nClient Information:\n";
		cout << "_________________________________________\n";
		cout << "Client First Name : " << Client.FirstName << endl;
		cout << "Client Last Name : " << Client.LastName << endl;
		cout << "Client Name : " << Client.FullName() << endl;
		cout << "Client Email : " << Client.Email << endl;
		cout << "Client Phone : " << Client.Phone << endl;
		cout << "Client Account Number : " << Client.Accoountnumber() << endl;
		cout << "Client Pin Code : " << Client.pincode << endl;
		cout << "Client Account Balance : " << Client.Accountbalance << endl;
		cout << "_________________________________________\n";
	}

	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Enter Client First Name? ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "Enter Client Last Name? ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "Enter Client Email? ";
		Client.Email = clsInputValidate::ReadString();
		cout << "Enter Client Phone? ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "pin code ? ";
		Client.pincode = clsInputValidate::ReadString();
		cout << "Account Balance ? ";
		Client.Accountbalance = clsInputValidate::ReadFloatNumber();
	}

public:
	static	void ShowUpdateScreen()
	{
		if (!clsScreen::_AccesPermissionDenied(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}
		cout << "Enter Account number ? ";
		string Accountnumber = "";
		Accountnumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsclientExist(Accountnumber))
		{
			cout << "invaled Accountnumber try again :-) ? ";
			Accountnumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(Accountnumber);
		_printClient(Client);

		cout << "Are you sure update this client [ Y \ N ] ? ";
		char what = 'n';
		cin >> ws >> what;

		if (what == 'Y' || what == 'y')
		{
			clsBankClient::enSaveResult saveresult;
			saveresult = Client.SaveResult();
			switch (saveresult)
			{
			case clsBankClient::enSaveResult::svSucceeded:
			{
				_ReadClientInfo(Client);
				cout << "Update Client Successfully :-)\n";
				_printClient(Client);
			}

			case clsBankClient::enSaveResult::svFaildEmptyObject:
			{
				cout << "Error Client Was Empty\n";
				break;
			}
			case clsBankClient::enSaveResult::svAccountnumberExsist:
			{
				cout << "Error Client Account number is exist\n";
				break;
			}
			default:
				break;


			}

		}
	}
};

