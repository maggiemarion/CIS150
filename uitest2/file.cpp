#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include "file.hpp"

using namespace std;

void draw::box() {
    int x=width,y=height;
    y=y-2;
    for (int a=0;a<x;a++) { cout << "x"; }
    cout << endl;
    for (int a=0;a<y;a++) {
        cout << "x";
        for (int a=0;a<x-2;a++) { cout << " "; }
        cout << "x\n"; }
    for (int a=0;a<x;a++) { cout << "x"; }
    cout << endl; }

void draw::setWidth(int input) { width = input; }

void draw::setHeight(int input) { height = input; }