#pragma once
#include "clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsDeleteClientScreen :protected clsScreen
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
	static void ShowDeleteClientScreen()
	{
		if (!clsScreen::_AccesPermissionDenied(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}
		_DrawScreenHeader("\t\tDelete Client Screen");

		cout << "Please enter Accountnumber ? " ;
		string Accountnumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsclientExist(Accountnumber))
		{
			cout << "Invaled Account number try again :-) ? ";
			Accountnumber = clsInputValidate::ReadString();
		}

		clsBankClient client = clsBankClient::Find(Accountnumber);
		_printClient(client);

		cout << "Are You sure Delete This Client ? ";
		char What = 'n';
		cin >> ws >> What;

		if (What=='y'||What=='Y')
		{
			if (client.Delete(Accountnumber))
			{
				cout << "\nUser Deleted Successfully :-)\n";
				_printClient(client);

			}
			else
			{
				cout << "\nError User Was not Deleted\n";
			}
		}
		
	}
};