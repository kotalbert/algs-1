#include <iostream>
// Efficient Fibonacci Number

using std::cin;
using std::cout;

long long fib_array(int n) {

    long long a[n+1];
    a[0] = 0;
    a[1] = 1;

    for (int i=2; i<=n; i++) {
        a[i] = a[i-1] + a[i-2];
    }
    return a[n];
}


int main() {
    int n;
    cin >> n;
    cout << fib_array(n)<<'\n';
    return 0;

}
