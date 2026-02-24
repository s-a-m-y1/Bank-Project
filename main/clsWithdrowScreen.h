#pragma once
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include<iostream>
using namespace std;
class clsWithdrowScreen:protected clsScreen
{
private:
	static void _printClient(clsBankClient& Client)
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


	static void WithdrowScreen()
	{
		clsScreen::_DrawScreenHeader("cls Withdrow Screen ");
		string Accountnumber = "";
		cout << "please Enter Accountnumber : ";
		Accountnumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsclientExist(Accountnumber))
		{
			cout << "Invaled Accountnumber try again :-) ";
			Accountnumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(Accountnumber);
		_printClient(Client);
		float Amount = 0.0;
		cout << "Enter A Amount : ";
		Amount = clsInputValidate::ReadFloatNumber();
		while(Amount<=0||Amount>Client.getAccountbalance())
		{
			cout << "invaled try Again ";
			Amount = clsInputValidate::ReadFloatNumber();
		}
		char what= 'n';
		cout << "Are you sure this prosess [Y / N]  . ";
		cin >> ws >> what;
		if (what=='y'||what=='Y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "Done . . . ";
			}
			else
			{
				cout << "Don't . .  .";
			}
		}
		else
		{
			cout << "Is Not't this Prosses ! . . .";
		}
		

	}





};

