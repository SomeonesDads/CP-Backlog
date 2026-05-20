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


vector<int> tree;

void update(int node, int l, int r, int ql, int qr, int val) {
    if (ql <= l && r <= qr) {
        tree[node] = min(tree[node], val);
        return;
    }
    int mid = (l + r) / 2;
    if (ql <= mid) update(2 * node, l, mid, ql, qr, val);
    if (qr > mid) update(2 * node + 1, mid + 1, r, ql, qr, val);
}

void push_all(int node, int l, int r, vector<int>& R_max) {
    if (l == r) {
        R_max[l] = tree[node];
        return;
    }
    tree[2 * node] = min(tree[2 * node], tree[node]);
    tree[2 * node + 1] = min(tree[2 * node + 1], tree[node]);
    int mid = (l + r) / 2;
    push_all(2 * node, l, mid, R_max);
    push_all(2 * node + 1, mid + 1, r, R_max);
}

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    tree.assign(4 * n + 5, n);
    vector<int> pref_max(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            for (int v : {a[i], b[i]}) {
                int ql = pref_max[v] + 1;
                int qr = (v == 1 ? i : pref_max[v - 1]);
                ql = max(ql, 1);
                qr = min(qr, i);
                if (ql <= qr) {
                    update(1, 1, n, ql, qr, i - 1);
                }
            }
        } else {
            int v = a[i];
            int val = (v == 1 ? i : pref_max[v - 1]);
            pref_max[v] = max(pref_max[v], val);
        }
    }

    vector<int> R_max(n + 1);
    push_all(1, 1, n, R_max);

    long long ans = 0;
    for (int l = 1; l <= n; l++) {
        if (R_max[l] >= l) {
            ans += (R_max[l] - l + 1);
        }
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
