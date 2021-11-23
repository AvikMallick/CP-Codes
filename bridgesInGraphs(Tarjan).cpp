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
int timer = 0;

void dfs(vector<vector<int>> &edges, int node, int p, vector<int> &in, vector<int> &low, vector<bool> &visited) {
	visited[node] = true;
	in[node] = timer;
	low[node] = timer;
	timer++;
	for (int child : edges[node]) {
		if (child == p) continue;
		if (visited[child]) {
			// this node - child is a back edge
			low[node] = min(low[node], in[child]);
		}
		else {
			// this node - child is a front edge
			dfs(edges, child, node, in, low, visited);
			if (low[child] > in[node]) {
				cout << node << " -> " << child  << " is a bridge\n";
			}
			low[node] = min(low[node], low[child]);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		edges[x].pb(y);
		edges[y].pb(x);
	}
	vector<int> in(n + 1, 0);
	vector<int> low(n + 1, 0);
	vector<bool> visited(n + 1, false);
	dfs(edges, 1, -1, in, low, visited);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}