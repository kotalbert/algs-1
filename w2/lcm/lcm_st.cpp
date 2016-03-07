#include <iostream>
#include <cstdlib>

long long gcd_e(long long a, long long b) {
    if (b==0) return a;
    else gcd_e(b,a%b);
}


long long lcm(long long a, long long b) {
  return (a*b)/gcd_e(a,b);
}

int main() {

    while (true) {
    long long a = std::rand()%1000000000+1;
    long long b = std::rand()%100000000+1;

    //std::cin >> a >> b;
    std::cout << a << '\t' << b << '\t';
    std::cout << lcm(a, b) << std::endl;
    }

    return 0;
}
