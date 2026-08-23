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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<int>> isTail(n, vector<int>(m, 0));

    REP(i, n)
    {
        string temp;
        cin >> temp;
        REP(j, m)
        {
            v[i][j] = temp[j];
        }
    }
    REP(i, n)
    {
        REP(j, m)
        {
            if (!visited[i][j])
            {
                visited[i][j] = 1;
                int x = i;
                int y = j;
                while (x >= 0 && x < n && y >= 0 && y < m)
                {
                    // debug(x, y);
                    if (v[x][y] == 'U')
                        x -= 1;
                    else if (v[x][y] == 'D')
                        x += 1;
                    else if (v[x][y] == 'R')
                        y += 1;
                    else if (v[x][y] == 'L')
                        y -= 1;
                    if (not(x >= 0 && x < n && y >= 0 && y < m))
                        break;
                    if (isTail[x][y])
                    {
                        isTail[x][y] = 0;
                        break;
                    }
                    if (visited[x][y])
                        break;
                    visited[x][y] = 1;
                }
                isTail[i][j] = 1;
            }
        }
    }
    int ans = 0;
    REP(i, n)
    REP(j, m)
    ans += isTail[i][j];
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}