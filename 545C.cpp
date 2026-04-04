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

void solve()
{
    int n;
    cin >> n;
    vector<long long> x(n), h(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> h[i];
    if (n <= 2) {
        cout << n << "\n";
        return;
    }
    vector<long long> stay(n), left(n), right(n);
    stay[0] = 0;
    left[0] = 1;
    right[0] = (x[0] + h[0] < x[1]) ? 1 : 0;
    for (int i = 1; i < n; i++) {
        stay[i] = max({stay[i - 1], left[i - 1], right[i - 1]});
        left[i] = -1e9;
        if (x[i] - h[i] > x[i - 1])
            left[i] = max({left[i], stay[i - 1] + 1, left[i-1] + 1});
        if (x[i] - h[i] > x[i - 1] + h[i - 1])
            left[i] = max(left[i], right[i - 1] + 1);
        right[i] = -1e9;
        if (i == n - 1 || x[i] + h[i] < x[i + 1])
            right[i] = 1 + stay[i];
    }

    cout << max({stay[n - 1], left[n - 1], right[n - 1]}) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    //cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
