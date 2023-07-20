#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (int i = a; i < b; i++)

int main(){
    int n; cin >> n;
    int x[n]; FOR(i, 0, n) {cin >> x[i];}
    sort(x, x+n);
    
    ll s = 0;
    for (int i = n-1; i > 0; i--){
        for (int j = 0; j < i; j++){
            int temp = x[i]|x[j]; x[j] = x[i]&x[j];
            x[i] = temp;
        }
        s += (ll)x[i]*x[i];
    }
    s += (ll)x[0]*x[0];
    cout << s << "\n";
}