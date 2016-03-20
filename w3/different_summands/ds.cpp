#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
    vector<int> summands;
    int k = n;
    int l = 1;

    while (true) {

        if (k <= 2*l) {
            summands.push_back(k);
            break;
        }
        else {
           summands.push_back(l);
        }
    k -= l;
    ++l;
    }
    return summands;
}

int main() {
    int n;
    std::cin >> n;
    vector<int> summands = optimal_summands(n);
    std::cout << summands.size() << '\n';

    for (size_t i = 0; i < summands.size(); ++i) {
        std::cout << summands[i] << ' ';
    }
}
