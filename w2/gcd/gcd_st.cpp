#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::rand;

int gcd_e(int a, int b) {
    if (b==0) return a;
    else gcd_e(b,a%b);
}


int gcd_n(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int main() {

    while (true) {
        const int max = 1000000000;
        int a = rand()%max+1;
        int b = rand()%max+1;
        int g1 = gcd_n(a,b);
        int g2 = gcd_e(a,b);

        cout << a << '\t' << b << '\t'
            << g1 << '\t' << g2 << '\n';

        if (g1 != g2) break;

    }

  return 0;
}
