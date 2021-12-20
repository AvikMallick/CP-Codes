// Modular Exponentiation
int mpow(int a, int b, int m = M) { int x = 1; while (b > 0) { if (b & 1) { x = (x * a) % m;} a = (a * a) % m; b >>= 1;} return x;}

// Modular Inverse
int inv(int i, int m = M) {if (i == 1) return 1; return (m - ((m / i) * inv(m % i)) % m) % m;}

// Modular Multiplication
int mod_mul(int a, int b, int m = M) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}

// Modular Addition
int mod_add(int a, int b, int m = M) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}

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
