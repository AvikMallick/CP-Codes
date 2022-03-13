//efficient code for Dijsktra's Algorithm using adjacency list and priority queue

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

bool myCmp(pair<pii, int> a, pair<pii, int> b) {
    if (a.sc == b.sc) {
        if (a.fr.fr == b.fr.fr) {
            return a.fr.sc < b.fr.sc;
        }
        return a.fr.fr < b.fr.fr;
    }
    return a.sc < b.sc;
}

void solve() {
    int v, e;
    cin >> v >> e;
    vector<vector<pii>> adj(v);
    pair<pii, int> temp[e];
    for (int i = 0;i < e;i++) {
        cin >> temp[i].fr.fr >> temp[i].fr.sc >> temp[i].sc;
    }
    sort(temp, temp + e, myCmp); //sorting to discard the duplicate edges with more distance
    for (int i = 0;i < e;i++) {
        if (i != 0 && temp[i].fr.fr == temp[i - 1].fr.fr && temp[i].fr.sc == temp[i - 1].fr.sc &&
            temp[i].sc >= temp[i - 1].sc) {
            continue;
        }
        adj[temp[i].fr.fr].pb({ temp[i].fr.sc,temp[i].sc });
        adj[temp[i].fr.sc].pb({ temp[i].fr.fr,temp[i].sc });
    }
    bool* visited = new bool[v];
    int* distance = new int[v];
    priority_queue<pii, vector<pii>, greater<pii>> pq; //fr->distance, sc->the vertex
    for (int i = 0;i < v;i++) {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    pq.push({ 0,0 });
    for (int i = 0;i < v - 1;i++) {
        int minVertex = pq.top().sc;
        //it may give a vertex which was pushed in pq, later a better distance for the same 
        //vertex was pushed in pq and then that better distance was used and the vertex got
        //visited but the previously psuhed worse distance still exists in the pq which may
        //be less than any other vertex's distance
        while (visited[minVertex]) {
            pq.pop();
            minVertex = pq.top().sc;
        }
        pq.pop();
        visited[minVertex] = true;
        for (int j = 0;j < adj[minVertex].size();j++) {
            int dist = adj[minVertex][j].sc;
            int u = adj[minVertex][j].fr;
            if (!visited[u]) {
                int newDistance = distance[minVertex] + dist;
                if (newDistance < distance[u]) {
                    distance[u] = newDistance;
                    pq.push({ distance[u],u });
                }
            }
        }
    }
    for (int i = 0;i < v;i++) {
        cout << i << " " << distance[i] << '\n';
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

/******************************************************************************
//using brute force approach for Dijkstra's Algorithm

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

int getMinVertex(bool* visited, int* distance, int n) {
    int ans = -1;
    for (int i = 0;i < n;i++) {
        if (!visited[i] && (ans == -1 || distance[i] < distance[ans])) {
            ans = i;
        }
    }
    return ans;
}

void solve() {
    int v, e;
    cin >> v >> e;
    int** edges = new int* [v];
    for (int i = 0;i < v;i++) {
        edges[i] = new int[v];
        for (int j = 0;j < v;j++) {
            edges[i][j] = 0;
        }
    }
    for (int i = 0;i < e;i++) {
        int x, y, w;
        cin >> x >> y >> w;
        if (edges[x][y] == 0 || edges[x][y] > w) {
            edges[x][y] = w;
            edges[y][x] = w;
        }
    }

    bool* visited = new bool[v];
    int* distance = new int[v];
    for (int i = 0;i < v;i++) {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    for (int i = 0;i < v - 1;i++) {
        int minVertex = getMinVertex(visited, distance, v);
        visited[minVertex] = true;
        for (int j = 0;j < v;j++) {
            if (!visited[j] && edges[minVertex][j] != 0) {
                int newDistance = distance[minVertex] + edges[minVertex][j];
                if (newDistance < distance[j]) {
                    distance[j] = newDistance;
                }
            }
        }
    }
    for (int i = 0;i < v;i++) {
        cout << i << " " << distance[i] << '\n';
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
*******************************************************************************/