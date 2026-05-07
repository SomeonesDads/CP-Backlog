#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
const int G = 3; 
 
// FERMAT GBS
ll modpow(ll a, ll e, ll mod) {
    ll r = 1;
    while (e > 0) {
        if (e & 1) r = r * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return r;
}
 
void ntt(vector<ll>& a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        ll wlen = modpow(G, (MOD - 1) / len, MOD);
        if (invert) wlen = modpow(wlen, MOD - 2, MOD);
        for (int i = 0; i < n; i += len) {
            ll w = 1;
            for (int j = 0; j < len / 2; j++) {
                ll u = a[i + j], v = a[i + j + len / 2] * w % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                w = w * wlen % MOD;
            }
        }
    }
    if (invert) {
        ll inv_n = modpow(n, MOD - 2, MOD);
        for (ll& x : a) x = x * inv_n % MOD;
    }
}
 
vector<ll> multiply(vector<ll> a, vector<ll> b) {
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    a.resize(n);
    b.resize(n);
    ntt(a, false);
    ntt(b, false);
    for (int i = 0; i < n; i++)
        a[i] = a[i] * b[i] % MOD;
    ntt(a, true);
    return a;
}
 
vector<ll> multiplyCyclic(const vector<ll>& A, const vector<ll>& B, int modLen) {
    auto C = multiply(A, B);
    vector<ll> res(modLen);
    for (int i = 0; i < C.size(); i++)
        res[i % modLen] = (res[i % modLen] + C[i]) % MOD;
    return res;
}
 
vector<ll> polyPower(vector<ll> base, long long exp, int modLen) {
    vector<ll> res(modLen);
    res[0] = 1;
    while (exp > 0) {
        if (exp & 1)
            res = multiplyCyclic(res, base, modLen);
        base = multiplyCyclic(base, base, modLen);
        exp >>= 1;
    }
    return res;
}
 
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
 
int powerMod(int x, unsigned int y, int p) {
    long long res = 1;
    x %= p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y >>= 1;
        x = (1LL * x * x) % p;
    }
    return (int)res;
}
 
void findPrimeFactors(unordered_set<int>& s, int n) {
    while (n % 2 == 0) {
        s.insert(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2)
        while (n % i == 0) {
            s.insert(i);
            n /= i;
        }
    if (n > 2) s.insert(n);
}
 
int findPrimitive(int n) {
    unordered_set<int> s;
    if (!isPrime(n)) return -1;
    int phi = n - 1;
    findPrimeFactors(s, phi);
    for (int r = 2; r <= phi; r++) {
        bool flag = false;
        for (auto f : s) {
            if (powerMod(r, phi / f, n) == 1) {
                flag = true;
                break;
            }
        }
        if (!flag) return r;
    }
    return -1;
}
 
vector<int> buildDiscreteLog(int g, int  m) {
    vector<int> log_table( m, -1);
    int val = 1;
    for (int e = 0; e <  m - 1; e++) {
        log_table[val] = e;
        val = (1LL * val * g) %  m;
    }
    return log_table;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; ll K; int m; ll l;
    cin >> n >> K >> m >> l;
    vector<int> S(n);
    for (int i = 0; i < n; i++) cin >> S[i];
    int g = findPrimitive( m);
    auto log_table = buildDiscreteLog(g,  m);
    if (K %  m == 0) {
        cout << 0;
        return 0;
    }
    vector<ll> freq( m - 1);
    for (int s : S)
        if (s %  m != 0)
            freq[log_table[s %  m]]++;
    vector<ll> poly = polyPower(freq, l, m - 1);
    int eK = log_table[K %  m];
 
    cout << poly[eK] % MOD << "\n";
}