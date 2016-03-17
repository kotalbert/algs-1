#include <iostream>

int get_change(int n) {

    //10
    int tens = n/10;
    //std::cout << "tens\t" << tens << '\n';
    n -= tens*10;
    //5
    int fives = n/5;
    //std::cout << "fives\t" << fives << '\n';
    //1
    n -= fives*5;
    //std::cout << "ones\t" << n << '\n';
    return tens + fives + n;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << get_change(n) << '\n';
}
