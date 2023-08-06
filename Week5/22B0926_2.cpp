#include <iostream>
using namespace std;

void Solve(){
    int n, m, k;
    cin >> n >> m >> k;
    if ((1LL * (n - 1) * n) / 2 < m || m < n - 1){
        cout << "NO" << endl;
        return;
    }
    if (n == 1){
        if (k > 1) {cout << "YES" << endl;}
        else {cout << "NO" << endl;}
    }
    else if (m < (1LL * (n - 1) * n) / 2){
        if (k > 3) {cout << "YES" << endl;}
        else {cout << "NO" << endl;}
    }
    else if (k > 2) {cout << "YES" << endl;}
        else {cout << "NO" << endl;}
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        Solve();
    }
    return 0;
}
