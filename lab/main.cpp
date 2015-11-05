//
//  main.cpp
//  lab
//
//  Created by Christian Munte on 9/21/15.
//  Copyright © 2015 Christian Munte. All rights reserved.
//


#include <iostream>
#include <string>
using namespace std;

void welcome(string& fullname,int& stunum){ //you already know what this is
    cout << "Enter the etudent's full name: ";
    getline(cin,fullname,'\n');
    cout << "Enter the student's ID # ";
    cin >> stunum; }

char getLetter(float grade){ //geta grade
    if (grade<60.0) {
        return 'E';
    } else if (60.0>=grade<70.0){
        return 'D';
    } else if (70.0>=grade<80.0) { //checks where the grade is..
        return 'C'; //returns a letter..
    } else if (80.0>=grade<90.0) {
        return 'B';
    } else if (grade>=90.0) {
        return 'A';
    } else { return ' '; } } //unless it fails

float examAverage(float exam1,float exam2){ //collects data
    float total=exam1+exam2; //adds to later math
    return total/2; } //maths

void getExam(float& exam1P,float& exam2P,float points){ //collects data to return
    float exam1, exam2;
    cout << "Enter the first exam grade: ";
    cin >> exam1; //gets points *sanitize input* (exam1 = sanitize(points); Why 'points'? to check if input is valid. (portable)
    exam1P = (exam1/points)*100; //converts points to percentage
    cout << "Enter the second exam grade: ";
    cin >> exam2;
    exam2P = (exam2/points)*100; }

void printExam(float exam1P, float exam2P,float examAverage, float weight){
    cout << "Exam 1: " << exam1P << "   Exam 2: " << exam2P << endl << "Exam Average: " << examAverage << endl << "Exam Percentage of Student Grade: " << weight*100 << "%\n"; } //woo, prints stuff

void getProgram(float& program1P,float& program2P,float program3P,float points){ //collects data to return
    float program1, program2,program3;
    cout << "Enter the first program grade: ";
    cin >> program1; //gets points
    program1P = (program1/points)*100; //converts points to percentage
    cout << "Enter the second program grade: ";
    cin >> program2;
    program2P = (program2/points)*100;
    cout << "Enter the third program grade: ";
    cin >> program3;
    program3P = (program3/points)*100; }

float programAverage(float pgrm1,float pgrm2,float pgrm3) { //collects data
    float total=pgrm1+pgrm2+pgrm3; //adds to later math
    return total/3; } //maths

void printProgram(float program1P, float program2P,float program3P,float programAverage,float weight){
    cout << "Program 1: " << program1P << "   Program 2: " << program2P << "   Program 3:" << program3P << endl << "Program Average: " << programAverage << endl << "program Percentage of Student Grade: " << weight*100 << "%\n"; } //woo, prints stuff

void getLab(float& lab1P,float& lab2P,float lab3P,float& lab4P,float points){ //collects data to return
    float lab1,lab2,lab3,lab4;
    cout << "Enter the first Lab grade: ";
    cin >> lab1; //gets points
    lab1P = (lab1/points)*100; //converts points to percentage
    cout << "Enter the second Lab grade: ";
    cin >> lab2;
    lab2P = (lab2/points)*100;
    cout << "Enter the third Lab grade: ";
    cin >> lab3;
    lab3P = (lab3/points)*100;
    cout << "Enter the fourth Lab grade: ";
    cin >> lab4;
    lab4P = (lab4/points)*100; }

float labAverage(float lab1,float lab2,float lab3,float lab4) { //collects data
    float total=lab1+lab2+lab3+lab4; //adds to later math
    return total/4; } //maths

void printLab(float lab1P, float lab2P,float lab3P,float lab4P,float programAverage,float weight){
    cout << "Program 1: " << lab1P << "   Program 2: " << lab2P << "   Program 3:" << lab3P << "   Lab 4: " << lab4P << endl << "Program Average: " << programAverage << endl << "program Percentage of Student Grade: " << weight*100 << "%\n"; } //woo, prints stuff

int main(){
    const float WEIGHT = 0.25; //weight for assignments
    const int EXAM = 30;
    const int PROGRAM = 25;
    const int LAB = 25;
    string fullname;
    int studentid;
    float exam1,exam2,program1,program2,program3,lab1,lab2,lab3,lab4; //variables
    welcome(fullname,studentid); //gets that
    cout << fullname << " " << studentid << endl; //prints that
    getExam(exam1,exam2,EXAM); //gets exam stuff
    printExam(exam1,exam2,examAverage(exam1,exam2),WEIGHT); //prints exam stuff
    getProgram(program1,program2,program3,PROGRAM);
    printProgram(program1,program2,program3,programAverage(program1,program2,program3),WEIGHT);
    getLab(lab1,lab2,lab3,lab4,LAB);
    printLab(lab1,lab2,lab3,lab4,labAverage(lab1,lab2,lab3,lab4),WEIGHT);
    return 0; }
