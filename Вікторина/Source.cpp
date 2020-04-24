#include"Viktoryna.h"
#include<iostream>
using namespace std;


#define CLEAR system("cls");

int main() {
	init();
	int action = 0;
	do
	{
		cout << "\tMENU:" << endl;
		cout << "1. Add new quiz" << endl;
		cout << "2. Show all quizzes & Pass one of the quizzes" << endl;
		cout << "3. Exit" << endl;
		cout << endl;
		cout << "Select action: ";
		cin >> action;

		switch (action){
		case 1: {
			CLEAR;
			cout << "ADD NEW QUIZ :" << endl;
			addquiz();
		}break;
		case 2: {
			CLEAR;
			showAllQuizzes();
			cout << "If you want to pass one of quiz - select 'y' " << endl;
			cout << "Exit - select 'n' " << endl;
			string ansvToPassQuiz = "";
			cin >> ansvToPassQuiz;
			if (ansvToPassQuiz=="y") {
				passQuiz();
			}
			else {
				break;
			}
		}break;
		case 3: {
			CLEAR;
			cout << "\n\n\n\t\t\tBye!" << endl;
			break;
		}
		default: {
			cout << "Please select action (1 - 3)" << endl;
		}
		}

	} while (action != 3);



	system("pause");
	return 0;
}

