//Program: Grade Calculation
//Programmer: Maggie Marion
//CIS 150
//Date created: November 2, 2015

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//A welcome message will be displayed to the user, and it collects the name of the student and their student number.
void welcome(string& fullname, int& studnum)
{
	cout << "Please enter the student's full name: ";
	getline(cin, fullname, '\n');
	cout << "Enter the student's ID number: ";
	cin >> studnum;
	cout << endl;
}

//This method gets a letter grade based on the point values
char getLetter(double grade)
{
	if (grade < 60.0)
	{
		return 'E';
	}
	else if (60.0 >= grade < 70.0)
	{
		return 'D';
	}
	else if (70.0 >= grade < 80.0)
	{
		return 'C';
	}
	else if (80.0 >= grade < 90.0)
	{
		return 'B';
	}
	else if (grade >= 90.0)
	{
		return 'A';
	}
}

//calculates the average of the two exam scores
double examAverage(double exam1, double exam2)
{
	double total = exam1 + exam2;
	return total / 2;
}

//collects the scores of the exams from the user
void getExam(double& exam1Score, double& exam2Score, double points)
{
	double exam1, exam2;
	do
	{
		cout << "Enter the first exam grade out of 30: ";
		cin >> exam1;
		if (exam1 < 0 || exam1 > 30)
		{
			cout << "Please enter a valid point value: ";
			cin >> exam1;
		}
		exam1Score = (exam1 / points) * 100;
		cout << "Enter the second exam grade out of 30: ";
		cin >> exam2;
		if (exam2 < 0 || exam2 > 30)
		{
			cout << "Please enter a valid point value: ";
			cin >> exam2;
		}
		exam2Score = (exam2 / points) * 100;
	} while ((exam1 < 0 || exam1 > 30) && (exam2 < 0 || exam2 > 30));
}

//prints out to the user the scores of the exams and the percentage
void printExam(double exam1Score, double exam2Score, double examAverage, double weight)
{
	cout << "Exam 1: " << exam1Score << "  Exam 2: " << exam2Score << endl << "Exam Average: " << examAverage << endl << "Exam Percentage of Student Grade: " << weight * 200 << "%\n";
	cout << endl;
}

//calculates the average of the programs
double programAverage(double program1, double program2, double program3)
{
	double total = program1 + program2 + program3;
	return total / 3;
}

//gets program values
void getProgram(double& program1Score, double& program2Score, double& program3Score, double programpoints)
{
	double program1, program2, program3;
	do
	{
		cout << "Enter the first program grade out of 25: ";
		cin >> program1;
		if (program1 < 0 || program1 > 25)
		{
			cout << "Please enter a valid point value: ";
			cin >> program1;
		}
		program1Score = (program1 / programpoints) * 100;
		cout << "Enter the second program grade out of 25: ";
		cin >> program2;
		if (program2 < 0 || program2 > 25)
		{
			cout << "Please enter a valid point value: ";
			cin >> program2;
		}
		program2Score = (program2 / programpoints) * 100;
		cout << "Enter the third program grade out of 25: ";
		cin >> program3;
		if (program3 < 0 || program3 > 25)
		{
			cout << "Please enter a valid point value: ";
			cin >> program3;
		}
		program3Score = (program3 / programpoints) * 100;
	} while ((program1 < 0 || program1 > 25) && (program2 < 0 || program2 > 25) && (program3 < 0 || program3 > 25));
}

//The scores of the programs will be printed out
void printProgram(double program1Score, double program2Score, double program3Score, double programAverage, double weight)
{
	cout << "Program 1: " << program1Score << "  Program 2: " << program2Score << "  Program 3: " << program3Score << endl << "Program Average: " << programAverage << endl << "Program Percentage of Student Grade: " << weight * 100 << "%\n";
	cout << endl;
}

//calculates the average of the 4 labs
double labAverage(double lab1, double lab2, double lab3, double lab4)
{
	double total = lab1 + lab2 + lab3 + lab4;
	return total / 4;
}

