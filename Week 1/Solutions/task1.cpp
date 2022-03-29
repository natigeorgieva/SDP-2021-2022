#include <iostream>
#include <cmath>
using namespace std;


/**
    A recursive function that sums len
    elements from an array

    @param[in] arr a pointer to the beginning
               of the array
    @param[in] len the number of elements to
                be summed
    @param[in] step the step that the recursion
                is at. Default 0.

    @returns Returns the value of the current iteration,
             if it is prime number, plus the value of the
             next iteration. If step >= len, returns 0.
*/
int recSumArr(int *arr, int len, int step = 0);


/**
    Checks whether the given number is prime

    @param[in] num the number to be checked

    @returns true if num is prime, else returns false;
*/
bool isPrime(int num);

int main()
{
    int arr[] = {5, 12, 432, 7, 23, 45};
    int len = 6;

    cout<<"The sum of the prime numbers is: "<<recSumArr(arr, len);

}

int recSumArr(int *arr, int len, int step)
{
    if(step >= len)
    {
        return 0;
    }

    if(isPrime(arr[step]))
    {
        return arr[step] + recSumArr(arr, len, step+1);
    }
    else
    {
        return recSumArr(arr, len, step+1);
    }
}

bool isPrime(int num)
{

    for(int i = 2; i < sqrt(num); i++)
    {
        if(num % i == 0)
            return false;
    }

    return true;
}
