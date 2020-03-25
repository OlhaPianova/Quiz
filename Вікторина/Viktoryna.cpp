#include "Viktoryna.h"
#include<iostream>
#include<string>
#include<fstream>


Quiz* arrQuizzes;
int countQuizzes=0;
void addquiz()
{
	ofstream fout;
	fout.open("quizzes.txt", fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true) {
		Quiz* temp = new Quiz[countQuizzes + 1];
		for (int i = 0; i < 5; i++) {
			temp[i] = arrQuizzes[i];
		}

		int countQuestion = 0;

		cout << "Enter name for Quiz: " << endl;
		cin >> temp[countQuizzes].quizName;
		

		
	}
	else {
		cout << "Error: file not opened!" << endl;
	}
}
