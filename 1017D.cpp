#include <bits/stdc++.h>
using namespace std;
template<typename T>
void _debug(const char* name, T&& value) {
    cerr << name << " = " << value << endl;
}
template<typename T, typename... Args>
void _debug(const char* names, T&& value, Args&&... args) {
    const char* comma = strchr(names, ',');
    cerr.write(names, comma - names) << " = " << value << " | ";
    _debug(comma + 1, args...);
}

#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define RREP(i,n) for(int i=n-1; i>=0; i--)
#define mod 1000000007

void solve() {
    int n, m, q; cin >> n >> m >> q;
    int N = 1 << n;
    int FULL = N - 1;
    vector<int> bitWeight(n);
    vector<int> w(n); REP(i, n) cin >> w[i];
    // Our mask is built from left to right,
    // so bit 0 represents the last character.
    for (int i = 0; i < n; i++) {
        bitWeight[i] = w[n - 1 - i];
    }
    vector<int> cnt(N, 0);
    REP(i, m) {
        string s; cin >> s;
        int mask = 0;
        for (char c : s) mask = (mask << 1) | (c - '0');
        cnt[mask]++;
    }

    // subsetSum[mask] = sum of weights of set bits.
    vector<int> subsetSum(N, 0);

    for (int mask = 1; mask < N; mask++) {
        int bit = __builtin_ctz(mask);

        subsetSum[mask] = subsetSum[mask & (mask - 1)] + bitWeight[bit];
    }

    // pref[x][k] = number of strings y where
    // Wu(x, y) <= k.
    vector<array<int, MAX_K + 1>> pref(N);

    for (auto &row : pref) {
        row.fill(0);
    }

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (cnt[y] == 0) continue;

            // Bits that are equal in x and y.
            int equalMask = FULL ^ (x ^ y);

            int wu = subsetSum[equalMask];

            if (wu <= MAX_K) {
                pref[x][wu] += cnt[y];
            }
        }
    }

    // Convert exact Wu values into prefix sums.
    for (int x = 0; x < N; x++) {
        for (int k = 1; k <= MAX_K; k++) {
            pref[x][k] += pref[x][k - 1];
        }
    }

    // Answer queries in O(1).
    while (q--) {
        string t;
        int k;
        cin >> t >> k;

        int mask = 0;
        for (char c : t) {
            mask = (mask << 1) | (c - '0');
        }

        cout << pref[mask][k] << '\n';
    }
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}