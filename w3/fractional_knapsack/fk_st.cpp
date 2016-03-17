#include <iostream>
#include <cstdlib>
#include <vector>

using std::cout;
using std::rand;
using std::vector;

int get_greedy_index(vector<int> weights, vector<int> values) {

    int greedy = 0;
    for (size_t i=0;i<weights.size();i++) {
        double candidate  = (double) values[i]/weights[i];
        double current = (double) values[greedy]/weights[greedy];
        if (candidate > current) greedy = i;
    }
    return greedy;
}


double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double total_value = 0.0;
    while (capacity > 0) {
        int greedy = get_greedy_index(weights, values);
        int weight = weights[greedy];
        int value = values[greedy];
        if (weight <= capacity) {
            capacity -= weight;
            total_value += value;
        }
        else {
            double frac = (double) capacity/weight;
            capacity = 0;
            total_value += frac * value;
        }
        weights.erase(weights.begin() + greedy);
        values.erase(values.begin() + greedy);
    }

  return total_value;
}


int main() {
    int n = 1000;
    int capacity = 2000000;
    vector<int> weights (n);
    vector<int> values (n);
    for (int i=0;i<n;i++) {
        weights[i] = rand()%capacity;
        values[i] = rand()%capacity;
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
