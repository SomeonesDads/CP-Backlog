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

vector<int> based(const vector<int>& a) {
    vector<int> res;
    set<int> seen;
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        if (seen.find(a[i]) == seen.end()) {
            res.push_back(a[i]);
            seen.insert(a[i]);
        }
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> s(n);
    REP(i, n) {
        int l;
        cin >> l;
        vector<int> a(l);
        REP(j, l) cin >> a[j];
        s[i] = based(a);
    }

    vector<bool> used(1000001, false);
    vector<int> used_ids;
    vector<bool> blog_handled(n, false);
    vector<int> final_q;

    int blogs_left = n;
    while (blogs_left > 0) {
        int best_idx = -1;
        vector<int> best_segment;
        REP(i, n){
            if (blog_handled[i]) continue;
            vector<int> current_segment;
            for (int x : s[i]) {
                if (!used[x]) {
                    current_segment.push_back(x);
                }
            }
            if (current_segment.empty()) {
                blog_handled[i] = true;
                blogs_left--;
                i--;
                continue;
            }
            if (best_idx == -1 || current_segment < best_segment) {
                best_segment = current_segment;
                best_idx = i;
            }
        }
        if (best_idx != -1) {
            for (int x : best_segment) {
                final_q.push_back(x);
                used[x] = true;
                used_ids.push_back(x);
            }
            blog_handled[best_idx] = true;
            blogs_left--;
        } else {
            break;
        }
    }
    for (int i = 0; i < final_q.size(); ++i) {
        cout << final_q[i] << (i == final_q.size() - 1 ? "" : " ");
    }
    cout << "\n";
    for (int id : used_ids) used[id] = false;
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
