#pragma once
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsAddNewClientScreen.h"
#include<iostream>
using namespace std;
class clsFindCurrency :protected clsScreen
{

private:
	enum EnCases
	{
		FCurrencyCode=1 , FCountry=2

	};
	EnCases En;
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "___________________________________________\n";
		cout << "Country      : " << Currency.Country()<<endl;
		cout << "Code         : " << Currency.CurrencyCode()<<endl;
		cout << "Name         : " << Currency.CurrencyName()<<endl;
		cout << "Rate / (1$)  : " << Currency.Rate()<<endl;
		cout << "___________________________________________\n";
	}
	static short _Choice()
	{
		short Choice=0;
		cout << "\n (: Find By : Code [1] OR [2] Country ? ";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 2);
		return Choice;
	}
	static void _Print(clsCurrency&Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "Is Found :) " << endl;
			_PrintCurrency(Currency);

		}
		else
		{
			cout << "Is Not Found :( " << endl;
			return;
		}
		
	}
public:
	static void ShowFindScreen()
	{
		clsScreen::_DrawScreenHeader("   Find Currency Screen");
		short Choice = _Choice();//this is To Choice Find By Code Or Country
		string Input = "";




		if (Choice == 1)
		{
			cout << "\n\nPlsese Enter A Currency Code : ";
			Input = clsInputValidate::ReadString();

			clsCurrency Currency1 = clsCurrency::FindByCurrencyCode(Input);
			_Print(Currency1);
		}
		else if (Choice==2)
      	{
			cout << "\nPlsese Enter A  Country : ";
			Input = clsInputValidate::ReadString();
			clsCurrency Currency2 = clsCurrency::FindByCurnert(Input);
			_Print(Currency2);
		}
		else
		{
			return;
		}
			
	}
};

