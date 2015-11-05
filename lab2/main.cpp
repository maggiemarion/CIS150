#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void welcome(string& fullname, int& studnum)
{
	cout << "Please enter the student's full name: ";
	getline(cin, fullname, '\n');
	cout << "Enter the student's ID number: ";
	cin >> studnum;
	cout << endl;
}

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

double examAverage(double exam1, double exam2)
{
	double total = exam1 + exam2;
	return total / 2;
}

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

void printExam(double exam1Score, double exam2Score, double examAverage, double weight)
{
	cout << "Exam 1: " << exam1Score << "  Exam 2: " << exam2Score << endl << "Exam Average: " << examAverage << endl << "Exam Percentage of Student Grade: " << weight * 200 << "%\n";
	cout << endl;
}


double programAverage(double program1, double program2, double program3)
{
	double total = program1 + program2 + program3;
	return total / 3;
}


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

void printProgram(double program1Score, double program2Score, double program3Score, double programAverage, double weight)
{
	cout << "Program 1: " << program1Score << "  Program 2: " << program2Score << "  Program 3: " << program3Score << endl << "Program Average: " << programAverage << endl << "Program Percentage of Student Grade: " << weight * 100 << "%\n";
	cout << endl;
}

double labAverage(double lab1, double lab2, double lab3, double lab4)
{
	double total = lab1 + lab2 + lab3 + lab4;
	return total / 4;
}

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


void printLab(double lab1Score, double lab2Score, double lab3Score, double lab4Score, double labAverage, double weight)
{
	cout << "Lab 1: " << lab1Score << "  Lab 2: " << lab2Score << "  Lab 3: " << lab3Score << endl << "  Lab 4: " << lab4Score << endl << "Lab Average: " << labAverage << endl << "Lab Percentage of Student Grade: " << weight * 100 << "%\n";
	cout << endl;
}




int main()
{
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

	}
	



	system("pause");
	return 0;
}
