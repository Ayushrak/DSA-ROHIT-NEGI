#include<iostream>
using namespace std;

int countVowels(string &str, int index){

    if(index==-1){
        return 0;
    }
    if(str[index]=='A'|| str[index]=='E'||str[index]=='I'|| str[index]=='O'||str[index]=='U'){
        return 1 + countVowels(str,index-1);
    }
    else{
        countVowels(str,index-1);
    }
}

int main(){
    string str ="AYUSH";
    cout<<countVowels(str,4);

}