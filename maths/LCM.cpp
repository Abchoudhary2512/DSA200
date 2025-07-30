#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int g = gcd(a, b);
    int l = lcm(a, b);

    cout << "GCD: " << g << "\n";
    cout << "LCM: " << l << "\n";
    cout << "GCD * LCM = " << g * l << " == " << a * b << "\n";

    return 0;
}
