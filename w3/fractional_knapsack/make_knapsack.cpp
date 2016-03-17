#include <iostream>
#include <cstdlib>
#include <vector>

using std::cout;
using std::rand;

int main() {
    int n = 1000;
    int capacity = 2000000;
    cout << n << '\t' << capacity << '\n';

    for (int i=0;i<n;i++) {
       int weight = rand()%capacity;
       int value = rand()%capacity;
       cout << value << '\t' << weight << '\n';
    }

    return 0;
}
