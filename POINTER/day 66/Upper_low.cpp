#include<iostream>
using namespace std; 
 

 //'a'->97;
 //'A'->65;
 void modifyString(char *str)
{
    while (*str)
    {
        if (*str >= 'A' && *str <= 'Z')
        {
            *str = *str - 'A' + 'a';
        }
        str++;
    }
}

int main()
{
    char myString[] = "HELLO WORLD";
    modifyString(myString);
    cout << myString;  // hello World
    return 0;
}
