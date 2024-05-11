#pragma once
#include <algorithm>
#include "file.h"

class TDList {
public:
    fileDisplay fD;
    void addTask() {
        system("cls");
        std::cout << "====== Add Tasks ======\n\n"
            << "How many task would you add? : ";
        short capacity;
        std::cin >> capacity;
        std::cin.ignore();
        string newTask;
        //std::string newTask;
        for (int i = 0; i < capacity; i++) {
            if (i == 0)
                std::cout << '\n';
            std::cout << "(" << i + 1 << ") Enter tasks ('X' to go back): ";
            std::getline(std::cin, newTask);
            if (newTask == "x" || newTask == "X")
                break;
            fD.tasks.push_back(newTask);
        }
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
        fD.displayTasks(taks);
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
                if (index >= 1 && index <= fD.tasks.size()) {
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
            std::cout << "TASK \"" << fD.tasks[index - 1] << "\" FINISHED.\n";
            fD.completedTasks.push_back(fD.tasks[index - 1]);
        }
        std::sort(indices2Complete.rbegin(), indices2Complete.rend());
        for (short index : indices2Complete) {
            fD.tasks.erase(fD.tasks.begin() + index - 1);
        }
    }
};