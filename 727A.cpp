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
    ll a, b; cin >> a >> b;
    string seq = "";
    while(b > a){
        if(b%10 == 1){
            b-=1;
            b/=10;
            seq += '1';
        }
        else if((b%10)%2 == 1){
            break;
        }
        else{
            b/=2;
            seq += '0';
        }
    }
    if(b==a){
        cout << "YES\n";
        cout << seq.size()+1 << '\n';
        seq = string(seq.rbegin(), seq.rend());
        // cout << seq << endl;
        cout << a << " ";
        REP(i, seq.size()){
            if(seq[i] == '0'){
                a *= 2;
            }
            else {
                (a *= 10); 
                a += 1;
            }
            cout << a << " ";
        }
    }
    else cout << "NO";    
}

int main() {
    // ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll test = 1;
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}