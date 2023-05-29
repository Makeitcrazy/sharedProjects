#pragma once 

void studyCountdown(string osystem)
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
            if (osystem == "W32" || osystem == "W64")
            {
                system("rundll32.exe user32.dll,LockWorkStation");
            }
            else if (osystem == "M")
            {
                system("pmset displaysleepnow");
            }
            // Generate clock alarm here
        }
        this_thread::sleep_for(chrono::seconds(1));
    }
}
