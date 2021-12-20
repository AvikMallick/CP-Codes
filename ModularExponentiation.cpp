// Modular Exponentiation
int mpow(int a, int b, int m) { // pow(a, b) % m
	int x = 1;
	while (b > 0) {
		if (b & 1) {           // fast way of checking if b is odd
			x = (x * a) % m;
		}
		a = (a * a) % m;       // compute the next power of 2
		b >>= 1;               // this is equivalent to b = floor(b / 2)
	}
	return x;
}

// Modular Inverse
int inv(int i) {if (i == 1) return 1; return (M - ((M / i) * inv(M % i)) % M) % M;}

// Modular Multiplication
int mod_mul(int a, int b) {a = a % M; b = b % M; return (((a * b) % M) + M) % M;}

// Modular Addition
ll mod_add(int a, int b) {a = a % M; b = b % M; return (((a + b) % M) + M) % M;}

