#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))

int MAX = 1000000000;
const int32_t MOD = 1e9 + 7;

struct Edge {
    int v1, v2, wt;
};
Edge edges[1000];
int distances[300];

void solve() {
    int n, e;
    cin >> n >> e;
    int src, dest;
    cin >> src >> dest;
    //here we are using edge list, becuase we have to go to each edge n-1 times
    for (int i = 0;i < e;i++) {
        cin >> edges[i].v1 >> edges[i].v2 >> edges[i].wt;
    }
    for (int i = 0;i <= n;i++) distances[i] = INT_MAX;
    distances[src] = 0;
    for (int i = 0;i < n - 1;i++) {
        for (int j = 0;j < e;j++) {
            int u = edges[j].v1;
            int v = edges[j].v2;
            int edgeWeight = edges[j].wt;
            if ((distances[u] != INT_MAX) && ((distances[u] + edgeWeight) < distances[v])) {
                distances[v] = distances[u] + edgeWeight;
            }
        }
    }
    bool check = true;

    //checking if the graph contains -ve weighted cycle
    for (int i = 0;i < e;i++) {
        int u = edges[i].v1;
        int v = edges[i].v2;
        int edgeWeight = edges[i].wt;

        if ((distances[u] != INT_MAX) && ((distances[u] + edgeWeight) < distances[v])) {
            check = false;
            break;
        }
    }

    if (!check || distances[dest] == INT_MAX) {
        cout << MAX << '\n';
    }
    else {
        cout << distances[dest] << '\n';
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