//collects the lab scores for all four labs
void getLab(double& lab1Score, double& lab2Score, double& lab3Score, double& lab4Score, double labpoints)
{
	double lab1, lab2, lab3, lab4;
	do
	{
		cout << "Enter the first lab grade out of 25: ";
		cin >> lab1;
		if (lab1 < 0 || lab1 > 25)
		{
			cout << "Please enter a valid point value: ";
			cin >> lab1;
		}
		lab1Score = (lab1 / labpoints) * 100;
		cout << "Enter the second lab grade out of 25: ";
		cin >> lab2;
		if (lab2 < 0 || lab2 > 25)
		{
			cout << "Please enter a valid point value: ";
			cin >> lab2;
		}
		lab2Score = (lab2 / labpoints) * 100;
		cout << "Enter the third lab grade out of 25: ";
		cin >> lab3;
		if (lab3 < 0 || lab3 > 25)
		{
			cout << "Please enter a valid point value: ";
			cin >> lab3;
		}
		lab3Score = (lab3 / labpoints) * 100;
		cout << "Enter the fourth lab grade out of 25: ";
		cin >> lab4;
		if (lab4 < 0 || lab4 > 25)
		{
			cout << "Please enter a valid point value: ";
			cin >> lab4;
		}
		lab4Score = (lab4 / labpoints) * 100;

	} while ((lab1 < 0 || lab1 > 25) && (lab2 < 0 || lab2 > 25) && (lab3 < 0 || lab3 > 25) && (lab4 < 0 || lab4 > 25));
}


//prints the lab scores and the average
void printLab(double lab1Score, double lab2Score, double lab3Score, double lab4Score, double labAverage, double weight)
{
	cout << "Lab 1: " << lab1Score << "  Lab 2: " << lab2Score << "  Lab 3: " << lab3Score << endl << "  Lab 4: " << lab4Score << endl << "Lab Average: " << labAverage << endl << "Lab Percentage of Student Grade: " << weight * 100 << "%\n";
	cout << endl;
}


//prints the scores for every student, and the percentages; this is called 3 times, one per student
void studentPrint(string fullname, int studnum, double exam1, double exam2, double program1, double program2, double program3, double lab1, double lab2, double lab3, double lab4)
{
	cout << fullname << "\t" << studnum << endl;
	cout << "Exam 1: " << exam1 << "\t Exam 2: " << exam2 << endl;
	cout << "Exam Average: " << ((exam1 + exam2) / 2) << endl;
	cout << "Exam Grade Percentage:" << ((exam1 + exam2) / 60)*.5 * 100 << endl;
	cout << endl;

	cout << "Program 1: " << program1 << "\t Program 2: " << program2 << "\t Program 3: " << program3 << endl;
	cout << "Program Average: " << ((program1 + program2 + program3) / 3) << endl;
	cout << "Program Grade Percentage: " << ((program1 + program2 + program3) / 75)*0.25 * 100 << endl;
	cout << endl;

	cout << "Lab 1: " << lab1 << "\t Lab 2: " << lab2 << "\t Lab 3: " << lab3 << "\t Lab 4: " << lab4 << endl;
	cout << "Lab Average: " << ((lab1 + lab2 + lab3 + lab4) / 4) << endl;
	cout << "Lab Grade Percentage: " << ((lab1 + lab2 + lab3 + lab4) / 100) *0.25 * 100 << endl;
	cout << endl;

}

//prints the scores and percentages for the entire class (3 students) and the averages.
void classPrint(double exam1, double exam2, double program1, double program2, double program3, double lab1, double lab2, double lab3, double lab4)
{
	double exam1average = exam1 / 3;
	double exam2average = exam2 / 3;
	double program1average = program1 / 3;
	double program2average = program2 / 3;
	double program3average = program3 / 3;
	double lab1average = lab1 / 3;
	double lab2average = lab2 / 3;
	double lab3average = lab3 / 3;
	double lab4average = lab4 / 3;

	cout << "Class Exam 1 Average: " << exam1 / 3 << "\t Class Exam 2 Average: " << exam2 / 3 << endl;
	cout << "Class Exam Average: " << ((exam1average + exam2average) / 2) << endl;
	cout << endl;
	cout << "Class Program 1 Average: " << program1 / 3 << "\t Class Program 2 Average: " << program2 / 3 << "\t Class Program 3 Average: " << program3 / 3 << endl;
	cout << "Class Program Average : " << ((program1average + program2average + program3average) / 3) << endl;
	cout << endl;
	cout << "Class Lab 1 Average : " << lab1 / 3 << "\t Class Lab 2 Average: " << lab2 / 3 << "\t Class Lab 3 Average: " << lab3 / 3 << "\t Class Lab 4 Average: " << lab4 / 3 << endl;
	cout << "Class Lab Average: " << ((lab1average + lab2average + lab3average + lab4average) / 4) << endl;
	cout << endl;
	cout << "Class Exam Percent: " << ((exam1average + exam2average) / 60) *.5 * 100 << endl;
	cout << endl;
	cout << "Class Program Percent: " << ((program1average + program2average + program3average) / 75) *.25 * 100 << endl;
	cout << endl;
	cout << "Class Lab Percent: " << ((lab1average + lab2average + lab3average + lab4average) / 100) *.25 * 100 << endl;
	cout << endl;

}



