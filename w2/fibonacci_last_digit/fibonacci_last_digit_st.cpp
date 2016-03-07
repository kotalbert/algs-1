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

void print_fld(int n) {
    cout << n << '\t' << get_fibonacci_last_digit(n) << '\n';
}

void fld_st() {
    print_fld(0);
    print_fld(3);
    print_fld(327305);
    print_fld(10000000);

    while (true) {
        size_t r = std::rand() % 10000000;
        print_fld(r);
    }

}

int main() {
    fld_st();
  //int n;
  //std::cin >> n;
  //int c = get_fibonacci_last_digit(n);
  //std::cout << c << '\n';
}
