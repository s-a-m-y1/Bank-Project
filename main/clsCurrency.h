#pragma once
#include"clsString.h"
#include<string>
#include<fstream>
using namespace std;
#include<iostream>
class clsCurrency
{
private:
	enum _enMoode {EmptyMode =1 , UpdateMode =2 };
	_enMoode _Mode;
	string _Country = "";
	string _CurrencyCode = "";
	string _CurrencyName = "";
	float _Rate = 0.0;
	///
	static clsCurrency _ConvertCurrencyLine(string Line, string spretor = "#//#")
	{
		vector<string> VFilter = clsString::Split(Line, spretor);

	
		if (VFilter.size() >= 4)
		{
			return clsCurrency(_enMoode::UpdateMode,
				VFilter[0],   // Country
				VFilter[1],   // Code
				VFilter[2],   // Name
				stod(VFilter[3])); 
		}
		else
		{
			return _ConvertemptyCurrency();
		}
	}
	static clsCurrency _ConvertemptyCurrency()///This Mode Empty  
	{
		return clsCurrency(_enMoode::EmptyMode, "", "", "", 0.0);
	}
static	vector<clsCurrency> LoadCurrencysDataFromFile()
	{
		fstream Load;
		vector<clsCurrency>VCurrencies;
		Load.open("Currencies.txt", ios::in);
		if (Load.is_open())
		{
			string Line = "";
			while (getline(Load , Line))
			{

				VCurrencies.push_back(_ConvertCurrencyLine(Line));///this is Push Back One Line To Object ///

			}
			///End
			Load.close();
		}
		return VCurrencies;
	}
static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
{

	string stCurrencyRecord = "";
	stCurrencyRecord += Currency.Country() + Seperator;
	stCurrencyRecord += Currency.CurrencyCode() + Seperator;
	stCurrencyRecord += Currency.CurrencyName() + Seperator;
	stCurrencyRecord += to_string(Currency.Rate());

	return stCurrencyRecord;

}
static void SaveurrencysDataTOFile(vector<clsCurrency>&VCurrency)///By &
{
	fstream OverWrite;
	OverWrite.open("Currencies.txt", ios::out);
	if (OverWrite.is_open())
	{
		for (clsCurrency& C : VCurrency)
		{
			OverWrite << _ConverCurrencyObjectToLine(C) << endl;/// this is Line Push To File /

		}
		OverWrite.close();

	}
}
 void _Update()
{
	 vector<clsCurrency>VUpdate = LoadCurrencysDataFromFile();
	 for (clsCurrency& C : VUpdate)
	 {
		 if (C.CurrencyCode() == CurrencyCode())
		 {
			 C = *this;
			 break;///here Break Update One Only
		 }

	 }
	 SaveurrencysDataTOFile(VUpdate);
}
public:
	void UpdateRate(float Rate)
	{
		_Rate = Rate;
		_Update();
	}
	bool IsEmpty()
	{
		return(_Mode == _enMoode::EmptyMode);
	}
	static vector <clsCurrency> GetAllUSDRates()
	{

		return LoadCurrencysDataFromFile();

	}

	clsCurrency( _enMoode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}


	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	float  Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCurrencyCode(string currncyCode)
	{
		currncyCode = clsString::UpperAllString(currncyCode);// This is To Upper Case /
		fstream Load;
		Load.open("Currencies.txt", ios::in);
		if (Load.is_open())
		{
			string line = "";
			while ( getline (Load , line) )
			{
				clsCurrency CurrenctObj = _ConvertCurrencyLine(line);
				if (clsString::UpperAllString(CurrenctObj.CurrencyCode())== currncyCode)
				{
					Load.close();
					return CurrenctObj;
				}
			}///End
			Load.close();

		}
		return _ConvertemptyCurrency();

	}
	static clsCurrency FindByCurnert(string currncy)
	{
		currncy = clsString::UpperAllString(currncy);// This is To Upper Case /
		fstream Load;
		Load.open("Currencies.txt", ios::in);
		if (Load.is_open())
		{
			string line = "";
			while (getline(Load, line))
			{
				clsCurrency Countery = _ConvertCurrencyLine(line);
				if (clsString::UpperAllString(Countery.Country()) == currncy)
				{
					Load.close();
					return Countery;
				}
			}///End
			Load.close();

		}
		return _ConvertemptyCurrency();

	}

	static 	bool ISCurrencyExist(string cuntery)
	{
		clsCurrency Currency = clsCurrency::FindByCurnert(cuntery);
		return(Currency.IsEmpty());

    }
	static vector<clsCurrency>ListCurrency()
	{
		return LoadCurrencysDataFromFile();
	}


};

