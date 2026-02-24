#pragma once
#include"clsUser.h"
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsUpdateUserScreen :protected clsScreen
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

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        return Permissions;

    }

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();
        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();
        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();
        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();
        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();
        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
	}

public:
    static void ShowUpdateUserScreen()
    {
        clsScreen::_DrawScreenHeader ("\t  Update User Screen");
        string UserName = "";
        cout << "Enter UserName : ";
        cin >> UserName;
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "Sorry UserName is not exist, Enter another one : ";
            cin >> UserName;
        }
        clsUser User = clsUser::Find(UserName);
            _PrintUser(User);
        //here we will read new data for this user and update it 
			char Answer = 'n';
			cout << "Are you sure you want to update this user? y/n? ";
			cin >> ws >> Answer;
            if (Answer=='Y'||Answer=='y')
            {
                _ReadUserInfo(User);
				clsUser::enSaveResults UpdateResult;
				UpdateResult = User.Save();
                switch (UpdateResult)
                {   
                case clsUser::svSucceeded:
					cout << " User Updated Successfully :-)\n";
                    _PrintUser(User);

                    break;
                case clsUser::svFaildEmptyObject:
					cout << "Failed to update user because the user data is empty :-(\n";
                    break;
                case clsUser::svFaildUserExists:
					cout << "Invalid user data, UserName is already exist, try another one :-(\n";
                    break;
                default:
					cout << "Error: Unhandled case in switch statement.\n";
                    break;
                }

            }
	}

};

