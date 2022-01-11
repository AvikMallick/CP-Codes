struct dsu {
	int n;
	vector<int> parent;
	vector<int> count;
	vector<int> rank;
	vector<vector<int> edges;
	void makeset(int rn) {
		int n = rn;
		edges.resize(n);
		count.assign(n, 1);
		rank.assign(n, 0);
		parent.assign(n, 0);
		rep(i, 0, n) parent[i] = i;
	}

	int findParent(int x) {
		if (parent[x] == x)
			return x;
		else {
			parent[x] = findParent(parent[x]);
			return parent[x];
		}
	}

	void merge(int x, int y) {
		int p1 = findParent(x);
		int p2 = findParent(y);
		if (p1 == p2) return;
		edges[x].pb(y);
		edges[y].pb(x);
		if (rank[p1] < rank[p2])
			swap(p1, p2);
		else if (rank[p1] == rank[p2])
			rank[p2]++;
		parent[p2] = p1;
		count[p1] += count[p2];
		return;
	}

	int size(int x) {
		return count[findParent(x)];
	}

	bool issame(int x, int y) {
		return findParent(x) == findParent(y);
	}
};
