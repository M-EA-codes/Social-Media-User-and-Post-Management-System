#pragma once
#include"Dat.h"
using namespace std;

class SMUserPost
{
	string User_ID;
	Date DOP;
	struct PostTime
	{
		int HH;
		int MM;
		int SS;
		PostTime(int h = 1, int m = 1, int s = 1) :HH(h), MM(m), SS(s) {}
	};
	PostTime TOP;
	string P_text;
public:
	SMUserPost(string uid = "", int day = 1, int month = 1, int year = 1, int h = 1, int m = 1, int s = 1, string p_text = "") :TOP(h, m, s)//,DOP(day, month, year)
	{
		set_US_ID(uid);
		set_P_text(p_text);
		DOP.setDay(day);
		DOP.setMonth(month);
		DOP.setYear(year);
	}


	//Prototypes of Accessors are defined below:
	inline string get_US_ID()const;
	inline string get_P_text()const;
	inline Date get_Date()const;
	inline PostTime get_TOP()const;

	//Prototypes of Mutators are defined below:
	inline void set_US_ID(const string& obj);
	inline void set_P_text(const string& obj);

	inline void Display();
};