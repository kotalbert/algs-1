#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

typedef long long ll;

ll mpp(vector<ll>& v) {
    
    ll first = -1;
    ll second = -1;

    for (int i=0; i<v.size(); i++) {
        if (v[i] > first) {
            second = first;
            first = v[i];
        }
        else if (v[i] > second) {
            second = v[i];
        }
    }

    return first * second;
}

int main() {
    int n;
    cin >> n;
    vector<ll> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    
    ll result = mpp(numbers);

    cout << result << "\n";
    return 0;
}
