#pragma once
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsString.h"
#include"clsInputValidate.h"
using namespace std;
class clsCurrencyCalculatorScreen:protected clsScreen
{
private:
	///Show Printtt 
	static void _PrintCurrency(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << " \t Currency Card ." << endl;
			cout << "___________________________________________\n";
			cout << "Country      : " << Currency.Country() << endl;
			cout << "Code         : " << Currency.CurrencyCode() << endl;
			cout << "Name         : " << Currency.CurrencyName() << endl;
			cout << "Rate / (1$)  : " << Currency.Rate() << endl;
			cout << "___________________________________________\n";
		}
		else
		{
			return;
		}
		
		
	}
	
	
	
	static string _ReadCurrencyCode()
	{
		string Code= "";
		Code = clsInputValidate::ReadString();
		return Code;

	}
	static bool IsUSD(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		return(CurrencyCode == "USD");

	}
	static float FromUsd( float RateFrom, clsCurrency Cu1 )
	{
		
		
			return RateFrom * Cu1.Rate();

	
		
	}
	static float ToUsd(  float RatetO, clsCurrency Cu1)
	{
		
		
			return RatetO / Cu1.Rate();
		
	}
public:
		static void ShowcurrencyCalculatorScreen()
		{
			clsScreen::_DrawScreenHeader("  Currency Calculator Screen ");
			char What = 'n';
			do
			{
			
			string Code = "";
			cout << "Enter Code 1 :";
			Code = clsInputValidate::ReadString();
			clsCurrency Cu = clsCurrency::FindByCurrencyCode(Code);
			while (Cu.IsEmpty())
			{
				cout << "try ";
				Code = clsInputValidate::ReadString();
				 Cu = clsCurrency::FindByCurrencyCode(Code);
			}
			cout << Cu.CurrencyCode() << endl;

			cout << "Enter Code 2 :";
			Code = clsInputValidate::ReadString();
			clsCurrency Cu1 = clsCurrency::FindByCurrencyCode(Code);
			while (Cu1.IsEmpty())
			{
				cout << "try ";
				Code = clsInputValidate::ReadString();
				 Cu1 = clsCurrency::FindByCurrencyCode(Code);
			}
			cout << Cu1.CurrencyCode() << endl;
			float Amout = 0.0;
			cout << "Enter A Amount : ";
			Amout = clsInputValidate::ReadFloatNumber();
			if (Cu.CurrencyCode()!=Cu1.CurrencyCode())
			{
				if (!IsUSD(Cu.CurrencyCode()) ,!IsUSD(Cu1.CurrencyCode()) )
				{
					_PrintCurrency(Cu);
					float Doler = ToUsd(Amout ,Cu);
					cout << Amout << " " << Cu.CurrencyCode() << " = " << Doler << " USD " << endl;
					///
					_PrintCurrency(Cu1);
					float Pound = FromUsd(Amout , Cu1);
					cout << Amout << " " << Cu.CurrencyCode() << " = " << Pound << Cu1.CurrencyCode() <<endl;
				}
				else if (IsUSD(Cu.CurrencyCode()) , !IsUSD(Cu1.CurrencyCode()))
				{
					_PrintCurrency(Cu);
					float Pound = FromUsd(Amout, Cu1);
					cout << Amout << " " << Cu.CurrencyCode() << " = " << Pound << Cu1.CurrencyCode() << endl;

				}
				else/// !IsUSD(Cu.CurrencyCode()) , IsUSD(Cu1.CurrencyCode()))
				{
					_PrintCurrency(Cu);
					float Doler = ToUsd(Amout, Cu);
					cout << Amout << " " << Cu.CurrencyCode() << " = " << Doler << " USD " << endl;
				}
			}
			else
			{
				return;
			}

			
			cout << "Are you want Add new [y / n ]";
			cin >> What;

			} while (What=='y'|| What=='Y');

		}

};

	