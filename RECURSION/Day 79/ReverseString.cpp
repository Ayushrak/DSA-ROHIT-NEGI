#include<iostream>
using namespace std;


void  Reverse(string &str,int start,int end){
    if(start>=end){
        return ;
    }
    char c = str[start];
    str[start] = str[end];
    str[end] = c;
   return  Reverse(str,start+1,end-1);
}

int main(){
    string str = "ayush";
    Reverse(str,0,4);
    cout<<str;
}


