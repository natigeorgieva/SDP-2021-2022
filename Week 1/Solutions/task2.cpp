#include <iostream>
#include <cmath>
using namespace std;

/**
    Recursive function that finds the
    n-th Fibonacci number
*/
int fib(int n);

int main()
{
    cout<<"The 8th Fibonacci number is: "<<fib(8);

}

int fib(int n){
    if(n == 1 || n == 2){
        return 1;
    }

    return fib(n-1)+ fib(n-2);
}
