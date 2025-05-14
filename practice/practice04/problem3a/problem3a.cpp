// problem3a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <string>

void addTask(std::list<std::string>& tasks) {
    std::string task;
    std::cout << "Enter task: ";
    std::getline(std::cin, task);

    //invalid check
    if (task.empty()) {
        std::cout << "Invalid input! Task cannot be empty." << std::endl;
    }
    else {
        tasks.push_back(task);
        std::cout << "Task added!" << std::endl;
    }
}

void removeTask(std::list<std::string>& tasks) {
    int taskNumber;
    std::cout << "Enter task number to remove: ";

    //invalid check
    while (!(std::cin >> taskNumber)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a valid task number: ";
    }
    std::cin.ignore();

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        auto it = tasks.begin();
        std::advance(it, taskNumber - 1);
        tasks.erase(it);
        std::cout << "Task removed!" << std::endl;
    }
    else {
        std::cout << "Invalid task number!" << std::endl;
    }
}

void showTasks(const std::list<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to display!" << std::endl;
    }
    else {
        std::cout << "Tasks:" << std::endl;
        int count = 1;
        for (const auto& task : tasks) {
            std::cout << count++ << ". " << task << std::endl;
        }
    }
}

int main()
{
    std::list<std::string> tasks;
    int choice;

    while (true) {
        std::cout << "\n1. Add Task\n"
            << "2. Remove Task\n"
            << "3. Show Tasks\n"
            << "4. Exit\n"
            << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            addTask(tasks);
        }
        else if (choice == 2) {
            removeTask(tasks);
        }
        else if (choice == 3) {
            showTasks(tasks);
        }
        else if (choice == 4) {
            std::cout << "Exiting the program!" << std::endl;
            break;
        }
        else {
            std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }

    return 0;
}