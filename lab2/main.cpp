#include <iostream>
#include <string>
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
    } else {
        return ' '; //this is importaint!
    }
}

int getInput(int maxPoints) {
    int points;
    cin >> points;
    while (points < 0 || points > maxPoints) {
        cout << points << " is not a valid value, please enter a valid value: ";
        cin >> points;
    }
    return points;
}

double examAverage(double exam1, double exam2)
{
    double total = exam1 + exam2;
    return total / 2;
}

void getExam(double& exam1Score, double& exam2Score, double exampoints)
{
    double exam1, exam2;
    cout << "Enter the first exam grade out of 30: ";
    exam1 = getInput(exampoints);
    exam1Score = (exam1 / exampoints) * 100;
    cout << "Enter the second exam grade out of 30: ";
    exam2 = getInput(exampoints);
    exam2Score = (exam2 / exampoints) * 100;
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
    cout << "Enter the first program grade out of 25: ";
    program1 = getInput(programpoints);
    program1Score = (program1 / programpoints) * 100;
    cout << "Enter the second program grade out of 25: ";
    program2 = getInput(programpoints);
    program2Score = (program2 / programpoints) * 100;
    cout << "Enter the third program grade out of 25: ";
    program3 = getInput(programpoints);
    program3Score = (program3 / programpoints) * 100;

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
    cout << "Enter the first lab grade out of 25: ";
    lab1 = getInput(labpoints);
    lab1Score = (lab1 / labpoints) * 100;
    cout << "Enter the second lab grade out of 25: ";
    lab2 = getInput(labpoints);
    lab2Score = (lab2 / labpoints) * 100;
    cout << "Enter the third lab grade out of 25: ";
    lab3 = getInput(labpoints);
    lab3Score = (lab3 / labpoints) * 100;
    cout << "Enter the fourth lab grade out of 25: ";
    lab4 = getInput(labpoints);
    lab4Score = (lab4 / labpoints) * 100;
}


void printLab(double lab1Score, double lab2Score, double lab3Score, double lab4Score, double labAverage, double weight)
{
    cout << "Lab 1: " << lab1Score << "  Lab 2: " << lab2Score << "  Lab 3: " << lab3Score  << "  Lab 4: " << lab4Score << endl << "Lab Average: " << labAverage << endl << "Lab Percentage of Student Grade: " << weight * 100 << "%\n";
    cout << endl;
}


int main()
{
    for (int count = 0; count < 3; count++)
    {
        string fullname;
        int studnum;
        welcome(fullname,studnum);
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
    }
    system("pause");
    return 0;
}