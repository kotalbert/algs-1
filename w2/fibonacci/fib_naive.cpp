#include <iostream>

// Naive Fibonacci Number

using std::cin;
using std::cout;

int fib_naive(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fib_naive(n-1) + fib_naive(n - 2);
}

void test_fib() {
    cout << "Enter number \n";
    int n;
    cin >> n;
    cout << fib_naive(n)<<'\n';

}

int main() {
    test_fib();
    return 0;
}
