#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using std::vector;
using std::string;

class TDList {
public:
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
            << " -------------------------------------\n"
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

	void addTask(){
        std::cout << "\n====== Add Tasks ======\n\n"
            << "How many task would you add? : ";
        short capacity;
        std::cin >> capacity;
        std::cin.ignore();
        string newTask;
        //std::string newTask;
        for (int i = 0; i < capacity; i++) {
            std::cout << "(" << i + 1 << ") Enter tasks ('X' to go back): ";
                std::getline(std::cin, newTask);
            if (newTask == "x" || newTask == "X")
                break;
            tasks.push_back(newTask);
        }
	}

    void displayTasks(vector<string>& tasks) {
        for (int i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << '\n';
        }
        std::cout << "\n<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>\n\n";
    }

    void removeTasks(vector<string>& tasks) {
        string input;
        std::getline(std::cin, input);

        vector<short> indices2Remove;
        size_t pos = 0;
        std::cout << '\n';

        while ((pos = input.find(' ')) != string::npos || !input.empty()) {
            string indexStr = input.substr(0, pos);
            short index;
            bool validInput = true;
           
            for (char num : indexStr) {
                if (!isdigit(num)) {
                    validInput = false;
                    break;
                }
            }

            if (validInput) {
                index = static_cast<short>(std::stoi(indexStr));
                if (index >= 1 && index <= tasks.size()) {
                    indices2Remove.push_back(index);
                }
                else
                    std::cerr << "\aINVALID INDEX: " << index << ". IGNORING.\n";
            }
            else
                std::cerr << "\aINVALID INPUT: " << indexStr << ". IGNORING.\n";
            input.erase(0, pos == string::npos ? pos : pos + 1);
        }
        for (short index : indices2Remove) {
            std::cout << "TASK \"" << tasks[index - 1] << "\" REMOVED.\n";
        }
        std::sort(indices2Remove.rbegin(), indices2Remove.rend());
        for (short index : indices2Remove) {
            tasks.erase(tasks.begin() + index - 1);
        }
    }

    void markTaskComplete(vector<string>& taks) {
        system("cls");
        std::cout << "\n====== Mark Task Complete ======\n\n";
            displayTasks(taks);
         std::cout << "Enter tasks index (space-separated): ";
        string input;
        std::getline(std::cin, input);

        vector<short> indices2Complete;
        size_t pos = 0;
        std::cout << '\n';

        while ((pos = input.find(' ')) != string::npos || !input.empty()) {
            string indexStr = input.substr(0, pos);
            short index;
            bool validInput = true;

            for (char num : indexStr) {
                if (!isdigit(num)) {
                    validInput = false;
                    break;
                }
            }

            if (validInput) {
                index = static_cast<short>(std::stoi(indexStr));
                if (index >= 1 && index <= tasks.size()) {
                    indices2Complete.push_back(index);
                }
                else
                    std::cerr << "\aINVALID INDEX: " << index << ". IGNORING.\n";
            }
            else
                std::cerr << "\aINVALID INPUT: " << indexStr << ". IGNORING.\n";
            input.erase(0, pos == string::npos ? pos : pos + 1);
        }
        for (short index : indices2Complete) {
            std::cout << "TASK \"" << tasks[index - 1] << "\" FINISHED.\n";
            completedTasks.push_back(tasks[index - 1]);
        }
        std::sort(indices2Complete.rbegin(), indices2Complete.rend());
        for (short index : indices2Complete) {
            tasks.erase(tasks.begin() + index - 1);
        }
    }

    void save2File (const vector<string>& tasks, const string& filename) {
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