#include<iostream>
#include<string>
#include<fstream>
#include"clsString.h"
#include"clsPerson.h"
#pragma once
using namespace std;	
class clsBankClient:public clsPerson
{
private:
	enum enMode{ eEmptyMode =0
	 , eUpdateMode =1};
	enMode Mode;
	string _Accountnumber = "";
	string _Pincode = "";
	float _Accountbalance = 0.0;
	static clsBankClient _ConvertEmptyLine()
	{
		return clsBankClient(enMode::eEmptyMode, "", "", "", "", "", "", 0.0);
	}
	static clsBankClient _ConvertLineObject(string Line  , string Spretor ="#//#")//This is Method but this to return data mebers for constractor 
	{
		vector <string> SplitLine = clsString::Split(Line, Spretor);
		if (SplitLine.size()>=7)
		{
	
			return clsBankClient(enMode::eUpdateMode,
				SplitLine[0],//firstname
				SplitLine[1],//lastname
				SplitLine[2],//Email
				SplitLine[3],//Phone
				SplitLine[4],//Accountnumber
				SplitLine[5],//pincode
				stof(SplitLine[6])//Accountbalance 
			);
		}
		   else
	{
		return	_ConvertEmptyLine();// Empty 
		}

	}
	static string _convertLinerecord(clsBankClient Client , string spretor = "#//#") // this is Asghar line
	{
		string Line = "";
		Line += Client.FirstName + spretor;
		Line += Client.LastName + spretor;
		Line += Client.Email + spretor;
		Line += Client.Phone + spretor;
		Line += Client.FullName() + spretor;
		Line += Client.Accoountnumber() + spretor;
		Line += Client.pincode + spretor;
		Line += to_string( Client.Accountbalance());


	}
	public:
		bool IsEmpty()
		{
			return(Mode == enMode::eEmptyMode); // this is Check on The object if he Empty Or Not  ! ///
		}
		bool IsUpdatemode()
		{
			return (Mode == enMode::eUpdateMode);
		}
		clsBankClient(enMode mode, string firstname  , string lastname , string Email  ,string Phone , string Accountnumber , string pincode  ,float Accountbalance  ):clsPerson(firstname , lastname , Email ,Phone)
		{
			_Accountnumber = Accountnumber;
			_Pincode = pincode;
			_Accountbalance = Accountbalance;
		}
		
		string Accoountnumber()
		{
			return _Accountnumber;
		}
		void setPincode(string Pincode)
		{
			_Pincode = Pincode;

		}
		string Pincode()
		{
			return _Pincode;
		}
		__declspec(property(get = Pincode, put = setPincode)) string pincode;
		void setAccountBalance(float Accoutnbalce)
		{
			_Accountbalance = Accoutnbalce;

		}
		float Accountbalance()
		{
			return _Accountbalance;
		}
		__declspec(property(get = Accountbalance, put = setAccountBalance)) float Accountbalance;

		static clsBankClient Find(string Account )
		{
			fstream load;
			//vector<clsBankClient>VClient;
			load.open("CLient.txt", ios::in);
				if (load.is_open())
				{
					string Line = "";
					while (getline(load , Line))
					{
						clsBankClient client = _ConvertLineObject(Line);
						if (Account == client.Accoountnumber())
						{
							load.close();
							return client;

						}
						//VClient.push_back(client);
					}
					load.close();
				}
				
				return  _ConvertEmptyLine();
		}


		static clsBankClient Find(string Account , string Pincode )
		{
			fstream load;
			//vector<clsBankClient>VClient;
			load.open("CLient.txt", ios::in);
			if (load.is_open())
			{
				string Line = "";
				while (getline(load, Line))
				{
					clsBankClient client = _ConvertLineObject(Line);
					if (Account == client.Accoountnumber() && Pincode==client.pincode)
					{
						load.close();
						return client;

					}
					//VClient.push_back(client);
				}
				load.close();
			}

			return  _ConvertEmptyLine();
		}


 };