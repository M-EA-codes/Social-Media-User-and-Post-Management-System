#pragma once
#include"Dat.h"
using namespace std;

class SMUser
{
	string User_ID;
	string User_F_Name;
	string User_L_Name;
	Date DOM;
public:
	SMUser(string uid = "", string UFN = "", string ULN = "", int dd = 1, int mm = 1, int yyyy = 1)//:DOM(dd, mm, yyyy)
	{
		set_U_ID(uid);
		set_F_Name(UFN);
		set_L_Name(ULN);
		DOM.setDay(dd);
		DOM.setMonth(mm);
		DOM.setYear(yyyy);
	}
	
	//Prototypes of Mutators are defined below:
	inline void set_U_ID(const string& obj);
	inline void set_F_Name(const string& obj);
	inline void set_L_Name(const string& obj);
	
	//Prototypes of Accessors are defined below:
	inline string get_U_ID()const;
	inline string get_F_Name()const;
	inline string get_L_Name()const;

	//For Display
	inline void Display();
};