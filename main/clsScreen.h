#pragma once
#include "clsUser.h"
#include "clsDate.h"
#include"Global.h"
#include <iostream>


using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\tUser : " << CurrentUser.UserName << endl;
		clsDate Date = clsDate::GetSystemDate();
		cout << "\t\t\t\t\tDate : " << Date.GetDay() << "/" << Date.GetMonth() << "/" << Date.GetYear() << endl;

    }

    static bool _AccesPermissionDenied(clsUser::enPermissions Perm)
    {
        if (!CurrentUser.CheckAccessRights(Perm))
        {

            cout << "\t\t\t\t\t_______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }

	


};

