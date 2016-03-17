#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::min;

class Item {
    private:
        int value;
        int weight;
        double uv;
    public:
        Item(int v, int w) {
            value = v;
            weight = w;
            if (weight == 0) uv = 0;
            else uv  = (double) value/weight;
        }
        double unit_value() {
            return uv;
        }
        int get_weight() {return weight;}
        int get_value() {return value;}
        void set_uv(double nuv) {uv = nuv;}

};

int get_greedy_index(vector<Item>& items) {
    int greedy=0;
    for (size_t i=0; i<items.size(); i++) {
        double current = items[greedy].unit_value();
        double candidate = items[i].unit_value();
        if (candidate > current) greedy = i;
    }
    return greedy;
}

double get_optimal_value(int capacity, vector<Item>&  items) {
    double value = 0.0;
    while (capacity >0) {
        int greedy = get_greedy_index(items);
        int weight = items[greedy].get_weight();
        int item_value = items[greedy].get_value();
        // stop when returned zero value
        if (items[greedy].unit_value() == 0) return value; 

        if (weight <= capacity) {
            capacity -= weight;
            value += item_value;
        }
        else {
        double frac = (double) capacity/weight;
        capacity = 0;
        value += frac*item_value;
        }
        // set unit value to 0 to exclude from further greedy selections
        items[greedy].set_uv(0.0);
    }

    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<Item> items;

    for (int i = 0; i < n; i++) {
        int v, w;
        std::cin >> v >> w;
        if (v==0 || w==0) continue;
        items.push_back(Item(v,w));
    }
    
    double optimal_value = get_optimal_value(capacity, items);
    std::cout.precision(10);
    std::cout << optimal_value << std::endl;

    return 0;
}
