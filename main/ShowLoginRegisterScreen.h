#pragma once
#include<iostream>
#include"Global.h"
#include"clsUser.h"
#include"clsScreen.h"
#include <iomanip>
using namespace std;
class ShowLoginRegisterScreen :protected clsScreen
{
private:
	static void _PrintHeader(const  clsUser::StDataLoginRegister& User)
	{
		cout << "\t| " << setw(30) << left << User.Date;
		cout << "\t| " << setw(25) << left << User.Username;
		cout << "\t| " << setw(15) << left << User.Password;
		cout << "\t| " << setw(15) << left << User.permissions;


	}
public:
	static void Header()
	{
		///this is Header
		
		vector<clsUser::StDataLoginRegister>Vuser = clsUser::LoadDataFromFIle();
		string Title = "\tRegister Screen ";
		string sub = " Users : ( " + to_string(Vuser.size()) + " ) (U) ";
		clsScreen::_DrawScreenHeader(Title, sub);
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t| " << setw(30) << left << "Date \ Time ";
		cout << "\t| " << setw(25) << left << "UserName";
		cout << "\t| " << setw(15) << left << "Password";
		cout << "\t| " << setw(15) << left << "permissions";
		cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (Vuser.size()==0)
		{
			cout << "This Empty (:" << endl;
		}
		else
		{



			for (clsUser::StDataLoginRegister& R : Vuser)
			{
				_PrintHeader(R);
				cout << endl;
			}
			cout << setw(8) << left << "" << "\n\t__________________________________________________________________";
			cout << "_________________________________________\n" << endl;
		}
	}



};

