#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define int               long long
#define pb                push_back
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define repr(i,a,b)       for(int i=a;i>=b;i--)
#define vi                vector<int>
#define vvi               vector<vector<int>>
#define vbool             vector<bool>
#define vchar             vector<char>
#define vstring           vector<string>
#define vpii              vector<pair>
#define all(x)            (x).begin(), (x).end()
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

//template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; 
// declaration : oset<data_type> s;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const long long INF = 1e18;
const int32_t M = 1e9+7;
const int32_t MM = 998244353;

/*-----------------------------------------------------------------------------------------------------------------*/
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.pb(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int mod_add(int a, int b, int m = M) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_sub(int a, int b, int m = M) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_mul(int a, int b, int m = M) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int inv(int i, int m = M) {if (i == 1) return 1; return (m - ((m / i) * inv(m % i)) % m) % m;}
int mpow(int a, int b, int m = M) { int x = 1; while (b > 0) { if (b & 1) { x = (x * a) % m;} a = (a * a) % m; b >>= 1;} return x;}
/*-----------------------------------------------------------------------------------------------------------------*/

void solve() { 
	
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
