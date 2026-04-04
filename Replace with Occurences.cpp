#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)
#define RREP(i,n) for(int i=n-1; i>= 0;i++)
#define mod 1000000007
void solve()
{
    int n; cin >> n;
    vector<int> bfreq(n+1, 0);
    vector<int> b(n);
    vector<pair<int, int>> freq(n+1, make_pair(0, 0));
    int m = 0;
    REP(i, n){
        cin >> b[i];
        bfreq[b[i]]++;
        m = max(b[i], m);
    }
    bool shit = false;
    for(int i = 1; i <= n; i++){
        if(bfreq[i]%i != 0) shit = true;
    }
    if(shit) cout << -1 << endl;
    else{
        int num = 1;
        REP(i, n){
            for(int j = num; j<=n; j++){
                if(freq[j].second == b[i] || freq[j].second == 0){
                    cout << j << " ";
                    freq[j].first++;
                    if(freq[j].second == 0) freq[j].second = b[i];
                    // printf("f: %d s : %d\n", freq[j].first, freq[j].second);
                    if(freq[j].first == freq[j].second){
                        freq[j].second = -1;
                    }
                    break;
                }
            }
            if (freq[num].second == -1) num++;
        }
        cout << endl;
    }
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
