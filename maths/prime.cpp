#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;      // 0 and 1 are not prime
    if (n == 2) return true;       // 2 is prime
    if (n % 2 == 0) return false;  // even numbers > 2 are not prime

    for (int i = 3; i * i <= n; i += 2) { // only check odd numbers up to sqrt(n)
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isPrime(number))
        cout << number << " is a prime number." << endl;
    else
        cout << number << " is not a prime number." << endl;

    return 0;
}
