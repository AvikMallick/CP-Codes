// using Union By Rank and Path Compression by using DSU(Disjoint Set Union)
// to find parent in O(1) time

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

struct edge {
    int src, dest, wt;
};

bool myCmp(edge a, edge b) {
    return a.wt < b.wt;
}

void makeset(int* parent, int* rank, int n) {  //cosntructing the required arrays for Disjoint Set
    for (int i = 0;i < n;i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int getParent(int* parent, int i) {
    if (parent[i] == i) return i;
    return parent[i] = getParent(parent, parent[i]); //path compression
}

void solve() {
    int n, e;
    cin >> n >> e;
    edge* arr = new edge[e];
    for (int i = 0;i < e;i++) {
        cin >> arr[i].src >> arr[i].dest >> arr[i].wt;
    }
    sort(arr, arr + e, myCmp);
    edge* mst = new edge[n - 1]; //for n vertices, MST contains n-1 edges
    int* parent = new int[n];
    int* rank = new int[n];
    makeset(parent, rank, n);
    int count = 0;
    int i = 0;
    while (count < n - 1) {
        edge currEdge = arr[i];
        int src = currEdge.src;
        int dest = currEdge.dest;
        int srcParent = getParent(parent, src);
        int destParent = getParent(parent, dest);
        if (srcParent == destParent) {
            i++;
            continue;
        }
        if (rank[srcParent] > rank[destParent]) { //we directly connect to the src so, we check for srcParent and srcDest
            parent[destParent] = srcParent;

        }
        else if (rank[srcParent] < rank[destParent]) {
            parent[srcParent] = destParent;
        }
        else {
            parent[srcParent] = destParent;
            rank[destParent]++; //since both nodes' ranks are same depth/rank increases
        }
        mst[count] = currEdge;
        count++;
        i++;
    }
    int totalWeight = 0;
    for (int i = 0;i < n - 1;i++) totalWeight += mst[i].wt;
    cout << totalWeight << '\n';
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
/**********************************************************************************/
/*
// using Union Find Algorithm

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

struct edge {
    int src, dest, wt;
};

bool myCmp(edge a, edge b) {
    return a.wt < b.wt;
}

int checkParent(int* parent, int i) { //checks top-most parent
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

// void setParent(int* parent, int dest, int src) { //updating parent[dest] by parent[src]
//     if (parent[dest] == dest) {
//         parent[dest] = parent[src];
//         return;
//     }
//     setParent(parent, parent[dest], src);
//     parent[dest] = parent[src];
// }

void solve() {
    int n, e;
    cin >> n >> e;
    edge* arr = new edge[e];
    for (int i = 0;i < e;i++) {
        cin >> arr[i].src >> arr[i].dest >> arr[i].wt;
    }
    sort(arr, arr + e, myCmp);
    edge* mst = new edge[n - 1]; //for n vertices, MST contains n-1 edges
    int* parent = new int[n];
    for (int i = 0;i < n;i++) parent[i] = i;
    int count = 0;
    int i = 0;
    while (count < n - 1) {
        edge currEdge = arr[i];
        int srcParent = checkParent(parent, currEdge.src);
        int destParent = checkParent(parent, currEdge.dest);
        if (srcParent == destParent) {
            i++;
            continue;
        }
        parent[srcParent] = destParent;
        mst[count] = currEdge;
        count++;
        i++;
    }
    int totalWeight = 0;
    for (int i = 0;i < n - 1;i++) totalWeight += mst[i].wt;
    cout << totalWeight << '\n';
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
*/