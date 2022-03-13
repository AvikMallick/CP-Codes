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
	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

void updateTree(int* arr, int* tree, int start, int end, int treeNode, int idx, int val) {
	if (start == end) {
		arr[idx] = val;
		tree[treeNode] = val;
		return;
	}

	int mid = (start + end) / 2;
	if (idx <= mid) {
		updateTree(arr, tree, start, mid, 2 * treeNode, idx, val);
	}
	else {
		updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, idx, val);
	}
	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

int query(int* tree, int start, int end, int treeNode, int left, int right) {

	if (start > right || end < left) { //outside the range
		return 0;
	}

	//completely inside the range
	if (start >= left && end <= right) {
		return tree[treeNode];
	}

	//partially inside, partially outside
	int mid = (start + end) / 2;
	int ans1 = query(tree, start, mid, 2 * treeNode, left, right);
	int ans2 = query(tree, mid + 1, end, 2 * treeNode + 1, left, right);
	return ans1 + ans2;
}

void solve() {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0;i < n;i++) cin >> arr[i];
	int* tree = new int[4 * n];
	mem1(tree);
	buildTree(arr, tree, 0, n - 1, 1);

	int idx, value; //update index and update value
	cin >> idx >> value;
	updateTree(arr, tree, 0, n - 1, 1, idx, value);

	int left, right; //left and right range for queries
	cin >> left >> right;

	int ans = query(tree, 0, n - 1, 1, left, right);
	cout << ans << '\n';

	//for printing the nodes of the segment tree
	// for (int i = 1;i < 4 * n;i++) {
	// 	if (tree[i] > 0) cout << tree[i] << '\n';
	// }
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