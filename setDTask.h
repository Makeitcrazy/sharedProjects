#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

void createDTasks()
{ // Creation of ofstream class object
    ofstream fout;

    string line;

    fout.open("Daily_Tasks.txt", ios::app);
    std::cout << "Please enter your daily tasks today and press '-1' to exit" << endl;
    std::cout << "Suggested input format: 11am-12nn - Cooking" << endl;
    std::cout << "-------------------------------------------------------------------------------------------" << endl;

    if (fout)
    {
        while (fout)
        {
            // Input a line
            getline(cin, line);

            // Input -1 to exit the input line
            if (line == "-1")
                break;

            // Write into the file
            fout << line << endl;
        }
    }
    else
    {
        std::cout << "File opening has issue(s)!" << endl;
    }

    fout.close();
}

void displayDTasks()
{
    ifstream fin;
    // Create a string to store the text inside
    string line;

    fin.open("Daily_Tasks.txt");

    // Loop through the text using getline
    // int line_no = 0;
    if (fin)
    {
        while (getline(fin, line))
        {
            std::cout << line << endl;
            // line_no++;
        }
    }
    else
    {
        std::cout << "File opening has issue(s)!" << endl;
    }
    // std::cout << line_no << endl;
    fin.close();
}


// This module has so many problems
void deleteDTask()
{
    string line;

    displayDTasks();

    // input delete line
    int line_no;
    std::cout << "Please input a delete line number based on the above paragraph!" << endl;
    std::cin >> line_no;

    // Open the current text file now
    ifstream fin;
    fin.open("Daily_Tasks.txt");

    // Open a new text file
    std::ofstream temp;
    temp.open("temp.txt");

    int curline = 1;
    if (fin)
    {
        while (getline(fin, line))
        {
            // Open the file and if the line number is aligned with the current line, write into a new file without the specified line
            if (curline != line_no)
            {
                temp << line << endl;
            }
            curline++;
        }

        temp.close();
        fin.close();

        // Rename and delete files
        rename("temp.txt", "Daily_Tasks.txt");
        remove("temp.txt");
    }
    else
    {
        std::cout << "File Opening Unsuccessful!" << endl;
    }

/* Delete line algorithm
    Create a new text file in a folder to store the new lines
    Move the new lines to a new file and write out in it
*/
}

void clearTxtfile()
{
    std::ofstream ofs;
    // trunc is used to clear all the text inside the daily file
    ofs.open("Daily_Tasks.txt", std::ofstream::out | std::ofstream::trunc);

    if (!ofs)
    {
        std::cout << "File has not been successfully opened!" << endl;
    }

    ofs.close();
}
