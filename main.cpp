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
#include "./setDTask.h"
#include "./count.h"
#include "./checkOS.h"
#include "./setGoals.h"
// #include "./menu.h"


using namespace std;

int main()
{
    char opt;
    displayTarget();

    // menu();

    // createDTasks();

    string osystem = checkOS();

    // Call study time countdown function
    studyCountdown(osystem);
    
    cout << "Start a new study phase (type 'y' to continue or 'n' to main screen): " << endl;
    cin >> opt;
    while (opt != 'n')
    { // For char ''; for string "" getline for string
        clearScreen(osystem);
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