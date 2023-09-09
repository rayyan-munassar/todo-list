
#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <sstream> // oss
#include <string>
#include <iomanip> // Include this for setw and setfill

std::string getDate()
{
    time_t t = time(NULL);
    struct tm date = *localtime(&t);

    std::ostringstream oss;
    oss << "Current date is " << date.tm_year + 1900 << '-'
        << std::setw(2) << std::setfill('0') << date.tm_mon + 1 << '-'
        << std::setw(2) << std::setfill('0') << date.tm_mday << ' '
        << std::setw(2) << std::setfill('0') << date.tm_hour << ':'
        << std::setw(2) << std::setfill('0') << date.tm_min;

    return oss.str();
}

int main()
{

    std::cout << "|___________MENU____________|" << std::endl;
    std::cout << "|1-Add task                 |" << std::endl;
    std::cout << "|2-Remove task              |" << std::endl;
    std::cout << "|3-Update task              |" << std::endl;
    std::cout << "|4-Add task                 |" << std::endl;
    std::cout << "|5-End the program          |" << std::endl;
    std::cout << "|___________________________|" << std::endl;

    int option;
    std::vector<int> tasks;
    std::unordered_map<std::string, std::string> task;
    int id = 0;
    int priority;

    std::cout << "Enter the operation number: ";
    std::cin >> option;

    switch (option)
    {
    case 1:

        std::cout << "Enter the description: ";
        std::cin.ignore();
        std::getline(std::cin, task["description"]);

        task["id"] = std::to_string(id++);
        task["date"] = getDate();

        std::cout << "Enter the number of priortiy" << std::endl;
        std::cout << "1- Not important" << std::endl;
        std::cout << "2- Important" << std::endl;
        std::cout << "3- Very important" << std::endl;
        std::cin >> priority;

        switch (priority)
        {
        case 1:
            task["priority"] = "Not important";
            break;

        case 2:
            task["priority"] = "Important";
            break;

        case 3:
            task["priority"] = "Very important";
            break;

        default:
            break;
        }

        std::cout << task["description"] << std::endl;
        std::cout << task["id"] << std::endl;
        std::cout << task["date"] << std::endl;
        std::cout << task["priority"] << std::endl;

        break;

    default:
        break;
    }

    return 0;
}