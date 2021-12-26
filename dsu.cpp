struct dsu {
	int n;
	vector<int> parent, ranks;
	vector<vector<int>> edges;

	void makeset(int rn) {
		n = rn;
		parent = vector<int>(n);
		ranks = vector<int>(n);
		fill(ranks.begin(), ranks.end(), 0);
		for (int i = 0; i < n; i++) parent[i] = i;
		edges = vector<vector<int>>(n);
	}

	int findParent(int node) {
		if (node == parent[node]) return node;
		return (parent[node] = findParent(parent[node]));
	}

	void merge(int u, int v) {
		int p1 = findParent(u);
		int p2 = findParent(v);
		if (p1 == p2) return;
		edges[u].push_back(v);
		edges[v].push_back(u);
		if (ranks[p1] < ranks[p2]) {
			parent[p1] = p2;
		}
		else if (ranks[p1] > ranks[p2]) {
			parent[p2] = p1;
		}
		else {
			parent[p2] = p1;
			ranks[p1]++;
		}
	}
};
