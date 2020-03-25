#include<iostream>
#include<string>
#include<fstream>
using namespace std;



int main() {

	int action = 0;
	do
	{
		cout << "\tMENU:" << endl;
		cout << "1. Add new quiz" << endl;
		cout << "2. Show all quizzes" << endl;
		cout << "2. Pass one of the quizzes" << endl;
		cout << "4. Exit" << endl;
		cout << endl;
		cout << "Select action: ";
		cin >> action;

		switch (action){
		case 1: {
			cout << "ADD NEW QUIZ :" << endl;
		}break;
		case 2: {
			cout << "ALL QUIZES: " << endl;

		}break;
		case 3: {

		}break;
		case 4: {
			cout << "Bye" << endl;
			break;
		}
		default: {
			cout << "Please select action (1 - 3)" << endl;
		}
		}

	} while (action != 4);



	system("pause");
	return 0;
}

