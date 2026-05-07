#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)

struct node {
    char t;
    int k;
};

struct segnode {
    array<int,16> f;
};
int n, q;
vector<node> a;
vector<segnode> seg;
segnode combine(const segnode &tl, const segnode &R) {
    segnode res;
    REP(i,16) res.f[i] = R.f[tl.f[i]];
    return res;
}
segnode make_pair(char t, int k) {
    segnode res;
    REP(i,16) {
        if (t == '+') res.f[i] = (i + k) % 16;
        else res.f[i] = i ^ k;
    }
    return res;
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = make_pair(a[tl-1].t, a[tl-1].k);
        return;
    }
    int mid = (tl + tr) / 2;
    build(v*2, tl, mid);
    build(v*2+1, mid+1, tr);
    seg[v] = combine(seg[v*2], seg[v*2+1]);
}
void update(int v, int tl, int r, int pos, char t, int k) {
    if (tl == r) {
        seg[v] = make_pair(t, k);
        return;
    }
    int mid = (tl + r) / 2;
    if (pos <= mid) update(v*2, tl, mid, pos, t, k);
    else update(v*2+1, mid+1, r, pos, t, k);
    seg[v] = combine(seg[v*2], seg[v*2+1]);
}

int output() {
    return seg[1].f[0];
}

void solve() {
    cin >> n >> q;
    a.resize(n);
    seg.resize(4*n);
    REP(i, n) cin >> a[i].t >> a[i].k;
    build(1, 1, n);
    REP(i, q) {
        int j; char t; int k;
        cin >> j >> t >> k;
        a[j-1].t = t;
        a[j-1].k = k;
        update(1, 1, n, j, t, k);
        cout << output() << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while (test--) solve();
    return 0;
}
