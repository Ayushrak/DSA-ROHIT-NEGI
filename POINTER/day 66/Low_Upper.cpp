#include<iostream>
using namespace std; 
 

 //'a'->97;
 //'A'->65;
 void modifyString(char *str)
{
    while (*str)
    {
        if (*str >= 'a' && *str <= 'z')
        {
            *str = *str - 'a' + 'A';
        }
        str++;
    }
}

int main()
{
    char myString[] = "hello World";
    modifyString(myString);
    cout << myString;  //HELLO WORLD
    return 0;
}
