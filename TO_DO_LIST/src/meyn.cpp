#include "class.h"

int main() {
	TDList lists{};

	lists.fD.fileCheck();
	char choice;
	do {
		lists.fD.displayMenu();
		std::cin >> choice;
		std::cin.ignore();
		switch (choice) {
		case '1':
			lists.addTask();
			break;
		case '2':
			system("cls");
			std::cout << "============> Tasks List <=============\n\n";
			lists.fD.displayTasks(lists.fD.tasks);
			std::cin.get();
			break;
		case '3':
			system("cls");
			std::cout << "====== Remove Task ======\n\n";
			lists.fD.displayTasks(lists.fD.tasks);
			std::cout << "Enter tasks index (space-separated): ";
			lists.removeTasks(lists.fD.tasks);
			std::cin.get();
			break;
		case '4':
			lists.markTaskComplete(lists.fD.tasks);
			std::cin.get();
			break;
		case '5':
			system("cls");
			std::cout << "=======> Completed Tasks List <=======\n\n";
			lists.fD.displayTasks(lists.fD.completedTasks);
			std::cin.get();
			break;
		case '6':
			system("cls");
			std::cout << "====== Remove Completed Task ======\n\n";
			lists.fD.displayTasks(lists.fD.completedTasks);
			std::cout << "Enter tasks index (space-separated): ";
			lists.removeTasks(lists.fD.completedTasks);
			std::cin.get();
			break;
		case '7':
			lists.fD.save2File(lists.fD.tasks, "todolist.txt");
			lists.fD.save2File(lists.fD.completedTasks, "completedtasks.txt");
			std::cout << "\n<<<<<<<< \"Program Terminated!\" >>>>>>>>>\n" << "\n    Tasks successfully saved to file\n" << "     ------------------------------\n";
			break;
		default:
			std::cerr << "\aINVALID INPUT! PLEASE ENTER A NUMBER FROM 1 - 7.\n";
			break;
		}
	} while (choice != '7');
}