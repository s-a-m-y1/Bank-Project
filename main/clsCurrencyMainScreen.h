#pragma once
#include<iostream>
#include<vector>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsCurrencyMainScreen:protected clsScreen
{
private:
	enum enCurrencys
	{
		eShowListCurrencys = 1, eFindCurrency=2 ,CurrencyClaulator=3, eUpdateRate = 4,  eMainMenue = 5

	};
	
	static short _ReadCurrencyMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		return clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number Between 1 and 5 : ");
	}

	static void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowCurrencyMainScreen();
	}
	static void _ShowListCurrencysScreen()
	{

		cout << "\nList of Currencys Will be here...\n";
	}
	static void _showFindCrrencyScreen ()
	{

		cout << "\nUPdate of Currencys Will be here...\n";
	}
	static void _ShowCurrencyCulacukatorScreen()
	{

		cout << "\nList of Currencys Will be here...\n";
	}
	static void _ShowUpdateRateScreen()
	{

		cout << "\nList of Currencys Will be here...\n";
	}
	static void _ShowMainMenuScreen()
	{

		cout << "\nList of Currencys Will be here...\n";
	}

	static void _AssmebleCurrencys(enCurrencys Currency )
	{
		switch (Currency)
		{
		case clsCurrencyMainScreen::eShowListCurrencys:
			system("cls");
			_ShowListCurrencysScreen();
			_GoBackToMainMenue();
			break;
		case clsCurrencyMainScreen::eFindCurrency:
			system("cls");
			_showFindCrrencyScreen();
			_GoBackToMainMenue();
			break;
		case clsCurrencyMainScreen::CurrencyClaulator:
			system("cls");
			_ShowCurrencyCulacukatorScreen();
			_GoBackToMainMenue();
			break;	
		case clsCurrencyMainScreen::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToMainMenue();	
			break;
		case clsCurrencyMainScreen::eMainMenue:
			system("cls");
			_ShowMainMenuScreen();
			break;
		default:
			break;
		}

	}

public:
	static void ShowCurrencyMainScreen()
	{
		system("cls");
		_DrawScreenHeader("\tCurrrency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrrency Exchange Main Screen\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Currencys List.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency .\n";
		cout << setw(37) << left << "" << "\t[3]  Update Rate .\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calulator   .\n";
		cout << setw(37) << left << "" << "\t[5] Main Screen .\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_AssmebleCurrencys((enCurrencys)_ReadCurrencyMainMenueOption());

	}


};

