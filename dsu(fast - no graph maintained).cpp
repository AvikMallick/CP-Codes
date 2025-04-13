struct dsu {
	int n;
	vector<int> parent;
	vector<int> count;
	vector<int> rank;
	void makeset(int rn) {
		int n = rn;
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
		x = findParent(x), y = findParent(y);
		if (x == y) return;
		if (rank[x] < rank[y])
			swap(x, y);
		else if (rank[x] == rank[y])
			rank[x]++;
		parent[y] = x;
		count[x] += count[y];
		return;
	}

	int size(int x) {
		return count[findParent(x)];
	}

	bool issame(int x, int y) {
		return findParent(x) == findParent(y);
	}
};
