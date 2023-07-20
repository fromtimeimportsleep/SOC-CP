#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define input(a) ll a; cin >> a;
#define list(arr, n) ll arr[n]; FOR(i, 0, n) {cin >> arr[i];}

int solve(int a, int b, int memo[500][500]){
    if (a < b) {swap(a, b);}
    if (a % b == 0) {return a/b-1;}
    if (memo[a-1][b-1] >= 0) {return memo[a-1][b-1];}
    int ans = 10000;
    FOR(i, 0, a/2) {
        int check = 1 + solve(i+1, b, memo) + solve(a-i-1, b, memo);
        if (check < ans) {ans = check;}
    }
    FOR (i, 0, b/2) {
        int check = 1 + solve(a, i+1, memo) + solve(a, b-i-1, memo);
        if (check < ans) {ans = check;}
    }
    memo[a-1][b-1] = ans;
    return ans;
}

int main(){
    input(a); input(b);
    int memo[500][500]; FOR(i, 0, 500) {FOR(j, 0, 500) {memo[i][j] = -1;}}
    cout << solve(a, b, memo) << "\n";
}