//
//  main.cpp
//  test
//
//  Created by Christian Munte on 9/16/15.
//  Copyright (c) 2015 Christian Munte. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void drawRec(int x,int y){
    y=y-2;
    for (int a=0;a<x;a++) { cout << "x"; }
    cout << endl;
    for (int a=0;a<y;a++) {
        cout << "x";
        for (int a=0;a<x-2;a++) { cout << " "; }
        cout << "x\n"; }
    for (int a=0;a<x;a++) { cout << "x"; }
    cout << endl;
}


int main() {
    int x,y;
    cout << "To draw a rectangle, enter the values:\nX: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    drawRec(x,y);
    return 0;
}