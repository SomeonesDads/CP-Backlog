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
#define RREP(i,n) for(int i=n-1; i>= 0; i--)
#define mod 1000000007
// #define MAXINT (1e6 + 5)

const int MAXINT = 1e6 + 5;

int parent[200005];
int siz[200005];
int spf[MAXINT]; 

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b]) swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}

void sieve() {
    for (int i = 1; i < MAXINT; i++) spf[i] = i;
    for (int i = 2; i * i < MAXINT; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXINT; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> get_primes(int x) {
    vector<int> primes;
    while (x > 1) {
        int p = spf[x]; primes.push_back(p);
        while (x % p == 0) x /= p;
    }
    return primes;
}

void solve() //Ngerjainnya dikasih tahu???
{

    int n; cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    REP(i, n) {
        parent[i] = i;
        siz[i] = 1;
    }
    unordered_map<int, int> last;
    REP(i, n) {
        vector<int> primes = get_primes(a[i]);
        for (int p : primes) {
            if (last.count(p)) {
                union_sets(i, last[p]);
            }
            last[p] = i;
        }
    }
    unordered_map<int, long long> comp_size;
    REP(i, n) comp_size[find_set(i)]++;
    long long ans = 0;
    for (auto &[bla, k] : comp_size) ans += k * (k - 1) / 2;
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
        sieve();
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
