#include <bits/stdc++.h>
using namespace std;

const int MAXB = 30;

struct Trie {
    struct Node {
        int cnt = 0;
        int child[2] = {-1, -1};
    };
    vector<Node> t;
    Trie() { t.push_back(Node()); }

    void insert(int x, int delta) {
        int v = 0;
        for (int i = MAXB - 1; i >= 0; i--) {
            int b = (x >> i) & 1;
            if (t[v].child[b] == -1) {
                t[v].child[b] = t.size();
                t.push_back(Node());
            }
            v = t[v].child[b];
            t[v].cnt += delta;
        }
    }

    int mex(int k, int i = 0, int bit = MAXB - 1, int v = 0, int val = 0) {
        if (v == -1) return val;
        if (bit < 0) return val;
        int b = (k >> bit) & 1;

        int left = t[v].child[b];
        int right = t[v].child[b ^ 1];

        int leftCount = (left == -1 ? 0 : t[left].cnt);
        int fullSize = 1 << bit;

        if (leftCount < fullSize) {
            return mex(k, i, bit - 1, left, val);
        } else {
            return mex(k, i, bit - 1, right, val | (1 << bit));
        }
    }
};

void solve() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q; int K;
    cin >> q >> K;
    Trie trie;
    unordered_map<int, int> freq;
    for (int _ = 0; _ < q; _++) {
        int x; cin >> x;
        if (freq[x] == 0) trie.insert(x, +1);
        else trie.insert(x, -1);
        freq[x] ^= 1;

        cout << trie.mex(K) << "\n";
    }
}

int main() {
    solve();
    return 0;
}
