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

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> present(26, 0);
    string s;
    bool b = true;
    REP(i, n){
        cin >> s;
        present[toupper(s[0]) - 'A'] = 1;
    }
    REP(i, m){
        cin >> s; for(char &c: s) if(!present[toupper(c) - 'A']){b = false; break;}
    }
    cout << (b ? "YES\n" : "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}