#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)
const ll MOD = 998244353;
const ll G = 3; // Primitive 
ll pow_mod(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

/**
 * @brief Computes modular inverse using Fermat's Little Theorem
 */
ll mod_inv(ll n, ll mod) {
    return pow_mod(n, mod - 2, mod);
}

/**
 * @brief Finds a primitive root modulo M (M must be prime)
 */
int find_g(int m) {
    int phi = m - 1;
    vector<int> factors;
    int n = phi;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if (n > 1) factors.push_back(n);

    for (int g = 2; g < m; ++g) {
        bool ok = true;
        for (int f : factors) {
            if (pow_mod(g, phi / f, m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
    return -1; // Should not happen
}

/**
 * @brief Number Theoretic Transform (NTT)
 * Assumes a.size() is a power of 2
 */
void ntt(vector<ll> &a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    // Bit-reversal permutation
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    // Butterfly loops
    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = pow_mod(G, (MOD - 1) / len, MOD);
        if (invert) wlen = mod_inv(wlen, MOD);
        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i + j];
                ll v = (a[i + j + len / 2] * w) % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                w = (w * wlen) % MOD;
            }
        }
    }

    if (invert) {
        ll n_inv = mod_inv(n, MOD);
        for (ll &x : a) {
            x = (x * n_inv) % MOD;
        }
    }
}

void solve() {
    int N, K, M;
    ll L;
    cin >> N >> K >> M >> L;

    // --- Step 1 & 2: Find primitive root and compute discrete logs ---
    // The problem seems to assume M is a Fermat prime (e.g., 3, 5, 17, 257, 65537)
    // so that M-1 is a power of 2, which is required for the NTT.
    int g = find_g(M);
    vector<int> dlog(M);
    int p = 1;
    int n = M - 1; // Size of the transform, M-1
    for (int i = 0; i < n; ++i) {
        dlog[p] = i;
        p = (1LL * p * g) % M;
    }

    // Target index
    int k_prime = dlog[K];

    // --- Step 3: Build the counts polynomial C(x) ---
    // C[i] = number of elements in S whose discrete log is i
    vector<ll> C(n, 0);
    REP(i, N) {
        int s;
        cin >> s;
        if (s != 0) { // s=0 is not in the group, but problem says positive integers
            C[dlog[s]]++;
        }
    }

    // --- Step 4: Transform to Frequency Domain (NTT) ---
    // We compute C(x)^L mod (x^(M-1) - 1)
    // This is equivalent to C_hat_k = (NTT(C)_k)^L
    ntt(C, false); // C is now \hat{C}

    // --- Step 5: Pointwise Exponentiation ---
    vector<ll> D(n);
    REP(i, n) {
        D[i] = pow_mod(C[i], L, MOD); // D is now \hat{D}
    }

    // --- Step 6: Transform back (Inverse NTT) ---
    ntt(D, true); // D is now INTT(\hat{D})

    // D[j] is the number of arrays of length L whose product-index sum is j
    cout << D[k_prime] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while(test--){
        solve();
    }
    return 0;
}