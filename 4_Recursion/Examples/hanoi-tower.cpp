#include <iostream>
#include <sstream>
#include <string>
using namespace std;

//////////////////
//declaration/////
//////////////////
const int PEG_CAPACITY = 10; //the capacity of each peg is static. assume it is enough.

//use a sequential list implementation to represent a peg
//the first element is at the bottom of the peg.
//the last element is on the top of the peg.
//each element is an int, meaning the size of each disk.
//disk size 0 means empty, no element.
class Peg{
public:
    string name;
    int capacity;
    int pegHeight; //how many non-empty elements in the peg
    int disks[PEG_CAPACITY];

    Peg(string str);
    bool initializePeg(int n); //put n disks on the peg.
    int popTopDisk(); //return the size of the top disk, remove the disk from the peg.
    void addTopDisk(int diskSize); //try to add a disk on top of the peg.
    string visualizePegLevel(int level);
    int peekTopDisk();
    int getContinuousGroupHeight(); // from top to bottom, 1, 2, 3, until the continuous series break, e.g., no 4, but directly 5, or reach the bottom.
};

class HanoiTowers{
public:
    Peg A, B, C;
    HanoiTowers(int n);
    void visualizeTowers();
    void moveRecursive(int n, Peg *currentPeg, Peg *targetPeg, Peg *sparePeg);
};

string intToString(int value); //utility function


//////////////////
//implementation//
//////////////////
Peg::Peg(string str) : name(str), capacity (PEG_CAPACITY), pegHeight (0) {
    for(int i = 0; i < PEG_CAPACITY; i++){
        disks[i] = 0;  //make all elements initially empty.
    }
}

bool Peg::initializePeg(int n){
    //assume the peg is empty, did not clear all elements here.
    if (n <= 0){
        cout<< "Error! n <= 0 in initializePeg." << endl;
        return false;
    }
    else if(n > capacity){
        cout<< "Error! n > capacity in initializePeg." << endl;
        return false;
    }
    else{
        int counter = n;
        for(int i = 0; i < n; i++){
            pegHeight++;
            disks[i] = counter;  //put largest disk at the bottom.
            counter--;
        }
        return true;
    }
}

int Peg::popTopDisk(){
    if(pegHeight == 0){
        cout<< "Error! popTopDisk has nothing to pop." <<endl;
        return 0;
    }
    else{
        int output = disks[pegHeight - 1];
        disks[pegHeight - 1] = 0;
        pegHeight--;
        return output;
    }
}

void Peg::addTopDisk(int diskSize){
    if(pegHeight == capacity){
        cout<< "Error! Peg is full. addTopDisk cannot add anything." <<endl;
        return;
    }
    else {
        //need to varify if it is legal to add.
        bool okToAddTop;
        if ( pegHeight == 0 ) okToAddTop = true;
        else if ( disks[pegHeight - 1] > diskSize ) okToAddTop = true;
        else okToAddTop = false;

        if (okToAddTop){
            disks[pegHeight] = diskSize;
            pegHeight++;
        }
        else {
            cout<< "Error! addTopDisk cannot add the disk." <<endl;
        }
    }

}

string Peg::visualizePegLevel(int level){
    //omit input validation here
    //return a string that visualizes the level from the Peg p.
    char spacePixel = (char)32; // space
    char solidPixel = (char)79; // O
    char pegPole = (char)124;   // |

    int diskSize = disks[level];
    string result = "";
    for(int i = 0; i<PEG_CAPACITY ; i++ ){
        if(i < PEG_CAPACITY-diskSize) result += spacePixel;
        else result += solidPixel;
    }
    if(diskSize == 0)result += pegPole;
    else result += intToString(diskSize);

    for(int i = 0; i<PEG_CAPACITY ; i++ ){
        if(i < diskSize) result += solidPixel;
        else 	result += spacePixel;
    }

    return result;
}

int Peg::peekTopDisk(){
    //return the size of the disk on top. return 0 if peg is empty.

    return disks[pegHeight - 1];
}

int Peg::getContinuousGroupHeight(){
    if (pegHeight == 0) return 0;
    int diskSizeCounter = 1;
    int result = 0;
    for(int i = pegHeight - 1; i>=0; i--  ){
        if( this->disks[i] == diskSizeCounter ) {
            result++;
            diskSizeCounter++;
        }
        else break;
    }
    return result;
}

HanoiTowers::HanoiTowers(int n) : A("A") , B("B") , C("C") {
    A.initializePeg(n);
}

void HanoiTowers::visualizeTowers(){
    //make the first line of A B C.
    string strA(PEG_CAPACITY, ' ');
    cout<< strA << A.name << strA << strA << B.name << strA << strA << C.name<< endl;

    //print each line
    for(int i = PEG_CAPACITY-1; i>=0; i--){
        //creat a line of string from each row of the three pegs
        cout<< A.visualizePegLevel(i);
        cout<< B.visualizePegLevel(i);
        cout<< C.visualizePegLevel(i) << endl;
    }
    cout<< endl;
}


//////////////////////////////////////////
//Hanoi Tower solution, recursive.
//3 Peg parameters
void HanoiTowers::moveRecursive(int n, Peg *currentPeg, Peg *targetPeg, Peg *sparePeg){
    cout<< "Call moveRecursive. Move " << n << " disks from " << currentPeg->name << " to " << targetPeg->name << " with help from " << sparePeg->name << endl;

    //////////////////////////////////////////
    //////////////////////////////////////////
    //////////////////////////////////////////

    if(n <= 0) return;  // invalid case

    //ending case
    if (n == 1){
        targetPeg->addTopDisk( currentPeg->popTopDisk() );
        visualizeTowers();
        system("PAUSE");
        //system("read -p 'Press Enter to continue...' var");
    }
    else{
        //step 1: move all but one ring from the current peg to the spare peg
        // with the help of the target peg
        moveRecursive(n - 1, currentPeg, sparePeg, targetPeg);
        //step 2: move the top ring on the current peg to the target peg
        // with the help of the spare peg (not actually used)
        moveRecursive(1, currentPeg, targetPeg, sparePeg);

        //step 3: move the (n - 1) rings (moved from current to spare earlier) to the target peg
        // with the help of the current peg
        moveRecursive(n - 1, sparePeg, targetPeg, currentPeg);
    }



    //////////////////////////////////////////
    //////////////////////////////////////////
    //////////////////////////////////////////
}


string intToString(int value)
{
    ostringstream oss;
    oss << value;
    return oss.str();
}




////////
//main//
////////
int main(){
    int testCaseN = 3;
    HanoiTowers towersProblem(testCaseN);
    towersProblem.visualizeTowers();

    //solving with recursive version

	towersProblem.moveRecursive(testCaseN, &towersProblem.A, &towersProblem.C, &towersProblem.B);
//	cout << "recursive version DONE" << endl;




    return 0;
}


