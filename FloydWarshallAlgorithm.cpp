#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))

const int32_t MOD = 1e9 + 7;
int MAX = 1e9;

void solve() {
    int n, e;
    cin >> n >> e;
    int edges[n + 1][n + 1];
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            if (i == j) edges[i][j] = 0;
            else edges[i][j] = INT_MAX;
        }
    }

    for (int i = 0;i < e;i++) {
        int x, y, w;
        cin >> x >> y >> w;
        // multiple edges may exist, so taking the minimum edge
        edges[x][y] = min(edges[x][y], w);
        edges[y][x] = min(edges[y][x], w);
    }

    for (int k = 1;k <= n;k++) {
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= n;j++) {
                if ((edges[i][k] != INT_MAX) && (edges[k][j] != INT_MAX)) {

                    edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
                }
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 1;i <= n;i++) {
        if (edges[i][i] < 0) { //means -ve weight edge cycle exists
            return;
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << min(MAX, edges[a][b]) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    // solve();

    return 0;
}