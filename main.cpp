#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <sstream>
#include <thread>
// import <stdlib.h> for system("pause") at Mac
#include <stdlib.h>
// import <cstdlib> for Windows
#include <cstdlib>

using namespace std;

#include "./setDTask.h"
#include "./count.h"
#include "./checkOS.h"
#include "./setGoals.h"
// #include "./menu.h"

using namespace std;

int main()
{
    char opt;

    // menu();

    // createDTasks();
    int choice;

    string osystem = checkOS();

    cout << "Would you please set up your daily tasks?" << endl;
    cout << "1. Create Today's Schedule" << endl;
    cout << "2. Check Today's Schedule" << endl;
    cout << "3. Delete all Today's Schedule" << endl;
    cout << "4. Jump to Study Countdown" << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;

    cin >> choice;
    while (choice != 4 || choice > 4)
    {
        switch(choice)
        {
            case 1:
                createDTasks();
                break;
            case 2:
                displayDTasks();
                std::cout << endl;
                std::cout << endl;
                break;
            case 3:
                clearTxtfile();
                break;
        }
        cout << "Would you please set up your daily tasks?" << endl;
        cout << "1. Create Today's Schedule" << endl;
        cout << "2. Check Today's Schedule" << endl;
        cout << "3. Delete all Today's Schedule" << endl;
        cout << "4. Exit" << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;
        cin >> choice;
    }

    displayDTasks();
    std::cout << endl;
    displayTarget();
    
    checkOS();
    
    // Call study time countdown function
    studyCountdown(osystem);
    
    cout << "Start a new study phase (type 'y' to continue or 'n' to main screen): " << endl;
    cin >> opt;
    while (opt != 'n')
    { // For char ''; for string "" getline for string
        clearScreen(osystem);

        displayDTasks();
        std::cout << endl;
        displayTarget();

        cout << "Study time for 40 minutes count now!" << endl;
        studyCountdown(osystem);
        cout << "Start a new study phase (type 'y' to continue or 'n' to main screen): " << endl;
        cin >> opt;
    }
    // cout << "Enter a sentence (or type 'exit' to quit): " << endl;
    // getline(cin, sentence);
    return 0;
}