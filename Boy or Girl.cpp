 #include <bits/stdc++.h>
 using namespace std;
 #define ll long long
 #define REP(i,n) for(int i=0; i<n; i++)
 #define mod 1000000007
 void solve()
 {
    set<char> distincts;
    string s;
    cin >> s;
    REP(i, s.length()){
        distincts.insert(s[i]);
    }
    if(distincts.size()%2 == 0){
        cout << "CHAT WITH HER!";
    }
    else cout << "IGNORE HIM!";
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
 