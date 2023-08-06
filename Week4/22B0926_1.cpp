#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<int> vc;
#define pb push_back
#define F first
#define S second

vi adj[100005];
bool vis[100005];
vi cyc;

bool dfs(int s, int p){
    vis[s] = 1;
    for (auto i: adj[s]) {
        cyc.pb(i);
        if (!vis[i]) {
            if (dfs(i,s)) {return 1;}
        }
        else if (i!=p) {
            return 1;
        }
        cyc.pop_back();
    }
    return 0;
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1; i <= n; i++){
        cyc.pb(i);
        if (!vis[i] && dfs(i,0)){
            vi ans = {*cyc.rbegin()};
            for (auto j = cyc.rbegin() + 1; j != cyc.rend(); j++){
                ans.pb(*j);
                if (*j == *cyc.rbegin()) break;
            }
            cout << ans.size() << "\n";
            for (auto i: ans)  cout << i << " ";
            return;
        }
        cyc.pop_back();
    }
    cout << "IMPOSSIBLE" << "\n";
}

int main(){
    int t = 1;
    while (t--) {
        solve();
    }
}
