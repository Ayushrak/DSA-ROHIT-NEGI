#include<iostream>
using namespace std;

//String
bool checkPalindrome( string str,int start,int end){
    if(start>=end){
        return 1;
    }

    if(str[start]!=str[end]){
        return 0;
    }
    else{
          return  checkPalindrome(str,start+1,end-1);
    }   
}

int main(){
    string str = "naman";
    cout<<checkPalindrome(str,0,4)<<endl;
}