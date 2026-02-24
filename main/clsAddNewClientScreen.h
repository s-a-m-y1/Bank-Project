#pragma once
#include "clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include<iostream>
using namespace std;
class clsAddNewClientScreen :protected clsScreen
{
private:
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
	static void _Print(clsBankClient& Client)
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
public:
	static void ShowAddNewClientScreen()
	{
		if (!clsScreen::_AccesPermissionDenied(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		clsScreen::_DrawScreenHeader("\t\tAdd New Client Screen");
		cout << "Please enter Accountnumber ? ";
		string Accountnumber = clsInputValidate::ReadString();
		while (clsBankClient::IsclientExist(Accountnumber))
		{
			cout << "Invaled Accountnumber Try again :-) ? ";
			Accountnumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::GetAddnewclient(Accountnumber);
		_ReadClientInfo(Client);
		clsBankClient::enSaveResult saveResult ;
		saveResult = Client.SaveResult();
		switch (saveResult)
		{
			case clsBankClient::enSaveResult::svSucceeded:
			{
				cout << "\nClient Added Successfully :-)\n";
				_Print(Client);
				break;
			}
			case clsBankClient::enSaveResult::svAccountnumberExsist:
			{
				cout << "\nClient Account Number is already exist, failed to add new client :-(";
				break;
			}
			default:
				{
				cout << "\nFailed to add new client :-(";
				break;
			}
		}
	}
};