#include "Viktoryna.h"
#include<fstream>
#include<Windows.h>
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
Quiz* arrQuizzes;
int countQuizzes=0;
const int questionNumb = 5;

void pushInGlobalArr(Quiz quiz) {
	Quiz* temp = new Quiz[countQuizzes + 1];
	for (int i = 0; i < countQuizzes; i++) {
		temp[i] = arrQuizzes[i];
	}
	temp[countQuizzes] = quiz;
	countQuizzes++;
	arrQuizzes = new Quiz[countQuizzes];
	for (int i = 0; i < countQuizzes; i++) {
		arrQuizzes[i] = temp[i];
	}
	delete temp;
}
void passQuiz() {
	cout << "\tEnter the quiz number you want to pass: " << endl;
	int number = 0;
	string ansv = "";
	int bal = 0;
	int rightAnsver = 0;
	cin >> number;
		cout << "You pass quizzes: " << arrQuizzes[number - 1].quizName << endl;
		for (int i = 0; i < questionNumb; i++) {
			cout << i + 1 << ". " << arrQuizzes[number-1].description[i].question << endl;
			cout << "Enter your answer: " << endl;
			cin >> ansv;
			if (ansv == arrQuizzes[number-1].description[i].answer) {
				SetConsoleTextAttribute(color, FOREGROUND_GREEN);
				cout << "RIGHT - YOU GET 20 POINTS)" << endl;
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				bal += 20;
				rightAnsver++;
			}
			else {
				SetConsoleTextAttribute(color, FOREGROUND_RED);
				cout << "ERROR" << endl;
				SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

				SetConsoleTextAttribute(color, FOREGROUND_GREEN);
				cout << "RIGHT ANSWER: " << arrQuizzes[i].description[i].answer << endl;
				SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
		}
	if (rightAnsver>0) {
		SetConsoleTextAttribute(color, FOREGROUND_GREEN);
		cout << "\t\tCONGRATULATIONS!" << endl;
		cout << "\tYou answered " << rightAnsver << " questions correctly " << endl;
		cout << "YOUR EARNING POINTS: " << bal << endl;
		SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	else {
		SetConsoleTextAttribute(color, FOREGROUND_RED);
		cout << "\tYou didn't give any correct answer(" << endl;
		SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
}



void init(){
	ifstream fin;
	fin.open("quizzes.txt");
	bool isOpen = fin.is_open();
	if (isOpen == true) {
		while (!fin.eof()) {
			Quiz getQuiz;
			fin >> getQuiz.quizName;
			if (getQuiz.quizName != "") {
				for (int i = 0; i < questionNumb; i++) {
					fin >> getQuiz.description[i].question;
					fin >> getQuiz.description[i].answer;
				}
			}
			else {
				break;
			}
			pushInGlobalArr(getQuiz);
		}
	}
	else {
		cout << "Error: file not open!" << endl;
	}
}
void addquiz(){
	ofstream fout;
	fout.open("quizzes.txt", fstream::app);
	bool isOpen = fout.is_open();
	if (isOpen == true) {
		Quiz* temp = new Quiz[countQuizzes + 1];
		for (int i = 0; i < countQuizzes; i++) {
			temp[i] = arrQuizzes[i];
		}
		cout << "Enter name for Quiz: " << endl;
		cin >> temp[countQuizzes].quizName;
		
		for (int i = 0; i < questionNumb; i++){
			cout << "Enter "<<i+1<<" question for this quiz: "<<endl;
			cin >> temp[countQuizzes].description[i].question;
			cout << "Enter right answer for this question: " << endl;
			cin >> temp[countQuizzes].description[i].answer;
		}
		fout << temp[countQuizzes].quizName << endl;
		for (int i = 0; i < questionNumb; i++) {
			fout << temp[countQuizzes].description[i].question << endl;
			fout << temp[countQuizzes].description[i].answer << endl;
		}
		countQuizzes++;
		arrQuizzes = new Quiz[countQuizzes];
		for (int i = 0; i < countQuizzes;i++) {
			arrQuizzes[i] = temp[i];
		}
		delete temp;
	}
	else {
		cout << "Error: file not opened!" << endl;
	}
}

void showAllQuizzes(){
	cout << "\t\tALL QUIZES: " << endl;
	for (int i = 0; i < countQuizzes; i++) {
		cout<<i+1<<". " << arrQuizzes[i].quizName << endl;
	}
	cout << endl;
}


