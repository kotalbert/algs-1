#include <iostream>
#include <vector>
#include <cstdlib>

// Last digit of a large Fibonacci Number

using std::cout;
using std::cin;
using std::vector;

int get_fibonacci_last_digit(int n) {

    vector<int> v(n+1);
    v[0] = 0;
    v[1] = 1;
    for (int i=2;i<v.size();i++) {
       v[i] = (v[i-1] + v[i-2])%10;
    }
    return v[n];
}


int main() {
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
