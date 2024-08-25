#include<iostream>
using namespace std;

bool isPrimeHelper(int n, int i) {
    if (i <= 1) {
        return true;  // Base case: if i reaches 1, the number is prime
    }

    if (n % i == 0) {
        return false;  // If n is divisible by i, it's not prime
    }

    return isPrimeHelper(n, i - 1);  // Recursive call with i decremented
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    return isPrimeHelper(n, n - 1);  // Start the recursion with i = n-1
}

int main() {
    int n;
    cin >> n;
    cout << isPrime(n);
    return 0;
}