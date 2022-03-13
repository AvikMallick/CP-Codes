//for giving the minimum element in a given range
//updating means increasing all the elements of a given range by some given value
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

void buildTree(int* arr, int* tree, int start, int end, int treeNode) {
	if (start == end) {
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	buildTree(arr, tree, start, mid, 2 * treeNode);
	buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);
	tree[treeNode] = min(tree[2 * treeNode], tree[2 * treeNode + 1]);
}

//startR -> startRange, endR -> endRange
void updateSegmentTreeLazy(int* tree, int* lazy, int low, int high, int startR, int endR, int currPos, int inc) {
	//outside the range
	if (low > high) {
		return;
	}

	if (lazy[currPos] != 0) {
		tree[currPos] += lazy[currPos];
		if (low != high) { //means this is not a leaf node, so it has children to update in the lazy tree
			lazy[2 * currPos] += lazy[currPos];
			lazy[2 * currPos + 1] += lazy[currPos];
		}
		lazy[currPos] = 0;
	}

	//no overlap, i.e. outside the range
	if (startR > high || endR < low) {
		return;
	}

	//Complete Overlap
	if (low >= startR && high <= endR) {
		tree[currPos] += inc;
		if (low != high) {
			lazy[2 * currPos] += inc;
			lazy[2 * currPos + 1] += inc;
		}
		return;
	}

	//Partial Overlap
	int mid = (low + high) / 2;
	updateSegmentTreeLazy(tree, lazy, low, mid, startR, endR, 2 * currPos, inc);
	updateSegmentTreeLazy(tree, lazy, mid + 1, high, startR, endR, 2 * currPos + 1, inc);
	tree[currPos] = min(tree[2 * currPos], tree[2 * currPos + 1]);
}

int query(int* tree, int* lazy, int low, int high, int startR, int endR, int currPos) {
	if (low > high) {
		return INT_MAX;
	}

	if (lazy[currPos] != 0) {
		tree[currPos] += lazy[currPos];
		if (low != high) {
			lazy[2 * currPos] += lazy[currPos];
			lazy[2 * currPos + 1] += lazy[currPos];
		}
		lazy[currPos] = 0;
	}

	//outside the range
	if (endR<low || startR>high) return INT_MAX;

	//completely inside the range
	if (low >= startR && high <= endR) {
		return tree[currPos];
	}

	int mid = (low + high) / 2;
	int ans1 = query(tree, lazy, low, mid, startR, endR, 2 * currPos);
	int ans2 = query(tree, lazy, mid + 1, high, startR, endR, 2 * currPos + 1);
	return min(ans1, ans2);
}

void solve() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0;i < n;i++) cin >> arr[i];
	int* tree = new int[4 * n];
	int* lazy = new int[4 * n](); //by using () initializing with 0

	buildTree(arr, tree, 0, n - 1, 1);

	int q;
	cin >> q;
	while (q--) {
		char option;
		cin >> option;
		if (option == 'Q') { //means query
			int left, right;
			cin >> left >> right;
			int ans = query(tree, lazy, 0, n - 1, left, right, 1);
			cout << ans << '\n';
		}
		else { //means update
			int left, right, value;
			cin >> left >> right >> value;
			updateSegmentTreeLazy(tree, lazy, 0, n - 1, left, right, 1, value);
		}
	}

}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// int t;
	// cin >> t;
	// while (t--) {
	// 	solve();
	// }
	solve();

	return 0;
}