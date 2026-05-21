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

vector<int> ans;
map<int, int> freq;

void precomp(){
    int num = 1;
    while(num != 1000){
        if(freq[num] != 1){
            freq[num]++;
            ans.push_back(num);
            if(num != 1){
                freq[num + ans[ans.size()-2]]++;
            }
        }
        num++;
    }
}
void solve()
{
    int n; cin >> n;
    REP(i, n){
        cout << ans[i] << " ";
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    cin>>test;
    precomp();
    while(test--)
    {
        solve();
    }
    return 0;
}
