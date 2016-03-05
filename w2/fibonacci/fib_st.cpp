// Fibonacci Number stress testing

#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;

int fib_naive(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else return fib_naive(n-1) + fib_naive(n-2);
}

long long fib_array(int n) {

    long long a[n+1];
    a[0] = 0;
    a[1] = 1;

    for (int i=2; i<=n; i++) {
        a[i] = a[i-1] + a[i-2];
    }
    return a[n];
}


void stress_test() {
    
    for (int i=0; i<35; i++) {
        cout << i << '\t'
            << fib_naive(i) << "\t\t"
            << fib_array(i) << '\n';
        
    }
}

int main() {
    stress_test();
    return 0;
}
