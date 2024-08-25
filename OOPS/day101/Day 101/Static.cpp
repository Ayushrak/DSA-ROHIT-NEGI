#include<iostream>
using namespace std;

class Customer{
    string name;
    int acc_num,balance;
   static int totalCount;

public:
    static int totaL_Person;
        Customer(string a ,int b,int c){
            name =a;
            acc_num=b;
            balance=c;
            ++totalCount; 
            ++totaL_Person;
        }

        void display(){
            cout<<name<<" "<<acc_num<<" "<<balance;
        }


        void display_Person(){
            cout<<totaL_Person<<endl;
        }

        static void CountNo(){
            //Only access class static member 
            cout<<totalCount<<endl;
        }

      
};

int Customer::totaL_Person=0;

int main(){

    Customer A1("Rohit",1,1000);
    Customer A2("Mohit",2, 1010);
    Customer A3("Mohan",3,2000);
    A1.display_Person(); // Ans 3 because 3 obj call constructor 
   A1.CountNo();  //3
    Customer::totaL_Person =5;
   A1.display_Person(); // 5 declare 5 as public attribute directly
   A1.display(); 
   cout<<endl;
   A2.display_Person(); //5 SAME AS upper

}