#include <iostream>
#include <vector>

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

        if (values[greedy] == 0) return total_value;

        if (weight <= capacity) {
            capacity -= weight;
            total_value += value;
        }
        else {
            double frac = (double) capacity/weight;
            capacity = 0;
            total_value += frac * value;
        }
        values[greedy] = 0;
    }

  return total_value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
