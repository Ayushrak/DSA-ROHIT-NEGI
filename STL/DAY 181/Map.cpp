//key and value
//logn comploxity
//sorted
//AVL tree


#include<iostream>
#include<map>
using namespace std;


int main(){
    map<int,int>m;
    multimap<int,int>n; //duplicate element allowed 

    m.insert(make_pair(1,10));
    m.insert(make_pair(2,20));
    m.insert(make_pair(3,30));
    m.insert(make_pair(4,40));
    m.insert(make_pair(5,50));
    m.insert(make_pair(6,60));
    m.insert(make_pair(7,70));
    m[100] = 60; //insert
    m[2]  = 50; //update  not allowed in multimap beacuse of duplicate key

    //search
    cout<<endl;
    if(m.count(1)){
        cout<<m[1]<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }

    //delete
    m.erase(6);

    for(auto it =m.begin(); it !=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    // for(auto p:m){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }

}