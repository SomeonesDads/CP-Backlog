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

int query(int a, int b){
    printf("? %d ", (b-a+1));
    for(int i = a; i <= b; i++){
        if(i != b) printf("%d ", i);
        else printf("%d\n", i);
    }
    fflush(stdout);
    int ans; scanf("%d", &ans);
    return ans;

}
void solve()
{
    int n; scanf("%d", &n);
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    vector<int> pref(n+1);
    pref[0] = 0;
    for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i];
    int l = 1; 
    int r = n;
    int mid = (l + r)/2;
    while(l != r){
        int mid = (l + r) / 2;

        int res = query(l, mid);
        int expected = pref[mid] - pref[l-1];

        if(res != expected) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    printf("! %d\n", l);
    fflush(stdout);
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
