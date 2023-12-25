#include<string>
#include<map>
#include"functions.h"
#include"Dat.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
using namespace std;


// Definition of the overloaded << operator
ostream& operator<<(std::ostream& os, const Date& date) {
    os << std::setfill('0') << std::setw(2) << date.day << "/";
	os << std::setfill('0') << std::setw(2) << date.month << "/";
	os << std::setw(4) << date.year;
	return os;
}

int main()
{
    int choice = 0, p = 1;
    map <int, SMUser>SMU;
    multimap<int, SMUserPost> SMU_P;
    multimap<int, SMUserPost>::iterator iter,iter2,iter3;
    intialize_map("SMUsers.csv", SMU);
    intialize_multimap("SMUserPosts.csv", SMU_P,SMU);
        
    
    //display the menu and get user input
      
    do {
        cout << "Menu:" << endl;
        cout << "1. Display all Users" << endl;
        cout << "2. Display a Specific User" << endl;
        cout << "3. Display all Posts" << endl;
        cout << "4. Display Posts from a Specific User" << endl;
        cout << "5. Exit the program" << endl;
        cout << "Enter your desired number (1-5): ";
        cin >> choice;

        switch (choice){
        case 1:
            // display all users
            cout << "\n\nUser ID" << "\t" << "First Name" << "\t" << "Last Name" << "\t" << "Date of Membership:" << "\t" << "Total no# of posts: " << endl;
            for (p = 1; p <= SMU.size(); p++)
            {
                SMU.at(p).Display();
                cout << "\t" << SMU_P.count(p) << endl;
            }
            break;
        case 2:
            // display a specific user
            cout << "Enter the ID of the user you want to display: ";
            cin >> choice;

            if (SMU.count(choice) == 1)
            {
                cout << "\n\nUser ID" << "\t" << "First Name" << "\t" << "Last Name" << "\t" << "Date of Membership:" << "\t" << "Total no# of posts: " << endl;
                SMU.at(choice).Display();
                cout << "\t" << SMU_P.count(choice) << endl;
                choice = 2;
            }
            else
            {
                cout << "Invalid Input: (User does not exist): \n\n";
            }
            break;
        case 3:
            // display all posts
             cout << "\n\nUser ID" << "\t" << "Date of Post" << "\t" << "Time of Post" << "\t" << " Post Text:" << endl;
             for (iter = SMU_P.begin(); iter != SMU_P.end(); ++iter)
             {
                 iter->second.Display();
                 cout << endl;
             }
        break;
        case 4:
            // display posts from a specific user
            cout << "Enter the ID no# of the user you want to display: ";
            cin >> choice;

            for (iter = SMU_P.begin(); iter != SMU_P.end(); ++iter)
            {
                if (iter->first == choice)
                {
                    iter2 = SMU_P.equal_range(choice).first;
                    iter3 = SMU_P.equal_range(choice).second;
                    if (SMU_P.count(choice) == 0)
                    {
                        cout << "\n\nNo Posts Found:" << endl;
                        break;
                    }
                    cout << "\n\nUser ID" << "\t" << "Date of Post" << "\t" << "Time of Post" << "\t" << " Post Text:" << endl;
                    while (iter2 != iter3) {
                        iter2->second.Display(); 
                        cout << endl;
                        iter2++;
                    }
                    choice = 4;
                }
            }

            if (iter == SMU_P.end())
            {
                cout << "Invalid Input: (User-ID does not exist in the Multi-Map): \n\n";
            }
            break;
        case 5:
            // exit the program
            cout << "\n\n\n\t\t\tI Hope You liked the Application\n\t\t\t\tHave a Nice Day" << endl;
            break;
        default:
            // invalid input
            cout << "\tInvalid input: Please enter a number between 1 and 5." << endl;
            break;
        }

        Sleep(5000);
        system("CLS");
    } while (choice != 5);

	return 0;
}