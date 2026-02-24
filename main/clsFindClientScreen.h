#include<iostream>
#pragma	once
#include"clsBankClient.h" 
#include"clsInputValidate.h"
#include"clsScreen.h"
using namespace std;
class clsFindClientScreen : protected clsScreen
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

		static void ShowFindeScreen()
		{
			if (!clsScreen::_AccesPermissionDenied(clsUser::enPermissions::pFindClient))
			{
				return;
			}
			clsScreen::_DrawScreenHeader("\tFind Client Screen ");
			string Accountnumber = "";
			
			cout << "please Enter Account Number ? ";
			Accountnumber = clsInputValidate::ReadString();
			while (!clsBankClient::IsclientExist(Accountnumber))
			{
				  cout << "Invalid account number, try again: ";
				Accountnumber = clsInputValidate::ReadString();
			}
			clsBankClient client = clsBankClient::Find(Accountnumber);
			_printClient(client);
			

	  }


	};