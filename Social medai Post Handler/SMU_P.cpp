#include<string>
#include"SM_U_P.h"
using namespace std;

inline string SMUserPost::get_US_ID() const{
	return User_ID;
}

inline string SMUserPost::get_P_text()const{
	return P_text;
}

inline Date SMUserPost::get_Date() const
{
	return DOP;
}

inline SMUserPost::PostTime SMUserPost::get_TOP() const
{
	return TOP;
}

inline void SMUserPost::set_US_ID(const string& obj){
	if (obj.empty())
	{
		throw "User's ID Cannot be Blank";
	}
	User_ID = obj;
}

inline void SMUserPost::set_P_text(const string& obj) {
	if (obj.empty())
	{
		throw "Post's Text Cannot be Blank";
	}
	P_text = obj;
}

inline void SMUserPost::Display()
{
	cout << User_ID << "\t" << DOP << "\t" << setfill('0') << setw(2) << TOP.HH << ":"<< setfill('0') << setw(2) << TOP.MM << ":" << setw(2) << TOP.SS << "\t" << P_text << endl;
}