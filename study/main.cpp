//
//  main.cpp
//  lab
//
//  Created by Christian Munte on 9/21/15.
//  Copyright © 2015 Christian Munte. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//The welcome method displaysy a welcome message to the user, and also asks for them to enter their full name.
//The user needs to enter their first and last name.
//The method will return the name, and it will be stored in the variable fullname
string welcome() {
    string fullname;
    cout << "Welcome to the J-Z Telephone Company account calculation.\n\nPlease enter your full name: ";
    getline(cin, fullname,'\n');
    return fullname; }
//This method collects the name of the customer that is being calculated for.
//The user needs to enter the first name of the customer.
//The program will store the name entered into the variable firstname.
string customername(string fullname) {
    string customer;
    cout << fullname << ", please enter the name of the customer: ";
    getline(cin,customer,'\n');
    return customer; }
//This method will get the account number of the customer.
//The user will enter the digits that represent the customers' accounts.
//The integer will be stored in the varibale account.
int account(string customer) {
    int accountnumber;
    cout << "Please enter the account number for " << customer << ": ";
    cin >> accountnumber;
    return accountnumber; }
//This method will ask the user to enter the address of the customer.
//The user will enter the address, including the city, state, and zip code.
//The variable address will store the integer that is entered.
void address(string customer, string& streetaddress, string& city, string& state, string& zip) {
    cout << "Please enter the billing information for " << customer << ".\nAddress: ";
    cin.ignore();
    getline(cin,streetaddress,'\n');
    cout << "City: ";
    cin >> city;
    cout << "State: ";
    cin >> state;
    cout << "Postal Code: ";
    cin >> zip;
    cout << endl; }
//This method will print out the data
//The user will not have to enter anything. It is void, will return nothing.
//The message will print out and be displayed
void printinfo(string fullname, string customer, int account, string streetaddress, string city, string state, string zip) {
    cout << fullname << ", please verify this is the correct information for " << customer << ":\n";
    cout << "Customer Name: " << customer << endl;
    cout << "Account Number: " << account << endl;
    cout << "Street Address: " << streetaddress << endl;
    cout << "City: " << city << endl;
    cout << "State: " << state << endl;
    cout << "Zip code: " << zip << endl << endl; }
//This method asks the user to enter the number of calls that were placed
//The user will enter an integer value
//The integer will be stored into numberofcalls and then the program will loop for each customer
int calls() {
    int numberofcalls;
    cout << "Please enter the number of calls that were placed: ";
    cin >> numberofcalls;
    while (numberofcalls <= 0) {
        cout << "Please enter a valid number of calls: ";
        cin >> numberofcalls; }
    cout << endl;
    return numberofcalls; }
//This method asks the user for the time of the call
//The user enters a time based on a 24 hour clock
//The time will be stored
int calltime() {
    int time;
    cout << "Enter the time that the call took place based on a 24-hour clock: ";
    cin >> time;
    while (time < 00 || time > 2400) {
        cout << "Please enter a valid time: ";
        cin >> time; }
    return time; }
//This method asks for the length of the call.
//The user enters an integer
//The integer is stored for later calculations
int lengthofcall() {
    int length;
    cout << "Length of the call in minutes: ";
    cin >> length;
    while (length <= 0) {
        cout << "Please enter a valid number: ";
        cin >> length; }
    return length; }
//This method calculates the gross cost of the calls
//The user does not enter anything, but the program multiplies the length of the call by 0.10
//The function returns the total
double gross(int length) { return length * 0.10; }
//This method calculates discounts
//The user doe not enter anything
//The values will be printed
double discounts(int length, double total, int time) {
    double sum;
    double sum2;
    double sumtotal=0;
    double totaldiscount=0;
    if((time <= 1800) && (time > 800)) {
        sum = total * 0.50;
        sumtotal = total - sum; }
    if (length >= 60) {
        sum = total * 0.50;
        sumtotal = total - sum;
        sum2 = sumtotal * 0.15;
        totaldiscount = sumtotal - sum2; }
    return totaldiscount+sumtotal; }
//This method calculates cost of tax
//The user will receive this value based on length of call
//The value will be determined and then printed
double tax(double grosscost) { return grosscost * 0.04; }
//This method prints the data which is separated by value
//The user does not enter anything, the values are previously calculated based on numbers from the user
//The print screen displays the values
void printcall(int time, int length, double discountamount, double taxamount, double grosscost, double netcost) {
    cout << left << setw(15) << "*Call Length*" << left << setw(15) << "*Start Time*" << left << setw(13) << "*Discounts*" << left << setw(13) << "*Taxes*" << left << setw(13) << "*Gross*" << left << setw(13) << "*Net*" << endl;
    cout << left << setw(15) << setprecision(2) << fixed << length << left << setw(15) << setprecision(2) << fixed << time << left << setw(13) << setprecision(2) << fixed << discountamount << left << setw(13) << setprecision(2) << fixed << taxamount << left << setw(13) << setprecision(2) << fixed << grosscost << left << setw(13) << setprecision(2) << fixed << netcost << endl << endl; }
//This method asks the user if there are any more customers
//The user wil input a 'y' or an 'n' to respond
//The program will either terminate or continue
int verification() {
    char verify;
    int answer = 0;
    cout << "Do you have another customer (Y or N)? ";
    cin >> verify;
    if (verify == 'Y' || verify == 'y') { answer = 1; }
    else if (verify == 'N' || verify == 'n') { answer = 0; }
    return answer; }
//This method calls methods and declares variables
//The user iinputs data that is refered to in here
//The program stores the data
int main() {
    string fullname;
    string customer;
    string firstname;
    int time = 0;
    int length = 0;
    double grosscost;
    int numberofcalls;
    int accountnumber;
    string streetaddress;
    string city;
    string state;
    string zip;
    double discountcalls;
    double taxamount;
    double netcost;
    int answer;
    fullname = welcome();
    do {
        customer = customername(fullname);
        accountnumber = account(customer);
        address(customer,streetaddress,city,state,zip);
        printinfo(fullname,customer,accountnumber,streetaddress,city,state,zip);
        numberofcalls = calls();
        for (int count = 0; count < numberofcalls; count++) {
            cout << "Information For Call " << count +1 << endl;
            time = calltime();
            length = lengthofcall();
            grosscost = gross(length);
            discountcalls = discounts(length,grosscost,time);
            taxamount = tax(discountcalls);
            netcost = discountcalls + taxamount;
            printcall(time, length, discountcalls, taxamount, grosscost, netcost);
            //cout << "**********************************************" << endl;
            //cout << "Time: " << time << " Length: " << length << " Discount: " << discountcalls << " Tax: " << taxamount << "GrossCost: " << grosscost << "NetCost: " << netcost << endl; this is redundant, printcall exists.
        }
        answer = verification();
    } while (answer==1);
    return 0;
}