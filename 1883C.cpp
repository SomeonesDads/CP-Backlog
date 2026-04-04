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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (k == 2 || k == 3 || k == 5) {
        int ans = INT_MAX;
        for (int x : a) {
            int cost = (k - (x % k)) % k;
            ans = min(ans, cost);
        }
        cout << ans << '\n';
        return;
    }
    int cost_div4 = INT_MAX;
    for (int x : a) {
        int c = (4 - (x % 4)) % 4;
        cost_div4 = min(cost_div4, c);
    }
    if (n == 1) {
        cout << cost_div4 << '\n';
        return;
    } else {
        int evenCount = 0;
        for (int x : a) if (x % 2 == 0) ++evenCount;
        int needToMakeTwoEven = max(0, 2 - evenCount); 
        int ans = min(cost_div4, needToMakeTwoEven);
        cout << ans << '\n';
    }
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
