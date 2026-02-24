#pragma once
#include"clsScreen.h"
#include <iomanip>
#include"clsInputValidate.h"
#include"clsAddNewUserScreen.h"
#include"clsListUsersScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
#include<iostream>
using namespace  std;
class clsManageUsersScreen:protected clsScreen
{
private:
	enum EnmanageUsersOpthion{ eListUser =1 , eAddNewUser =2 , eDeleteUser =3 , eUpdateUser =4  ,eFindUser =5 ,eMainScreen =6 };
	static short _ReadMainScreen()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Chose = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6?");
		return Chose;
	}
	static void _GoBackToManageUsersMenue()
	{
		cout << "\n\nPress any key to go back to Manage Users Menue...";
		system("pause>0");
		ShowManageUsersMenue();
	}
	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}
	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::DeleteUsersScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUsersScreen()
	{
		clsFindUserScreen::FindUserScreen();
	}

	static void _ShowMainMenu()
	{
		return;
	}

	static void _Performopthon(EnmanageUsersOpthion Choose)
	{
		switch (Choose)
		{
		case EnmanageUsersOpthion::eListUser:
			{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			}
		case EnmanageUsersOpthion::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
		}
		case EnmanageUsersOpthion::eDeleteUser :
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
		}
		case EnmanageUsersOpthion::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
		}
		case EnmanageUsersOpthion::eFindUser:
		{
			system("cls");
			_ShowFindUsersScreen();
			_GoBackToManageUsersMenue();
		}
		case EnmanageUsersOpthion::eMainScreen:
		{
			system("cls");
			_ShowMainMenu();
			_GoBackToManageUsersMenue();
		}


		}
	}
public:
	static void ShowManageUsersMenue()
	{
		if (!clsScreen::_AccesPermissionDenied(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_Performopthon((EnmanageUsersOpthion)_ReadMainScreen());

	}
};

