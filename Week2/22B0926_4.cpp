#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i = a; i < b; i++)

int pairsSmallerThan(vector<int> nums, int d){  //returns no of pairs <= d in distance
    int output = 0;
    int low = 0;
    FOR (high, 1, nums.size()){
        while (nums[high] - nums[low] > d) {low++;}
        output += high - low;
    }
    return output;
}

int smallestDistancePair(vector<int> nums, int k){
    sort(nums.begin(), nums.end());
    int ans = -1;
    for (int step = nums.back() - nums.front(); step >= 1; step /= 2){
        while (pairsSmallerThan(nums, ans+step) < k-1) {ans += step;}
    }
    return ans+1;
}