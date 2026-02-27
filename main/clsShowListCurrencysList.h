#pragma once
#include"clsCurrency.h"
#include"clsScreen.h"
#include<iostream>
#include<vector>
#include<iomanip>
#include<windows.h>
class clsShowListCurrencysList :protected clsScreen
{
private:
	static void _Print(clsCurrency Currency)
	{
		cout << setw(30) << left << Currency.Country();
		cout << setw(10) << left << Currency.CurrencyCode();
		cout << setw(35) << left << Currency.CurrencyName();
		cout << setw(20) << left << Currency.Rate();


	}
public:
	static void ShowListCurrencysScreen()
	{
		vector<clsCurrency>VCurrencies = clsCurrency::GetAllUSDRates();
		string Title = "\t    List of Currencys Screen";
		string SubTitle = "(" + to_string(VCurrencies.size()) + ") Currency(s).";
		clsScreen::_DrawScreenHeader(Title ,SubTitle);
		cout << "\n=====================================================================================================================\n";
		cout << setw(30) << left << "Country";
		cout << setw(10) << left << "Code";
		cout << setw(35) << left << "Currency Name";
		cout << setw(20) << left << "Rate Vs USD";
		cout << "\n=====================================================================================================================\n";
		for (clsCurrency& C : VCurrencies)
		{
			_Print(C);
			cout << endl;
		}
		cout << "\n=====================================================================================================================\n";
	}

};


