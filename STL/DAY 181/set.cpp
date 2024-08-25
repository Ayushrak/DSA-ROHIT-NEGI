//it store only unique element also in sorted order;
//logn complexity
//avl tree or red black tree(more powerful)
#include<iostream>
#include<set>
using namespace std;

class Person{
    public:
    int age;
    string name;

    bool operator<(const Person &p) const
    {
        return this->age < p.age;
    }
  
};

int main()
{
    set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);
    s.insert(10);
    s.insert(11);
    s.insert(12);
    s.insert(13);
    s.insert(14);
    s.insert(15);
    s.insert(16);
    s.insert(17);
    s.insert(18);
    s.insert(19);
    s.insert(20);
    s.insert(21);
    s.insert(22);
    s.insert(23);
    s.insert(24);
    s.erase(344);

    for(auto it =s.begin(); it !=s.end();it++)
    {
        cout<<*it<<" ";
    }


    //find
    if(s.find(5)!=s.end()){
        cout<<"5 is present";
    }
    else{
        cout<<"5 is not present";
    }

    //count
    if(s.count(5)){
        cout<<"5 is present";
    }
    else{
        cout<<"5 is not present";
    }
    cout<<endl;
    //for descending order
    set<int,greater<int> >s2;
    s2.insert(2);
    s2.insert(1);
    s2.insert(4);
    s2.insert(3);
    s2.insert(5);
    s2.insert(6);
    s2.insert(7);
    s2.insert(8);
    s2.insert(9);
    s2.insert(10);
    s2.insert(11);
    s2.insert(12);
    s2.insert(13);
    s2.insert(14);
    s2.insert(15);
    s2.insert(16);
    s2.insert(17);
    s2.insert(18);
    s2.insert(19);
    s2.insert(20);
    s2.insert(21);
    s2.insert(22);
    s2.insert(23);
    s2.insert(24);

     for(auto it =s2.begin(); it !=s2.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    

    //
    set<Person>s3;
    Person p1,p2,p3;
    p1.age =10, p1.name = "Rohit";
    p2.age = 20, p2.name = "Rohit1";
    p3.age = 30, p3.name = "Rohit2";
    s3.insert(p1);
    s3.insert(p2);
    s3.insert(p3);

    for(auto it=s3.begin(); it!=s3.end();it++)
    {
       //cout<<{*it}.age<<" "<<(*it).name<<endl;
        cout<<it->age<<" "<<it->name<<endl;
    }
}