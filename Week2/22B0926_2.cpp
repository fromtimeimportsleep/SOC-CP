#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (ll i = a; i < b; i++)

int no_of_subarrays(ll arr[], int n, ll max_sum){ 
    ll sum = 0;
    int count = 1;
    FOR(i, 0, n){
        if (arr[i] > max_sum) {return INT_MAX;}
        if (sum + arr[i] <= max_sum) {sum += arr[i];}
        else {sum = arr[i]; count++;}
    }
    return count;
}

int main(){
    ll n, k; cin >> n >> k;
    ll arr[n]; FOR(i, 0, n) {cin >> arr[i];}
    ll sum = accumulate(arr, arr+n, sum);
    ll ans = -1;
    for (ll step = sum; step >= 1; step /= 2) {
        while (no_of_subarrays(arr, n, ans+step) > k) {ans += step;}
    }
    cout << ans+1 << "\n";
}