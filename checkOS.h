#pragma once


string checkOS()
{
    // Determine the operating system
    string osystem;
// Determine the operating system
#if defined(_WIN32)
    osystem = "W32";
    // pause the screen on Window OS
    cout << "If you are ready, please any button to start counting!" << endl;
    system("pause");
#elif defined(_WIN64)
    osystem = "W64";
    // pause the screen on Window OS
    cout << "If you are ready, please any button to start counting!" << endl;
    system("pause");
#elif defined(__linux__)
    osystem = "L";
#elif defined(__APPLE__)
    osystem = "M";
    // pasue the screen on Mac OS
    system("read -n 1 -s -p \"If you are ready, please any button to start counting!\n\"");
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
    else if (osystem == "W64" || osystem == "M")
    {
        system("clear");
    }
    else
    {
        cout << "Unknown Operating System" << endl;
    }
}