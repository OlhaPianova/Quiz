#include "Viktoryna.h"
#include<fstream>
#include<Windows.h>
#include<stdlib.h>
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
Quiz* arrQuizzes;
int countQuizzes=0;
int questionNumb = 0;

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
	delete[] temp;
}
void passQuiz() {
	cout << "\tEnter the quiz number you want to pass: " << endl;
	int number = 0;
	string ansv = "";
	int bal = 0;
	int rightAnsver = 0;
	cin >> number;
	cout << "You pass quizzes: " << arrQuizzes[number - 1].quizName << endl;
	for (int i = 0; i < arrQuizzes[countQuizzes].questionNumb; i++) {
		cout << i + 1 << ". " << arrQuizzes[i].description[i].question << endl;
		cout << "Enter your answer: " << endl;
		cin >> ansv;
		if (ansv == arrQuizzes[number - 1].description[i].answer) {
			SetConsoleTextAttribute(color, FOREGROUND_GREEN);
			cout << "RIGHT - YOU GET 20 POINTS)" << endl;
			SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			bal += 20;
			rightAnsver++;
		}
		else if (ansv != arrQuizzes[number - 1].description[i].answer) {
			SetConsoleTextAttribute(color, FOREGROUND_RED);
			cout << "ERROR" << endl;
			SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

			SetConsoleTextAttribute(color, FOREGROUND_GREEN);
			cout << "RIGHT ANSWER: " << arrQuizzes[number - 1].description[i].answer << endl;
			SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
	}
	if(rightAnsver>0){
	SetConsoleTextAttribute(color, FOREGROUND_GREEN);
	cout << "\tYou answered " << rightAnsver << " questions correctly " << endl;
	cout << "YOUR EARNING POINTS: " << bal << endl;
	SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}
	else if(rightAnsver<1){
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
			string t = "";
			fin >> t;
			int n = atoi(t.c_str());
			getQuiz.description = new Questions[n];
			if (getQuiz.quizName != "") {
				for (int i = 0; i < n; i++) {
					fin >> getQuiz.description[i].question;
					fin >> getQuiz.description[i].answer;
				}
				pushInGlobalArr(getQuiz);
			}
			else {
				break;
			}
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
		cout << "Enter count questions for this quiz: " << endl;
		cin >> questionNumb;
		temp[countQuizzes].questionNumb = questionNumb;
		temp[countQuizzes].description = new Questions[questionNumb];
		for (int i = 0; i < questionNumb; i++){
			cout << "Enter "<<i+1<<" question for this quiz: "<<endl;
			cin >> temp[countQuizzes].description[i].question;
			cout << "Enter right answer for this question: " << endl;
			cin >> temp[countQuizzes].description[i].answer;
		}
		fout << temp[countQuizzes].quizName << endl;
		fout << temp[countQuizzes].questionNumb << endl;
		for (int i = 0; i <temp[countQuizzes].questionNumb ; i++) {
			fout << temp[countQuizzes].description[i].question << endl;
			fout << temp[countQuizzes].description[i].answer << endl;
		}
		countQuizzes++;
		arrQuizzes = new Quiz[countQuizzes];
		for (int i = 0; i < countQuizzes;i++) {
			arrQuizzes[i] = temp[i];
		}
		delete[] temp;
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


