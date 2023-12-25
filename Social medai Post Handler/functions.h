#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include"SMUser.cpp"
#include"SMU_P.cpp"
using namespace std;

void intialize_map(string filename, map<int, SMUser>& SMU)
{
	int users = 0;
	ifstream inFile;
	inFile.open(filename);
	string line, d, m, y, userid, UFN, ULN;

	if (inFile.is_open()) {
		// Loop through each line of the file and count the number of users
	   /* while (getline(inFile, line)) {
			users++;
			data = line.substr(0, 6);
		}*/

		while (getline(inFile, line)) {
			int i = 0;
			userid = "", UFN = "", ULN = "", d = "", m = "", y = "";

			for (int j = 0; line[j] != '\0'; j++)
			{
				if (line[j] == ',')
				{
					i++;
					continue;
				}
				//else if (!(line[j] > 47 && line[j] < 58) && line[j] != ',' && line[j] != '.')
				//{
				//	break;
				//}
				else if (i == 0)
				{
					userid += line[j];
 				}
				else if (i == 1)
				{
					UFN += line[j];
					//	t_d++;
				}
				else if (i == 2)
				{
					ULN += line[j];
					//	t_d++;
				}
				else if (i == 3)
				{
					y += line[j];
					///t_s++;
				}
				else if (i == 4)
				{
					m += line[j];
					///t_s++;
				}
				else
				{
					d += line[j];
					///t_s++;
				}
			}
			int id = stoi(userid.substr(4, 6));
			int dd = stoi(d);
			int mm = stoi(m);
			int yy = stoi(y);
			SMUser obj(userid, UFN, ULN, dd, mm, yy);
			if (SMU.count(id)==false)
			{
				SMU.insert(pair<int, SMUser>(id, obj));
			}
			else
			{
				// Save the user's details in a text file for error handling
				ofstream errorFile("UserErrors.txt", std::ios::app);
				errorFile << "Duplicate user found: " << obj.get_U_ID() << ", " << obj.get_F_Name() << " " << obj.get_L_Name() << endl;
				errorFile.close();
			}
		}
		inFile.close();
		users--;
		//       cout << "The number of unique users is: "<< users << endl;
	}
	else {
		cout << "Invalid File Name(Unable to open the File): \n";
		exit(0);
	}
}

void intialize_multimap(string filename, multimap<int, SMUserPost>& SMU_P, map<int, SMUser> SMU)
{
	int users = 0;
	ifstream inFile;
	inFile.open(filename);
	string line;
	string d, m, y, mm, hh, userid, pt, ss;
	if (inFile.is_open()) {
		// Loop through each line of the file and count the number of users
	   /* while (getline(inFile, line)) {
			users++;
			data = line.substr(0, 6);
		}*/

		while (getline(inFile, line)) {
			int i = 0;
			userid = "", mm = "", hh = "", d = "", m = "", y = "", ss = "", pt = "";

			for (int j = 0; line[j] != '\0'; j++)
			{
				if (line[j] == ',')
				{
					i++;
					continue;
				}
				//else if (!(line[j] > 47 && line[j] < 58) && line[j] != ',' && line[j] != '.')
				//{
				//	break;
				//}
				else if (i == 0)
				{
					userid += line[j];
				}
				else if (i == 1)
				{
					y += line[j];
					//	t_d++;
				}
				else if (i == 2)
				{
					m += line[j];
					//	t_d++;
				}
				else if (i == 3)
				{
					d += line[j];
					///t_s++;
				}
				else if (i == 4)
				{
					hh += line[j];
					///t_s++;
				}
				else if (i == 5)
				{
					mm += line[j];
					///t_s++;
				}
				else if (i == 6)
				{
					ss += line[j];
					///t_s++;
				}
				else
				{
					pt += line[j];
				}
			}
			int id = stoi(userid.substr(4, 6));
			int day = stoi(d);
			int mon = stoi(m);
			int year = stoi(y);
			int min = stoi(mm);
			int hrs = stoi(hh);
			int s = stoi(ss);
			SMUserPost obj(userid, day, mon, year, hrs, min, s, pt);
			
			if (SMU.count(id) == 1)
			{
				SMU_P.insert(pair<int, SMUserPost>(id, obj));
			}
			else
			{
				// Save the user's details in a text file for error handling
				ofstream errorFile("PostErrors.txt", std::ios::app);
				errorFile << "No user exist: " << obj.get_US_ID() << ", ";
				errorFile<< obj.get_Date().getYear() << "\\" << obj.get_Date().getMonth() << "\\" << obj.get_Date().getDay() << " ";
				errorFile<< obj.get_TOP().HH << ":" << obj.get_TOP().MM << ":" << obj.get_TOP().SS << endl;
				errorFile.close();
			}
		}
		inFile.close();
		users--;
		//       cout << "The number of unique users is: "<< users << endl;
	}
	else {
		cout << "Invalid File Name(Unable to open the File): \n";
		exit(0);
	}
}


void printUserErrors(const std::string& filename) {
	std::ifstream inFile(filename);
	if (!inFile.is_open()) {
		std::cout << "Invalid File Name no Errors Dectected in " << filename << std::endl;
		return;
	}

	std::string line;
	while (std::getline(inFile, line)) {
		std::cout << line << std::endl;
	}

	inFile.close();
}