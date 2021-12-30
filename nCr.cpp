// nCr using preComputaton if factorial and inverse factorial
// Initialize N as Needed
int N = 1000005;
vi fact(N + 1, 1);
vi ifact(N + 1, 1);
int nCr(int n, int r) {
	int ans = fact[n];
	ans = mod_mul(ans, ifact[r]);
	ans = mod_mul(ans, ifact[n - r]);
	return ans;
}
/* initialization of fact & ifact */
    for(int i = 2; i <= N; i++) {
        fact[i] = mod_mul(i, fact[i - 1]);
    }
    ifact[N] = inv(fact[N]);
    for (int i = N - 1; i > 0; i--) {
        ifact[i] = mod_mul(i + 1, ifact[i + 1]);
    }
/********************************/
