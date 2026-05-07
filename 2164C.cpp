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
#define RREP(i,n) for(int i=n-1; i>=0; i--)
#define mod 1000000007

void solve() {
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    REP(i, n) cin>>a[i];
    vector<ll> b(m),c(m);
    for (auto &x:b) cin>>x;
    for (auto &x:c) cin>>x;
    priority_queue<ll,vector<ll>,greater<ll>> heap;
    for (auto x:a) heap.push(x);
    vector<pair<ll,ll>> stage1;
    vector<ll> stage2monsters;

    for(int i=0;i<m;i++){
        if(c[i])
            stage1.push_back({b[i],c[i]});
        else
            stage2monsters.push_back(b[i]);
    }
    sort(stage1.begin(),stage1.end());
    vector<ll> stage2swords;
    int killed=0;
    for(auto [bi,ci]:stage1){
        while(!heap.empty()){
            ll x=heap.top();
            if(x<bi){
                stage2swords.push_back(x);
                heap.pop();
            }
            else{
                heap.pop();
                killed++;
                ll newsword=max(x,ci);
                heap.push(newsword);
                break;
            }
        }
        if(heap.empty())
            break;
    }
    while(!heap.empty()){
        stage2swords.push_back(heap.top());
        heap.pop();
    }
    sort(stage2swords.begin(),stage2swords.end());
    sort(stage2monsters.begin(),stage2monsters.end());
    int i=0,j=0;
    while(i<stage2swords.size() && j<stage2monsters.size()){
        if(stage2swords[i]>=stage2monsters[j]){
            killed++;
            i++;
            j++;
        }
        else i++;
    }
    cout<<killed<<"\n";
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}