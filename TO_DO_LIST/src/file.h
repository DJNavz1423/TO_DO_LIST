#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using std::vector;
using std::string;

struct fileDisplay {
    vector<string> tasks;
    vector<string> completedTasks;

    void fileCheck() {
        std::fstream file("todoList.txt", std::ios::in);
        if (file.is_open()) {
            string task;
            while (getline(file, task)) {
                tasks.push_back(task);
            }
            file.close();
        }
        else
            std::cerr << "\aNO EXISTING TO-DO LIST FOUND!\n";

        file.open("completedTasks.txt", std::ios::in);
        if (file.is_open()) {
            string completedTask;
            while (getline(file, completedTask)) {
                completedTasks.push_back(completedTask);
            }
            file.close();
        }
        else
            std::cerr << "\aNO EXISTING COMPLETED TASKS FOUND!\n";
    }

    void displayMenu() {
        system("cls");
        std::cout << "<========> To-Do List <========>\n"
            << " ------------------------------\n"
            << "\n<====== Menu Options ======>\n"
            << "\n1. Add Task\n"
            << "2. Display Tasks\n"
            << "3. Remove Task\n"
            << "4. Mark Task Complete\n"
            << "5. Display Completed Tasks\n"
            << "6. Remove Completed Task\n"
            << "7. Save and Quit\n"
            << "\n<=========================>\n"
            << "Enter your choice (1-7): ";
    }

    void displayTasks(vector<string>& tasks) {
        for (int i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << '\n';
        }
        std::cout << "\n<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n\n";
    }

    void save2File(const vector<string>& tasks, const string& filename) {
        std::fstream file(filename, std::ios::out | std::ios::trunc);
        if (file.is_open()) {
            for (const auto& task : tasks) {
                file << task << '\n';
            }
            file.close();
        }
        else
            std::cerr << "\aUNABLE TO SAVE TASKS TO FILE!\n";
    }
};