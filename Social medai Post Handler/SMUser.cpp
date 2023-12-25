#include<string>
#include"SM_User.h"
using namespace std;


//Implementation of Mutators are given below:
inline void SMUser::set_U_ID(const string& obj)
{
	if (obj.empty())
	{
		throw "User's ID Cannot be Blank";
	}
	User_ID = obj;
}

inline void SMUser::set_F_Name(const string& obj)
{
	if (obj.empty())
	{
		throw "User's First Name Cannot be Blank";
	}
	User_F_Name = obj;
}
inline void SMUser::set_L_Name(const string& obj)
{
	if (obj.empty())
	{
		throw "User's Last Name Cannot be Blank";
	}
	User_L_Name = obj;
}

//Implementation of Accessors are given below:
inline string SMUser::get_U_ID() const {
	return User_ID;
}

inline string SMUser::get_F_Name() const {
	return User_F_Name;
}

inline string SMUser::get_L_Name() const {
	return User_L_Name;
}

inline void SMUser::Display()
{
	cout << User_ID << "\t" << User_F_Name;
	
	if (User_ID.length() <= 7)
	{
		cout << "\t\t" << User_L_Name << "\t\t" << DOM;
	}
	else
	{
		cout << User_L_Name << "\t\t" << DOM;
	}
}