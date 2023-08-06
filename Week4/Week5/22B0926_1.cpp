#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int a, b, c;
    int total_cost = 0;
    int cost = 0;
    int from[101] = {0};
    int to[101] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        total_cost += c;
        if (from[a] || to[b]){
            from[b] = 1;
            to[a] = 1;
            cost += c;
        }
        else {
            from[a] = 1;
            to[b] = 1;
        }
    }
    if (total_cost - cost >= cost) {cout << cost;}
    else {cout << total_cost - cost;}
}
