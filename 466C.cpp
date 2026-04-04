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
    int n; cin >> n;
    ll sum = 0;
    vector<int> a(n);
    REP(i, n){
        cin >> a[i];
        sum += a[i];
    }
    if(sum%3 != 0) cout << 0;
    else{
        ll limit = sum/3;
        int i = 0;
        ll tempsum = 0;
        while(tempsum!=limit && i < n){
            tempsum += a[i];
            i++;
        }
        if(tempsum != limit || i == n){
            cout << 0; return;
        }
        if(i!=0)i--;
        int z = n-1;
        tempsum = 0;
        while(tempsum < limit && z >= 0){
            tempsum += a[z];
            z--;
        }
        if(tempsum != limit || z == -1){
            cout << 0; return;
        }
        if(z - i == 0){
            cout << 0; return;
        }
        if(z!=n-1) z++;
        int j = i+1; 
        int ans = 1;
        int l = j;
        ll tempsum = 0;
        for(int r = j; r < z; r++){
            tempsum += a[r];
            if(tempsum == sum/3){
                
            }
        }
        cout << ans;
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test=1;
    // cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
