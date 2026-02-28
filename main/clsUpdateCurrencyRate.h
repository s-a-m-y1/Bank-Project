#pragma once
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include<iostream>
using namespace std;
class clsUpdateCurrencyRate :protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << " \t Currency Card ." << endl;
		cout << "___________________________________________\n";
		cout << "Country      : " << Currency.Country() << endl;
		cout << "Code         : " << Currency.CurrencyCode() << endl;
		cout << "Name         : " << Currency.CurrencyName() << endl;
		cout << "Rate / (1$)  : " << Currency.Rate() << endl;
		cout << "___________________________________________\n";
	}

public:
	static void ShowUpdateScreen()
	{
		clsScreen::_DrawScreenHeader("   Update Screen ");
		string Input = "";
		
		cout << "\n\nPlsese Enter A Currency Code : ";
		Input = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCurrencyCode(Input);
		while (Currency.IsEmpty())
		{
			cout << "please Enter Currency Code : ";
			Input = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCurrencyCode(Input);
		}
		_PrintCurrency(Currency);
		char what = 'n';
		cout << "Do you want update currency [Y / N ]:";
		cin >> ws >> what;
		if (what=='y'||what=='Y')
		{
			float NewRate = 0.0;
			cout << " Update Currency Rate . " << endl;
			cout << "____________________" << endl;
			cout << "New Rate : ";
			NewRate = clsInputValidate::ReadFloatNumberBetween(0.0, 100000.0);

			Currency.UpdateRate(NewRate);

			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nUpdate Cancelled.\n";
		}


	}

};

