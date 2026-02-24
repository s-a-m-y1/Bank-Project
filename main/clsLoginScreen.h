#pragma once
#include"Global.h"
#include"clsScreen.h"
#include"clsMainscreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"	
using namespace std;
class clsLoginScreen:protected clsScreen
{

private:
	static bool _Login()
	{
		bool LoginFailed = false;//this variable to know if login failed or not to show message
		short Logins = 3;
		string
			UserName = "",
			Password = "";
		do
		{
			if (LoginFailed&&Logins!=0)//this is true if login failed to show message
			{
			
				Logins--;//decrease logins by 1
				system("cls");
				cout << "________________):_____________" << endl;
				cout << "invalid login username/password \n";
				cout << "You have " << Logins << " trials to login : " << endl;
				cout << "_______________^_^____________" << endl;
			}
			if (Logins==0)
			{
				cout << "\n________________________________" << endl;
				cout << "Sorry You've run out of adapters  Please Try again  ^_^  " << endl;
				cout << "\n________________________________" << endl;
				return false;
			}


			cout << "Enter Username : ";
			UserName = clsInputValidate::ReadString();

			cout << "Enter Password : ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);//this will return user object if found or empty user object if not found
			LoginFailed = CurrentUser.IsEmpty();//if user is empty this means login failed to return true if login failed to show message
		} while (LoginFailed);//This Is true If Login Failed
		CurrentUser.AddLoginRegister();
		clsMainScreen::ShowMainMenue();
     
		return true;
	}
public:
	static bool ShowLoginScreen()//THIS IS PUBLIC FUNCTION TO SHOW LOGIN SCREEN THI IS NEME ABSTRACTED FROM PRIVATE FUNCTION TO BE CALLED IN MAIN
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return(_Login());
	}
};/// :-)

