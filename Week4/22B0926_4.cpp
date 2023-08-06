#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int maxN = 200001;
vector<int> graph[maxN];
int subtree[maxN];

ll ans = 0;
int cnt[maxN]{1}, mx_depth;
bool processed[maxN];

int n, k; // Declared outside of the functions to avoid scope issues

int get_subtree_sizes(int node, int parent = 0) {
    subtree[node] = 1;
    for (int i : graph[node]) {
        if (!processed[i] && i != parent) {
            subtree[node] += get_subtree_sizes(i, node);
        }
    }
    return subtree[node];
}

int get_centroid(int desired, int node, int parent = 0) {
    for (int i : graph[node]) {
        if (!processed[i] && i != parent && subtree[i] >= desired) {
            return get_centroid(desired, i, node);
        }
    }
    return node;
}

void get_cnt(int node, int parent, bool filling, int depth = 1) {
    if (depth > k) return;
    mx_depth = max(mx_depth, depth);
    if (filling) cnt[depth]++;
    else ans += cnt[k - depth];
    for (int i : graph[node]) {
        if (!processed[i] && i != parent) {
            get_cnt(i, node, filling, depth + 1);
        }
    }
}

void centroid_decomp(int node = 1) {
    int centroid = get_centroid(get_subtree_sizes(node) >> 1, node);
    processed[centroid] = true;
    mx_depth = 0;
    for (int i : graph[centroid]) {
        if (!processed[i]) {
            get_cnt(i, centroid, false);
            get_cnt(i, centroid, true);
        }
    }
    fill(cnt + 1, cnt + mx_depth + 1, 0);
    for (int i : graph[centroid]) {
        if (!processed[i]) {
            centroid_decomp(i);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    centroid_decomp();
    cout << ans;
    return 0;
}
