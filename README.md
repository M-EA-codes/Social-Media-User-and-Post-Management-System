# Social Media User and Post Management System

This C++ program manages users and posts within a social media platform. It reads data from CSV files (`SMUsers.csv` and `SMUserPosts.csv`) and stores the information in STL Maps and MultiMaps.

## Overview

The program consists of functionalities to display users and their posts, allowing specific user searches and overall information about the user base.

## Implementation Details

### Data Handling

The program uses STL Maps and MultiMaps to store and manage user data and posts:
- **SMUsers.csv**: Contains user information.
- **SMUserPosts.csv**: Includes posts from users identified in the `SMUsers.csv` file.

### Libraries Used

- `string`: For string manipulation.
- `map` and `multimap`: For storing user and post information.
- `functions.h` and `Dat.h`: Headers containing necessary function prototypes and data structures.
- `Windows.h` or `unistd.h`: For system-specific functions.

## Execution

1. **Compilation**: Compile the source code using a compatible C++ compiler.
2. **Execution**: Run the compiled program.
3. **Menu Navigation**: Users can navigate through the following functionalities:
    - Display all Users
    - Display a Specific User
    - Display all Posts
    - Display Posts from a Specific User
    - Exit the program

## Code Description

- The `main()` function initializes user and post maps and multimap.
- Displays a menu for user interaction and input choice handling.
- Options include displaying users, specific users, all posts, posts from a specific user, and exiting the program.
- Utilizes `Sleep()` for delay and `system("CLS")` for clearing the console screen between menu interactions.

## Project Experience
### Social Media Data Handling Project
This project was undertaken as part of a freelance contract for a social media data management system. The goal was to create a program to manage user data and their corresponding posts.


#### Key Achievements
- Successfully implemented CSV data parsing and storage into STL Maps and MultiMaps.
- Developed functionalities to display all users, specific users, all posts, and posts from a particular user.
- Managed the program's user interface and menu system to facilitate easy navigation and usage.

This project provided hands-on experience in data handling, STL Map/MultiMap utilization, and user interface development in C++. It was a valuable opportunity to apply programming skills to a practical scenario and deliver a functional solution for the client.

## Notes
- Ensure CSV files are properly formatted and present in the correct file path.
- Input validation is in place to handle invalid user IDs or choices.
- The program includes Windows-specific (`Windows.h`) or POSIX (`unistd.h`) headers for system-specific functionalities.
