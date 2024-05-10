#include "class.h"

int main (){
	TDList lists{};

	lists.fileCheck();
	char choice;
	do {
		lists.displayMenu();
		std::cin >> choice;
		std::cin.ignore();
		switch (choice) {
		case '1':
			lists.addTask();
			break;
		case '2':
			system("cls");
			std::cout << "============> Tasks List <=============\n\n";
			lists.displayTasks(lists.tasks);
			std::cin.get();
			break;
		case '3':
			system("cls");
			std::cout << "====== Remove Task ======\n\n";
			lists.displayTasks(lists.tasks);
			std::cout << "Enter tasks index (space-separated): ";
			lists.removeTasks(lists.tasks);
			std::cin.get();
			break;
		case '4':
			lists.markTaskComplete(lists.tasks);
			std::cin.get();
			break;
		case '5':
			system("cls");
			std::cout <<"=======> Completed Tasks List <=======\n\n";
			lists.displayTasks(lists.completedTasks);
			std::cin.get();
			break;
		case '6':
			system("cls");
			std::cout << "====== Remove Completed Task ======\n\n";
			lists.displayTasks(lists.completedTasks);
			std::cout << "Enter tasks index (space-separated): ";
			lists.removeTasks(lists.completedTasks);
			std::cin.get();
			break;
		case '7':
			lists.save2File(lists.tasks, "todolist.txt");
			lists.save2File(lists.completedTasks, "completedtasks.txt");
			std::cout <<"\n<<<<<<<< \"Program Terminated!\" >>>>>>>>>\n" << "\n    Tasks successfully saved to file\n" << "     ------------------------------\n";
			break;
		default:
			std::cerr << "\aINVALID INPUT! PLEASE ENTER A NUMBER FROM 1 - 7.\n";
			break;
		}
	} while (choice != '7');
}