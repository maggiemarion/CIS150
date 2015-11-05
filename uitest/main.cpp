#include <iostream>
#include <cmath>
#include <string>
#include <array>
#include <unistd.h>
using namespace std;

string name;

int lookupArray(string array [],string input,int length){ //Find where in a given array input is
    int lookup=0;
    for (int x=0; x<length; x=x+1) {
        if (input.compare(array[x]) == 0) { lookup=x+1; } }
    return lookup; }

int randNumber(int min, int max) { //Random Number Generator, takes min and max
    srand((int)time(NULL));
    return min + (rand() % (int)(max - min + 1)); }

void introduction(){
    string data [] = {"me?","I'm","what?"},input;
    cin >> input;
    int find = sizeof(data)/sizeof(data[0]);
    find = lookupArray(data,input,find);
    if (find==1) {
        cout << "yes, you. What's your name?\n>";
        cin >> name;
    } if (find == 2) {
        cin >> name;
    }
    cout << name << ", eh? I'm James by the way\n";
}

void help(int level){
    if (level==0) {
        cout << "Sorry, I can't give you much help right now.\nAll I can say is try looking around.\n";
    }
}

void look(int area){
    if (area == 0) {
        cout << "It's dark... or bright... or maybe blue?\nWhat's going on here, who are you?\n>";
        introduction();
    }
}

string input(string type){ //does stuff, nobody really knows what though
    string input;
    if (type=="norm") {
        cout << ">";
        getline(cin,input,'\n');
    } else { return "Error: Invalid Type"; }
    
    string data [] = {"y","n","help","look","attack","quit"};
    int find = sizeof(data)/sizeof(data[0]);
    find = lookupArray(data,input,find);
    if (find == 0) { return "Error: Invalid Input";
    } else if (find == 6) { return "Error: End Of Game";
    } else if (find == 3) {
        help(0);
    } else if (find ==4) {
        look(0);
    }
    
    return "ok";
}

int main() {
    string output;
    do { output = input("norm"); } while (output == "ok");
    cout << endl << output << endl;
    return 0; }