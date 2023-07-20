#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (ll i = a; i < b; i++)

ll products_made (ll time, ll arr[], ll n){
    ll output = 0;
    FOR(i, 0, n) {output += time/arr[i];}
    return output;
}

int main(){
    ll n, t; cin >> n >> t;
    ll arr[n]; FOR(i, 0, n) {cin >> arr[i];}
    sort(arr, arr+n);
    ll ans = -1;
    for (ll step = t*arr[0]; step >= 1; step /= 2){
        while (products_made(ans+step, arr, n) < t) {ans += step;}
    }
    cout << ans+1 << "\n";
}
