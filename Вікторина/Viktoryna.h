#pragma once
#include<iostream>
#include<string>
using namespace std;


struct Questions
{
	string question;
	string answer;
};

struct Quiz
{
	string quizName;
	Questions description[5];

};
void init();
void addquiz();
void showAllQuizzes();
void pushInGlobalArr(Quiz quiz);
void passQuiz();
