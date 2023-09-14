#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <sstream>
#include <string>
#include <iomanip>
#include <algorithm>

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

void addTask(std::vector<std::unordered_map<std::string, std::string>> &tasks, int &id)
{
    std::unordered_map<std::string, std::string> task;

    std::cout << "Enter task details:" << std::endl;

    std::cout << "Title: ";
    std::cin.ignore();
    std::getline(std::cin, task["title"]);

    std::cout << "Description: ";
    std::getline(std::cin, task["description"]);

    task["id"] = std::to_string(id++);
    task["date"] = getDate();

    std::cout << "Enter the priority (1-3):" << std::endl;
    std::cout << "1- Not important" << std::endl;
    std::cout << "2- Important" << std::endl;
    std::cout << "3- Very important" << std::endl;

    int priority;
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

    tasks.push_back(task);

    std::cout << "Task added successfully!" << std::endl;
}

void listTasks(const std::vector<std::unordered_map<std::string, std::string>> &tasks)
{
    std::cout << "Task List:" << std::endl;

    for (const auto &task : tasks)
    {
        std::cout << "Title: " << task.at("title") << std::endl;
        std::cout << "Description: " << task.at("description") << std::endl;
        std::cout << "Task ID: " << task.at("id") << std::endl;
        std::cout << "Priority: " << task.at("priority") << std::endl;
        std::cout << "Date: " << task.at("date") << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
}

void removeTask(std::vector<std::unordered_map<std::string, std::string>> &tasks)
{
    std::cout << "Enter the task ID to remove:" << std::endl;
    int taskId;
    std::cin >> taskId;

    auto it = std::remove_if(tasks.begin(), tasks.end(),
                             [taskId](const std::unordered_map<std::string, std::string> &task)
                             {
                                 return task.at("id") == std::to_string(taskId);
                             });

    if (it != tasks.end())
    {
        tasks.erase(it, tasks.end());
        std::cout << "Task removed successfully!" << std::endl;
    }
    else
    {
        std::cout << "Task not found with the specified ID." << std::endl;
    }
}

int main()
{
    bool running = true;
    std::vector<std::unordered_map<std::string, std::string>> tasks; // Store tasks in a vector
    int id = 1;                                                      // Starting task ID

    while (running)
    {
        std::cout << "|___________MENU____________|" << std::endl;
        std::cout << "|1-Add task                 |" << std::endl;
        std::cout << "|2-List tasks               |" << std::endl;
        std::cout << "|3-Remove task              |" << std::endl;
        std::cout << "|4-End the program          |" << std::endl;
        std::cout << "|___________________________|" << std::endl;

        int option;

        std::cout << "Enter the option number: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            addTask(tasks, id);
            break;

        case 2:
            listTasks(tasks);
            break;

        case 3:
            removeTask(tasks);
            break;

        case 4:
            running = false;
            break;

        default:
            std::cout << "Invalid option. Please try again." << std::endl;
            break;
        }
    }

    return 0;
}