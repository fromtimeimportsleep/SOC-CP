#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (ll i = a; i < b; i++)

int main(){
    int t; cin >> t;
    FOR(o, 0, t){
        ll n, b, k, s; cin >> n >> k >> b >> s;
        if (s < k*b || s > k*b + n*(k-1)) {cout << -1 << "\n"; continue;}
        ll x[n]; FOR(i, 0, n-1) {x[i] = 0;} 
        x[n-1] = k*b;
        if (k == 1) {   //edge case, can't divide by k-1
            FOR(i, 0, n) {cout << x[i] << " ";} cout << "\n";
            continue;
        }
        ll p = (s - k*b)/(k-1); ll q = (s - k*b)%(k-1);
        FOR(i, 0, p) {x[i] += k-1;}
        x[p] += q;
        FOR(i, 0, n) {cout << x[i] << " ";} 
        cout << "\n";
    }
}