#pragma once
#include"clsCurrency.h"
#include"clsScreen.h"
#include<iostream>
#include<vector>
#include<iomanip>
class clsShowListCurrencysList :protected clsScreen
{
private:
    static void _PrintUserRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " <<setw(30) << left << Currency.Country();
        cout << "| " << setw(12) << left << Currency.CurrencyCode();
        cout << "| " << setw(40) << left << Currency.CurrencyName();
        cout << "| " << setw(12) << left << Currency.Rate();

    }
private:
   
public:

    static void ShowCurrencysList()
   {
      vector <clsCurrency> vC = clsCurrency::ListCurrency();

      string Title = "  currencys List Screen";
       string SubTitle = "\t    (" + to_string(vC.size()) + ")";

     _DrawScreenHeader(Title, SubTitle);

     cout << setw(8) << left << "" << "\n\t_______________________________________________________";
       cout << "______________________________________________\n" << endl;

       cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
      cout << "| " << left << setw(12) << "Code ";
       cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(12) << "Rate/(1$)";
     
    cout << setw(8) << left << "" << "\n\t_______________________________________________________";
      cout << "______________________________________________\n" << endl;
      if (vC.size()==0)
      {
          cout << "\t\t\t\tNo Users Available In the System!";
      }
      
       else

          for (clsCurrency Currency : vC)
           {

             
             _PrintUserRecordLine(Currency);
             cout << endl;
           }

       cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }

  
};


