#include <iostream>
#include <cmath>
#include <unistd.h>
#include <string>
#include <array>
using namespace std;

// global vars
int hp=20,lvl=0;
const int SEC=1000000;
string name,area,monster[] ={"Rat","Spider","Zombie","Bat","Welp","Grue","Pig","Kobold","Goblin","Orc","Wight"};

int randNumber(int min, int max) { //Random Number Generator, takes min and max
    srand((int)time(NULL));
    return min + (rand() % (int)(max - min + 1)); }

string mName() { return monster[randNumber(0,10)]; } //returns a random monster name

int mHp(string monst){ //returns the HP of a given monster
    int health []={2,4,5,3,7,6,4,6,7,8,10},b;
    for (int a=0; a<11; a=a+1) {
        if (monster[a].compare(monst)==0) { //reverse lookup for array value to get HP
            b=a;
            break; } }
    return health[b]; }

void fillTxt(string txt, int x) {
    if (txt == "fill") { //makes the - x across
        for (int a=0; x>a; a=a+1) {
            cout << "-";
        }
    } else if (txt == "blank") { //fills amount with x spaces
        for (int a=0; x>a; a=a+1) {
            cout << " ";
        }
    } else if (txt == "top") { //makes the top graphic x wide
        cout << ".";
        fillTxt("fill", x);
        cout << ".\n";
    } else if (txt == "bottom") { //makes the bottom graphic x wide
        cout << "'";
        fillTxt("fill", x);
        cout << "'\n\n";
    } else if (txt == "gap") { //makes a graphic x wide that's empty
        cout << "|";
        fillTxt("blank", x);
        cout << "|\n";
    } else if (txt == "end") { //makes a graphic to trail text x wide
        fillTxt("blank", x);
        cout << "|\n";
    } else if (txt == "finish") { //makes a graphic to end a box x wide
        fillTxt("gap", x);
        fillTxt("bottom", x);
    } else if (txt == "noend") { //exactly what "end" does but with no automatic new line
        fillTxt("blank", x);
        cout << "|";
    }
}

void startGraphic() { //self explanatory, really
    fillTxt("top", 38);
    cout << "|   _____  __    __    ___  ___   _____|\n";
    cout << "|  / ___/_/ /___/ /_  / _  / _   / ___/|\n";
    cout << "| / /__/_  __/_  __/ / , _/ ___// (_ / |\n";
    cout << "|  ___/ /_/   /_/   /_/|_/_/     ___/  |\n";
    fillTxt("gap", 38);
    cout << "|     Graphics Test- best for 8x40     |\n";
    fillTxt("bottom", 38);
    usleep(SEC*1);
    cout << endl << endl; }

void drawGraphic(string find){
    if (find == "playermonster") {
        cout << "|   _|_|_                              |\n";
        cout << "|   _|_|_                       ()     |\n";
        cout << "|    | |                        /|     |\n";
        cout << "|                              /(_)    |\n";
    } else if (find == "monsterplayer") {
        cout << "|    ()                                |\n";
        cout << "|    /|                      _|_|_     |\n";
        cout << "|   /(_)                     _|_|_     |\n";
        cout << "|                             | |      |\n";
    }
}

int playerAttack(int mhp, string mname, string name){ //preforms a player attack to the monster
    int dmg=randNumber(1,5),z=mname.length(),x=name.length(),y,ym,yd; //ignore broken, dmg for damage, x for monter length, x for player langth
    if (hp >= 10) { y=1; } else { y=0; } //fixes graphic for player hp, uses y
    if (mhp >= 10) { ym=1; } else { ym=0; } //fizes graphic for monster hp, uses ym
    if (dmg >= 10) { yd=1; } else { yd=0; } //fixes graphic for damage value, uses yd
    cout << "| >>A " << mname << " with " << mhp << " HP appears";
    fillTxt("end", 15-z-ym);
    cout << "| >>You hit the " << mname << ": deal " << dmg << " damage";
    fillTxt("end", 8-z-yd);
    mhp = mhp-dmg; //takes damange
    if (mhp <= 0) { //if monster is dead
        cout << "| >>The " << mname << " has been defeated!";
        fillTxt("end", 12-z);
        cout << "| >>" << name << "'s HP: " << hp;
        fillTxt("noend", 27-x-y);
        mhp=0;
    } else { //if monster lives
        cout << "| >>" << name << "'s HP: " << hp;
        fillTxt("end", 27-x-y);
        cout << "| >>" << mname << " HP: " << mhp;
        fillTxt("noend", 29-z-ym);
    } return mhp; }

