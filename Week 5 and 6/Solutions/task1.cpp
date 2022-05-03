#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int MAX_SIZE_D = 100, MAX_SIZE_R = 20;

class Dice {
private:
	int size, lastR;

public:
	Dice();
	Dice(int _size, int _lastR);

	int getSize()const { return size; }
	int getLastR()const { return lastR; }

	void setSize(int _size) { size = _size; }
	void setLastR(int _lastR) { lastR = _lastR; }

	int Roll();
};

Dice::Dice() {
	size = 6;
	lastR = -1;
}

Dice::Dice(int _size, int _lastR) {
	size = _size;
	lastR = _lastR;
}

int Dice::Roll() {
	lastR = rand() % size + 1;
	return lastR;
}

void NullArr(int arr[]){
    for(int i = 0; i < MAX_SIZE_R; i++) arr[i] = 0;
}

int main()
{
	Dice arrDice[MAX_SIZE_D];
	int arrRolls[MAX_SIZE_R];

	NullArr(arrRolls);

	int len, rolls;

	int sizeSidesD;

	cout<<"Enter how many dice you will use [1 - "<<MAX_SIZE_D<<"] :";
	cin>>len;

	if(len<0&&len>MAX_SIZE_D){
        return 0;
	}

	cout<<"Enter how many rolls you want to make: ";
	cin>>rolls;

	for(int i = 0; i < len; i++){
        cout<<"Enter dice "<<i+1<<" sides: ";
        cin>>sizeSidesD;

        arrDice[i].setSize(sizeSidesD);
	}

	for(int i = 0; i < len; i++){
        cout<<"For dice with "<<arrDice[i].getSize()<<" the rolls are: \n";

        for(int j = 0; j < rolls; j++){
            arrRolls[arrDice[i].Roll()-1]++;
        }

        for(int j = 0; j < arrDice[i].getSize(); j++){
            cout<<j+1<<" : "<<arrRolls[j]<<" \\";
        }

        cout<<endl;
        NullArr(arrRolls);
	}
}
