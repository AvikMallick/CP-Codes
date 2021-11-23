#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define MAX    	  		  100001 //this is greater than root(R)
const int32_t MOD = 1e9 + 7;

vector<int>* sieve() {
	bool isPrime[MAX];
	// For N numbers we run loop till root(N), same here we are running loop till root(R)
	// to pre-compute all the primes within range of R
	for (int i = 0; i < MAX; i++) isPrime[i] = true;
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < MAX; i++) {
		if (isPrime[i] == true) {
			for (int j = i * i; j < MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}
	vector<int> *primes = new vector<int>();
	primes->pb(2);
	for (int i = 3; i < MAX; i += 2) {
		if (isPrime[i] == true) primes->pb(i);
	}
	return primes;
}

void solve(int l, int r, vector<int>* &primes) {
	bool isPrime[r - l + 1];
	for (int i = 0; i <= r - l; i++) isPrime[i] = true;
	for (int i = 0; primes->at(i)*primes->at(i) <= r; i++) {
		int currPrime = primes->at(i);
		// Just smaller or equal value to l
		int base = (l / currPrime) * currPrime;
		if (base < l) base += currPrime;
		// Mark all multiples within L to R as false
		for (int j = base; j <= r; j += currPrime) {
			isPrime[j - l] = false;
		}
		// There may be a case where base is itself a prime number
		if (base == currPrime) isPrime[base - l] = true;
	}
	for (int i = 0; i <= r - l; i++) {
		if (isPrime[i] == true) cout << i + l << " ";
	}
	cout << '\n';
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> *primes = sieve();
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		/*since there is no prime number lesser than 2 and if we don't do
		this we will get 1 as prime output*/
		if (l < 2) l = 2;
		solve(l, r, primes);
	}
	// solve();

	return 0;
}