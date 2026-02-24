#pragma once
#include"clsUser.h"
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsFindUserScreen :protected clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";
	}
public:
	static void FindUserScreen ()
	{
		clsScreen::_DrawScreenHeader("\t  Find User Screen");	
		string UserName = "";	
		cout << "Enter Username : ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "Sorry UserName is not exist, Enter another one : ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

	}

};

