#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (ll i = a; i < b; i++)

int main(){
    int n; cin >> n;
    FOR(i, 1, n+1){
        // initial code was for i > 4, but function works for all i
        // x = 4*[2] + 8*[3] + 4*(i-3)*[4] + 4*(i-4)*[6] + (i-4)*(i-4)*[8]
        ll x = 8*i*i - 24*i + 16;
        cout << ((i*i)*(i*i-1) - x)/2 << "\n";
    }
}