#pragma once

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
                       "1. Be reponsible\n"
                       "2. Don't be lazy e.g. rebalancing check HSSSHSC\n"
                       "3. Focus on thinking: hand gesture or move to help you think and calculate\n"
                       "4. Learn his excel solving skills\n\n"
                       "Favorite Courses\n"
                       "BCIT - Data Structure and Algorithm Analysis\n"
                       "BCIT - Application Development with C++\n"
                       "BCIT - Advanced Application Development with C++\n"
                       "BCIT - Advanced Data Structure and Algorithm Analysis\n\n"
                       "Remarks:\n";

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