int main()
{
	string fullname;
	int studnum;

	double classExam1 = 0;
	double classExam2 = 0;
	double classExamAverage = 0;
	double classProgram1 = 0;
	double classProgram2 = 0;
	double classProgram3 = 0;
	double classProgramAverage = 0;
	double classLab1 = 0;
	double classLab2 = 0;
	double classLab3 = 0;
	double classLab4 = 0;
	double classLabAverage = 0;

	double student1exam1;
	double student1exam2;
	double student1program1;
	double student1program2;
	double student1program3;
	double student1lab1;
	double student1lab2;
	double student1lab3;
	double student1lab4;

	double student2exam1;
	double student2exam2;
	double student2program1;
	double student2program2;
	double student2program3;
	double student2lab1;
	double student2lab2;
	double student2lab3;
	double student2lab4;

	double student3exam1;
	double student3exam2;
	double student3program1;
	double student3program2;
	double student3program3;
	double student3lab1;
	double student3lab2;
	double student3lab3;
	double student3lab4;

	int student1num;
	int student2num;
	int student3num;
	string student1name;
	string student2name;
	string student3name;

	for (int count = 0; count < 3; count++)
	{
		string fullname;
		int studnum;
		welcome(fullname, studnum);
		cout << fullname << " " << studnum << endl;
		const double weight = 0.25;
		const int exam = 30;
		const int program = 25;
		const int lab = 25;
		double exam1, exam2, program1, program2, program3, lab1, lab2, lab3, lab4;
		getExam(exam1, exam2, exam);
		printExam(exam1, exam2, examAverage(exam1, exam2), weight);
		getProgram(program1, program2, program3, program);
		printProgram(program1, program2, program3, programAverage(program1, program2, program3), weight);
		getLab(lab1, lab2, lab3, lab4, lab);
		printLab(lab1, lab2, lab3, lab4, labAverage(lab1, lab2, lab3, lab4), weight);
		cin.ignore(); 

		classExam1 = exam1 + classExam1;
		classExam2 = exam2 + classExam2;
		classExamAverage = examAverage(exam1, exam2) + classExamAverage;
		classProgram1 = program1 + classProgram1;
		classProgram2 = program2 + classProgram2;
		classProgram3 = program3 + classProgram3;
		classProgramAverage = programAverage(program1, program2, program3) + classProgramAverage;
		classLab1 = lab1 + classLab1;
		classLab2 = lab2 + classLab2;
		classLab3 = lab3 + classLab3;
		classLab4 = lab4 + classLab4;
		classLabAverage = labAverage(lab1, lab2, lab3, lab4) + classLabAverage;

		if (count == 0)
		{
			student1name = fullname;
			student1num = studnum;
			student1exam1 = exam1;
			student1exam2 = exam2;
			student1program1 = program1;
			student1program2 = program2;
			student1program3 = program3;
			student1lab1 = lab1;
			student1lab2 = lab2;
			student1lab3 = lab3;
			student1lab4 = lab4;
		}
		if (count == 1)
		{
			student2name = fullname;
			student2num = studnum;
			student2exam1 = exam1;
			student2exam2 = exam2;
			student2program1 = program1;
			student2program2 = program2;
			student2program3 = program3;
			student2lab1 = lab1;
			student2lab2 = lab2;
			student2lab3 = lab3;
			student2lab4 = lab4;
		}
		if (count == 2)
		{
			student3name = fullname;
			student3num=studnum;
			student3exam1 = exam1;
			student3exam2 = exam2;
			student3program1 = program1;
			student3program2 = program2;
			student3program3 = program3;
			student3lab1 = lab1;
			student3lab2 = lab2;
			student3lab3 = lab3;
			student3lab4 = lab4;
		}
	}

	studentPrint(student1name, student1num, student1exam1, student1exam2, student1program1, student1program2, student1program3, student1lab1, student1lab2, student1lab3, student1lab4);
	cout << endl;
	studentPrint(student2name, student2num, student2exam1, student2exam2, student2program1, student2program2, student2program3, student2lab1, student2lab2, student2lab3, student2lab4);
	cout << endl;
	studentPrint(student3name, student3num, student3exam1, student3exam2, student3program1, student3program2, student3program3, student3lab1, student3lab2, student3lab3, student3lab4);
	cout << endl;
	classPrint(classExam1, classExam2, classProgram1, classProgram2, classProgram3, classLab1, classLab2, classLab3, classLab4);
	
	system("pause");
	return 0;
}
