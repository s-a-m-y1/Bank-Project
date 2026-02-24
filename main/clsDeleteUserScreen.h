#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iostream>
#include"clsUser.h"
using namespace std;
class clsDeleteUserScreen :protected clsScreen
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

    static void DeleteUsersScreen()
    {
        clsScreen::_DrawScreenHeader("\t  Delete User Screen");
        string UserName = "";
        cout << "Enter UserName : ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "Sorry UserName is not exist, Enter another one : ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        clsUser::enSaveResults DeleteResult;
        DeleteResult = User.Save();//this is variable to save the result of delete process to know if it is success or not 

        char Answer = 'n';
        cout << "Are you sure you want to delete this user? y/n? ";
        cin >> ws >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
        
			if (User.Delete())//this is hold on this object to delete it and return true if it is deleted successfully
            {
				cout << "User Deleted Successfully :-)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "Failed to delete user :-(\n";
            }
            
        }
        else
        {
			cout << "Don't delete user :-(\n";
        }
    }

};