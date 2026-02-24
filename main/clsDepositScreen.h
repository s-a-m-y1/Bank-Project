#pragma once
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;
class clsDepositScreen :protected clsScreen
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
	static void DepositScreen()
	{
		clsScreen::_DrawScreenHeader("\t\tDeposit Screen");
		string Accountnumber = "";
		cout << "Please enter Accountnumber ? ";
		Accountnumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsclientExist(Accountnumber))
		{
			cout << "Sorry, Invaled Account number try again :-) ? ";
			Accountnumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(Accountnumber);
		_printClient(Client);
		///____________________///
		
		float Amount = 0.0;
		cout << "Enter Amount to Deposit ? ";
		Amount = clsInputValidate::ReadFloatNumber();
		while (Amount <= 0)
		{
			cout << "PLease Enter Amount Greater than 0 ? ";
			Amount = clsInputValidate::ReadFloatNumber();
		}

		char what = 'n';
		cout << "Are you sure this Amoount [Y / N] ? ";
		cin >> ws >> what;
		if (what == 'Y' || what == 'y')
		{
			Client.Deposit(Amount);
		}
		else
		{
			cout << "Don't optethon . . . "<<endl;
		}
		
		
		
	}
};

