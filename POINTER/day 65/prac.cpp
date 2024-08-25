#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(const char *str) {
  // Check for palindrome 
   

}

int main() {
    const char *palindrome1 = "level";
    const char *palindrome2 = "hello";
   cout << "Is '" << palindrome1 << "' a palindrome? " << (isPalindrome(palindrome1) ? "Yes" : "No") <<endl;
    cout << "Is '" << palindrome2 << "' a palindrome? " << (isPalindrome(palindrome2) ? "Yes" : "No") <<endl;
    return 0;
}
