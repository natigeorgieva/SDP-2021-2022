#include <iostream>
#include <cmath>
#include <string>
using namespace std;


string s(string str);
bool isPalindrome(string str, int pos = 0);

int main(){

    string str1 = "abcdefggfedcba",
           str2 = "abcdefgafedcba";

    cout<<str1<< " is"<<s(str1)<<" palindrome"<<endl;
    cout<<str2<< " is"<<s(str2)<<" palindrome"<<endl;
}

string s(string str){
    if(isPalindrome((str))){
        return "";
    }else{
        return "n't";
    }
}

bool isPalindrome(string str, int pos){

    if(pos >= str.length()/2){
        return true;
    }

    if(pos < str.length()/2 && str[pos] == str[str.length() -1 -pos]){
        return isPalindrome(str, pos+1);
    }

    return false;

}
