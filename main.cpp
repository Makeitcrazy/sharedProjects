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

// Study time set to 40 minutes of focus time

void studyCountdown()
{
    const int seconds = 5; // 2700
    for (int i = seconds; i >= 0; i--)
    {
        if (i > 0)
        {
            cout << "Time Left:: " << i << "s" << endl;
        }
        if (i == 0)
        {
            cout << "Time's up! Time to Rest!" << endl;
            // system("rundll32.exe user32.dll,LockWorkStation");
            // Generate clock alarm here
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void displayTarget()
{

    std::string text = "Goals and Reminders\n"
                       "C++ - Hope to have a learning progress within 2023!!!!\n"
                       "Machine Learning and Deep Learning - Start to publish my first project by July\n"
                       "FRM - Keep learning and absorbing knowledge and try the exam on November\n\n"
                       "Kenneth:\n"
                       "1. Study quality more than quantity!\n"
                       "2. Try and Error! If you don't try, you put your esteem high up which does not help your personal growth!\n"
                       "3. Understand what you are doing!\n"
                       "4a. Whether the decision benefits me or hurts me? And in what ways? Whether this strategy is good or not good?\n"
                       "4b. Who will be responsible if I take this action?\n"
                       "5. Am I doing it right, and how can I prove that I'm doing right?\n"
                       "6. Why do I do this? Is there any better way to make it better or faster?\n"
                       "7. Once I complete a task, I don't need to submit...double check double check and use different methods to test and check the results\n"
                       "8. Don't rush to complete a task!\n"
                       "9. Check your work! Don't get it wrong, and be careful and cautious! Think how to do it faster and quicker!\n"
                       "10. Some events show his attitudes: 1) Find AH adjusted factor; 2) Prove Alice's statement wrong; 3) No mistake! Zero Tolerance!\n\n"
                       "Philip:\n"
                       "Be reponsible\n"
                       "Don't be lazy e.g. rebalancing check HSSSHSC\n"
                       "Focus on thinking: hand gesture or move to help you think and calculate\n"
                       "Learn his excel solving skills\n\n"
                       "Favorite Courses\n"
                       "BCIT - Data Structure and Algorithm Analysis\n"
                       "BCIT - Application Development with C++\n"
                       "BCIT - Advanced Application Development with C++\n"
                       "BCIT - Advanced Data Structure and Algorithm Analysis";

    // Determine the maximum length of a line in the text
    size_t max_line_length = 135;
    int max_leng = 0;
    int i = 0;

    for (const char &line : text)
    {
        // std::cout << line;
        i++;
        // Find the max charlength in a line
        if (line == '\n')
        {
            if (i > max_leng)
            {
                max_leng = i;
                i = 0;
            }
            else
            {
                i = 0;
            }
        }
    }

    string concat_String;
    // Print the top border
    std::cout << "|" << std::string(max_line_length + 2, '-') << "|" << std::endl;

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != '\n')
        {
            concat_String += text[i];
        }
        else
        {
            std::cout << "| " << concat_String << std::string(max_line_length - concat_String.length(), ' ') << " |" << std::endl;
            concat_String = "";
        }
    }
    std::cout << "|" << std::string(max_line_length + 2, '-') << "|" << std::endl;
}

string checkOS()
{
    // Determine the operating system
    string osystem;
// Determine the operating system
#if defined(_WIN32)
    osystem = "W32";
    // // pause the screen on Window OS
    // cout << "If you are ready, please any button to start counting!" << endl;
    // system("pause");
#elif defined(_WIN64)
    osystem = "W64";
    // // pause the screen on Window OS
    // cout << "If you are ready, please any button to start counting!" << endl;
    // system("pause");
#elif defined(__linux__)
    osystem = 'L';
#elif defined(__APPLE__)
    osystem = 'M';
    // // pasue the screen on Mac OS
    // system("read -n 1 -s -p \"If you are ready, please any button to start counting!\n\"");
#else
    std::cout << "Unknown Operating System" << std::endl;
    osystem = "NULL"
    // return 0;
#endif
    return osystem;
}

void clearScreen(string osystem)
{
    if (osystem == "W32")
    {
        system("cls");
    }
    else if (osystem == "W32")
    {
        system("clear");
    }
    else if (osystem == "M")
    {
        system("clear");
    }
    else
    {
        cout << "Unknown Operating System" << endl;
    }
}

int main()
{
    char opt;
    displayTarget();

    string osystem = checkOS();

    // Pause the screen base on the OS
    if (osystem == "W32" || osystem == "W32")
    {
        // pause the screen on Window OS
        cout << "If you are ready, please any button to start counting!" << endl;
        system("pause");
    }
    else if (osystem == "M")
    {
        // pasue the screen on Mac OS
        system("read -n 1 -s -p \"If you are ready, please any button to start counting!\n\"");
    }
    else
    {
        // if the OS is not Windows or Mac, print out the error message
        cout << "Unknown Operating System" << endl;
        // return 0 to exit the program
        return 0;
    }

    // Call study time countdown function
    studyCountdown();
    cout << "Start a new study phase (type 'y' to continue or 'n' to main screen): " << endl;
    cin >> opt;
    while (opt != 'n')
    { // For char ''; for string "" getline for string
        clearScreen(osystem);
        displayTarget();
        cout << "Study time for 40 minutes count now!" << endl;
        studyCountdown();
        cout << "Start a new study phase (type 'y' to continue or 'n' to main screen): " << endl;
        cin >> opt;
    }
    // cout << "Enter a sentence (or type 'exit' to quit): " << endl;
    // getline(cin, sentence);
    return 0;
}

//test