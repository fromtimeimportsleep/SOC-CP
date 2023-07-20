#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i = a; i < b; i++)

int main(){
    int t; cin >> t;
    FOR(i, 0, t){
        ll n; cin >> n;
        cout << (n+1)*(n+1) + 1 << "\n";
    }
} 
