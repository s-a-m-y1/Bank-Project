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

          
            cout << "\n Enter Currency 1 Code (From): ";
            Code = clsInputValidate::ReadString();
            clsCurrency Cu = clsCurrency::FindByCurrencyCode(Code);
            while (Cu.IsEmpty())
            {
                cout << " Failed operation! Please try again: ";
                Code = clsInputValidate::ReadString();
                Cu = clsCurrency::FindByCurrencyCode(Code);
            }
            cout << " Selected: " << Cu.CurrencyCode() << endl;

        
            cout << "\n Enter Currency 2 Code (To): ";
            Code = clsInputValidate::ReadString();
            clsCurrency Cu1 = clsCurrency::FindByCurrencyCode(Code);
            while (Cu1.IsEmpty())
            {
                cout << " Failed operation! Please try again: ";
                Code = clsInputValidate::ReadString();
                Cu1 = clsCurrency::FindByCurrencyCode(Code);
            }
            cout << " Selected: " << Cu1.CurrencyCode() << endl;

            cout << "\n Enter Amount To Exchange: ";
            float Amount = clsInputValidate::ReadFloatNumberBetween(100.0,10000.0);

            if (Cu.CurrencyCode() != Cu1.CurrencyCode())
            {
               
                float to_Dollar = ToUsd(Amount, Cu);
                float To_TargetCurrency = FromUsd(to_Dollar, Cu1);

                if (IsUSD(Cu1.CurrencyCode()))
                {
                    system("cls");
                    _PrintCurrency(Cu);
                    cout << "\n Result: " << Amount << " " << Cu.CurrencyCode() << " = " << To_TargetCurrency << " USD " << endl;
                }
                else
                {
                    system("cls");
                    _PrintCurrency(Cu);
                    cout << "\n Step 1: " << Amount << " " << Cu.CurrencyCode() << " = " << to_Dollar << " USD " << endl;

                    cout << "\n-----------------------------\n"<<endl;
                    _PrintCurrency(Cu1);
                    cout << " Final Result: " << Amount << " " << Cu.CurrencyCode() << " = " << To_TargetCurrency << " " << Cu1.CurrencyCode()  << endl;
                }
            }
            else
            {
                cout << "\n Both currencies are the same. No conversion needed! \n";
              
            }

            cout << "\n Do you want to perform another exchange? [y/n]: ";
            cin >> What;

        } while (What == 'y' || What == 'Y');

        cout << "\n Thank you for using our Currency Converter! See you soon! \n";
    }   

};
        