#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define input(a) ll a; cin >> a;
#define array(arr, n) ll arr[n]; FOR(i, 0, n) {cin >> arr[i];} 

int main(){
    input(t);
    FOR(i, 0, t){
        input(n);
        array(arr, n);
        bool is_beautiful = false;
        FOR(j, 0, n){
            if (arr[j] <= j+1) {is_beautiful = true; break;}
        }
        if (is_beautiful) {cout << "YES" << "\n";}
        else {cout << "NO" << "\n";}
    }
}