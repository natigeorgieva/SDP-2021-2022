#include <iostream>
#include <cmath>
#include <string>
using namespace std;


/**
    Recursive function that prints
    all 'n' long binary numbers

    @param n the length of the numbers
    @param pas the current iteration
    @param currStr the current string that
            contains the beginning of the
            binary number
*/
void print(int n, int pos = 0, string currStr = "");

int main()
{
    print(5);
}

void print(int n, int pos, string currStr){
    if(pos >= n){
        cout<<currStr<<endl;
        return;
    }

    print(n, pos +1, currStr+"0");
    print(n, pos +1, currStr+"1");
}
