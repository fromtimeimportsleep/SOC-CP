#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define input(a) ll a; cin >> a;
#define list(arr, n) vector<ll> arr(n); FOR(i, 0, n) {cin >> arr[i];}

int main(){
    input(t);
    FOR(x, 0, t){
        input(n); input(k);
        vector<array<ll ,2>> a(n); FOR(i, 0, n) {cin >> a[i][0]; a[i][1] = i;}
        list(b, n);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ans[n];
        FOR(i, 0, n){
            ll index = a[i][1];
            ans[index] = b[i];
        }
        FOR(i, 0, n) {cout << ans[i] << " ";}
        cout << "\n";
    }
}