int monsterAttack(int mhp, string mname, string name) { //preformes a monster attack on the player
    int dmg=randNumber(1,5),z=mname.length(),x=name.length(),y,ym,yd; //ignore broken, dmg for damage, x for monter length, x for player langth
    if (hp >= 10) { y=1; } else { y=0; } //fixes graphic for player hp, uses y
    if (mhp >= 10) { ym=1; } else { ym=0; } //fizes graphic for monster hp, uses ym
    if (dmg >= 10) { yd=1; } else { yd=0; } //fixes graphic for damage value, uses yd
    cout << "| >>A " << mname << " with " << mhp << " HP appears";
    fillTxt("end", 15-z-ym);
    cout << "| >>The " << mname << " deals " << dmg << " damage to you";
    fillTxt("end", 9-z-yd);
    hp = hp-dmg; //takes damange
    cout << "| >>" << name << "'s HP: " << hp;
    fillTxt("end", 27-x-y);
    cout << "| >>" << mname << " HP: " << mhp;
    fillTxt("noend", 29-z-ym);
    return mhp; }

void battle() {
    string mname=mName(); //grabs random monster
    int mhp=mHp(mname); //grabs HP
    while (mhp>0) {
        drawGraphic("playermonster");
        mhp=playerAttack(mhp,mname,name); //preformes attack, returns remaining monster health
        usleep(SEC*2);
        if (mhp<=0) {
            cout << endl;
            break; } //time to escape!
        cout << endl;
        fillTxt("gap", 38);
        drawGraphic("monsterplayer");
        mhp=monsterAttack(mhp,mname,name); //preformes attack, returns remaining monster health
        usleep(SEC*2);
        cout << endl;
        fillTxt("gap", 38); } }

void setVar() { //sets things
    string txt;
    cout << "| >>Please select what to set:";
    fillTxt("end", 9);
    cout << "| >>name: sets player name";
    fillTxt("end", 13);
    cout << "| >>level: sets player level";
    fillTxt("end", 11);
    cout << "| >>hp: sets player health";
    fillTxt("end", 13);
    cout << "| >>";
    cin >> txt;
    if (txt == "name") {
        cout << "| >>Set name to: ";
        cin >> name;
        if (name == "Chris") {
            cout << "| >>Welcome back, Chris";
            fillTxt("end", 16);
        }
    } else if (txt == "level" and name == "Chris") {
        cout << "| >>Set level to: ";
        cin >> lvl;
    } else if (txt == "hp" and name == "chris") {
        cout << "| >>Set player heath to: ";
        cin >> hp;
    } else {
        cout << "| >>Invalid operation";
        fillTxt("end", 18);
    } fillTxt("gap", 38); }

string prompt(string input) {
    string text;
    fillTxt("top", 38);
    if (name=="") { name = "Guest"; } //makes the following look better before name is properly set
    if (input == "norm") {
        cout << "| >>" << name << ",please enter a command";
    fillTxt("end", 12 - name.length()); }
    cout << "| >>";
    getline(cin,text,'\n');
    return text; }

void look() {
    if (area=="start") {
        cout << "You look around, there is only a door";
    } else if (area=="forest"){
        cout << "good job";
    }
}

int response(string text) {
    string cmd [] ={"a","attack","l","look","h","heal","lvl","lev","level","cmd","help","set","quit","stop","end"};
    string help = "\nCommands:\nhelp/cmd: Pulls up this help screen\na(ttack): hits target with your weapon\nl(ook): see a description of your environment\nh(eal): heals your character\nlev(el): Levels up your character\nset: set the value of variables\nq(uit)/end: stops the program\n";
    int escape=0,len=(sizeof(cmd)/sizeof(cmd[0])),lkup=0; //len finds the length of the cmd array
    for (int x=0; x<len; x=x+1) { //lookup for command array
        if (text.compare(cmd[x]) == 0) { lkup=x+1; } } //adds one to make things proper
    //cout << lookup << " " << len << " " << cmd[lookup-1] << endl;
    if (lkup >= 1 and lkup <=2) { //attack
        battle();
    } else if (lkup >= 3 and lkup <= 4){ //look
        look();
    } else if (lkup >= 5 and lkup <=6) { //heal
        int up=randNumber(4, 6),y,yu;
        hp = hp+up;
        if (hp >= 10) { y=1; } else { y=0; } //fixes graphic for player hp, uses y
        if (up >= 10) { yu=1; } else { yu=0; } //fixes graphic for heal amount, uses yu
        cout << "| >>HP went up by " << up << " and is now " << hp;
        fillTxt("end", 7-y-yu);
    } else if (lkup >= 7 and lkup <= 9) { //level check/up
        int y;
        if (lvl >= 10) { y=1; } else { y=0; }
        cout << "| >>You are level " << lvl;
        fillTxt("end", 20-y);
    } else if (lkup >= 10 and lkup <= 11){ //help
        cout << help;
    } else if (lkup == 12) { //sets values
        setVar();
    } else if (lkup >= 13 and lkup <= 15) { //quits
        escape = 1;
    }
    return escape; }

int main() {
    startGraphic();
    area="start";
    while (response(prompt("norm"))!=1) { fillTxt("bottom", 38); } //main game loop
    fillTxt("gap", 38);
    cout << "|    Thank you for playing C++ RPG     |\n";
    cout << "|      Made by Christian Munte         |\n";
    fillTxt("bottom", 38);
    return 0; }