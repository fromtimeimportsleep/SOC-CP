#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define input(a) ll a; cin >> a;
#define array(arr, n) ll arr[n]; FOR(i, 0, n) {cin >> arr[i];} 

int main(){
    input(n); input(x);
    array(coins, n);
    ll count[x+1]; FOR(i, 0, x+1) {count[i] = 0;}
    count[0] = 1;
    FOR(i, 1, x+1) {
        FOR(j, 0, n){
            if (i-coins[j] >= 0) {count[i] += count[i-coins[j]]; count[i]%=1000000007;}
        }
    }
    cout << count[x] << "\n";
}