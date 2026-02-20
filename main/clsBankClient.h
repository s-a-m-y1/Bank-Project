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
	 , eUpdateMode =1 , eAddnewMode = 2 };
	enMode Mode;
	string _Accountnumber = "";
	string _Pincode = "";
	float _Accountbalance = 0.0;
	bool MarkForDelete = false;
	static clsBankClient _ConvertEmptyLine()
	{
		return clsBankClient(enMode::eEmptyMode, "", "", "", "", "", "", 0.0);
	}
	static clsBankClient _ConvertLineObject(string Line  , string Spretor ="#")//This is Method but this to return data mebers for constractor 
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
	static string _convertLinerecord(clsBankClient Client , string spretor ="#") // this is Asghar line
	{
		string Line = "";
		Line += Client.FirstName + spretor;
		Line += Client.LastName + spretor;
		Line += Client.Email + spretor;
		Line += Client.Phone + spretor;
		Line += Client.FullName() + spretor;
		Line += Client.Accoountnumber() + spretor;
		Line += Client.pincode + spretor;
		Line += to_string( Client.getAccountbalance());

		return Line;
	}
	static vector<clsBankClient>_LoaddataFromFile()
	{
		fstream loading;
		vector<clsBankClient>VClient;
		loading.open("Client.txt", ios::in);
		string line = "";
		if (loading.is_open())
		{
			while (getline(loading, line))
			{
				VClient.push_back(_ConvertLineObject(line));
			}
	     	loading.close();
		}
		return VClient;
	}
	static void _saveDataToFile(vector<clsBankClient>&Vclient )
	{
		fstream LoadNew;
		LoadNew.open("Client.txt", ios::out);
		if (LoadNew.is_open())
		{
			for (clsBankClient& C : Vclient)
			{
				if (C.MarkForDelete==false)
				{
					LoadNew << _convertLinerecord(C) << endl;

				}

			}
			LoadNew.close();
		}

	}
	static bool Markthisclient (string CAccountnumber )
	{
		fstream NewL;
		vector<clsBankClient> Vclients = _LoaddataFromFile();
		for (clsBankClient& C : Vclients) 
		{
			if (CAccountnumber == C.Accoountnumber()) // This  Efects on the Vector of data currntly 
			{
				C.MarkForDelete = true;
				_saveDataToFile(Vclients);
				return true;
			}
		}
		return false;
	}
      void _Update()
    {
        //here client this///
        vector<clsBankClient>Vclient;
        Vclient = _LoaddataFromFile();
        for (clsBankClient& C : Vclient)
        {
            if (C.Accoountnumber() == Accoountnumber())
            {
                C = (*this);
                break;
            }
        }
         _saveDataToFile(Vclient);
    }

     void _AddClietnToFile(string Line ="")
     {
         fstream Add;
         Add.open("Client.txt", ios::app | ios::out);
         if (Add.is_open())
         {
             Add << Line << endl;
             Add.close();
         }
     }
     void _AddLIne()
     {
         _AddClietnToFile(_convertLinerecord (*this));
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
		float getAccountbalance()
		{
			return _Accountbalance;
		}
		__declspec(property(get = getAccountbalance, put = setAccountBalance)) float Accountbalance;

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
		enum enSaveResult { svFaildEmptyObject = 0, svSucceeded =1 , svAccountnumberExsist = 2  };

	 enSaveResult SaveResult( )
		{
		switch (Mode)
		{
		case enMode::eEmptyMode: 
		{
			return svFaildEmptyObject;
		}
		
		case  enMode::eUpdateMode:
		{
			_Update();
			return svSucceeded;
		}
			
		case enMode::eAddnewMode:
		{
			if (clsBankClient::IsclientExist(Accoountnumber()))//This is Check on The Account Number this object ///
			{
			return	svAccountnumberExsist;
			}
			else
			{
				_AddLIne();//this Method she pass *this pintnter :-)/
				Mode = enMode::eUpdateMode;//here edit mode after edit 
				return svSucceeded;
			}
		}
		default:
	
			return svFaildEmptyObject;
		}

		}
	 static bool IsclientExist(string Acountnumer)
	 {
		 clsBankClient Client = clsBankClient::Find(Acountnumer);
		 return(!Client.IsEmpty());
	 }
	 static clsBankClient GetAddnewclient(string Accountnumber)
	 {
		 return clsBankClient( enMode::eAddnewMode,"", "", "", "", Accountnumber, "", 0.0);

	 }
	 bool Delete(string Accountnumber)
	 {
		 vector<clsBankClient>Vclient = _LoaddataFromFile();
		 for (clsBankClient& C : Vclient)
		 {
			 if (Accountnumber == C.Accoountnumber())// what this->Accoountnumber()
			 {
				 C.MarkForDelete = true;
				 break;

			 }

		 }
		 _saveDataToFile(Vclient);
		 *this = _ConvertEmptyLine();
		 return true;
	 }
	 static vector< clsBankClient> GetClientList()
	 {
		 
		
		 return  _LoaddataFromFile();
		 

	 }
	 static float GetTotalbakances()
	 {
		 vector <clsBankClient>VBal = clsBankClient::GetClientList();
		 float Total = 0.0;
		 for (clsBankClient& C : VBal)
		 {
			 Total += C.Accountbalance;
		 }
		 return Total;
	 }
 };