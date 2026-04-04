#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define mod 1000000007
void solve()
{
    string a,b;
    cin >> a >> b;
    char a_char, b_char;
    int i = 0;
    do {
        a_char = tolower(a[i]);
        b_char = tolower(b[i]);
        i++;
    }while(i < a.length() && a_char == b_char);
    cout << ((a_char >= b_char) ? !!(a_char - b_char) : -1);

    
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
