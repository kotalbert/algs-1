#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

typedef unsigned long ulong;

ulong mpp(vector<ulong>& nums) {
    int fi = 0; // index of first largest 
    int si = 0; // index of second largest

    // find index of first largest element
    for (int i=1; i<nums.size(); i++) {
        if (nums[i]>nums[fi]) {
            fi = i;
        }
    }

    // find index of second largest element
    for (int i=1; i<nums.size(); i++) {
        if (i == fi) continue;
        else if (nums[i] > nums[si]) si = i;
    }
    
    return nums[fi] * nums[si];
}

int main() {
    int n;
    cin >> n;
    vector<ulong> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    
    ulong result = mpp(numbers);

    cout << result << "\n";
    return 0;
}
