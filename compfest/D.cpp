#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _debug(const char *name, T &&value)
{
    cerr << name << " = " << value << endl;
}
template <typename T, typename... Args>
void _debug(const char *names, T &&value, Args &&...args)
{
    const char *comma = strchr(names, ',');
    cerr.write(names, comma - names) << " = " << value << " | ";
    _debug(comma + 1, args...);
}

#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
#define ll long long
#define REP(i, n) for (int i = 0; i < n; i++)
#define RREP(i, n) for (int i = n - 1; i >= 0; i--)
#define mod 1000000007

bool sortbyCond(const vector<ll> &a, const vector<ll> &b)
{
    if (a[0] != b[0])
        return (a[1] < b[1]);
    else
        return (a[0] > b[0]);
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<ll>> t(n, vector<ll>(3)); // 0 = L, 1 = R, 2 = W
    set<int> decision;
    REP(i, n)
    {
        cin >> t[i][0] >> t[i][1] >> t[i][3];
        decision.push(t[i][1]);
    }
    vector<int> dp(decision.size());
    dp[0] = t[0][2];

    for (int d : decisions)
    {
        dp[d] = t[0][2];
    }
    sort(t.start(), t.end(), sortbyCond);
}

int main()
{
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}