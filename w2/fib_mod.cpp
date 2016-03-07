#include <iostream>
#include <vector>

using std::vector;

typedef long long ll;

bool is_periodic(vector<int> v) {

    size_t h = v.size()%2;
    // check only symmetrical vectors
    if (h=! 0) return false;
    // if vector is not periodic, return false
    for (size_t i=0;i<h;i++) {
        if (v[i] != v[i+h]) return false;
    }
    // return true if vector is periodic.
    return true;
}

// find period of pisano series
int pi(ll m, vector<int> v) {
    v.push_back(0);
    v.push_back(1);
    
    size_t i=2;
    while (true) {
       v[i] = (v[i-1]+v[i-2])%m;
       if (is_periodic(v)) break;
        ++i;
    }
    return v.size()%2;

}

int main() {
    
    vector<int> v;
    ll n,m;
    std::cin >> n >> m;
    int p = pi(m,v);
    std::cout << v[n%p];

    return 0;

}
