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
    int n; cin >> n;
    string x; cin >> x;
    int a = 2;
    int b = 0;
    bool correct = true;
    if(n%2==0){
        a--;
        b++;
    }
    REP(i, n){
        if(x[i] == 'a'){
            if(!a){
                correct = false;
                break;
            }
            a--;
            b++;
        }
        else if(x[i] == 'b'){
            if(!b){
                correct = false;
                break;
            }
            a++;
            b--;
        }
        else{
            if(!b){
                a--;
                b++;
            }
            else if (!a){
                a++;
                b--;
            }
            else{
                int count = 1;
                char ta
                for(int j =i+1;j<n;j++){
                    if(x[j] == '?') count++;
                    else break;
                }
                i+=count-1;
                if(count%2 == 0){
                    
                }
            }
        }
    }
    cout << (correct ? "YES\n":"NO\n");

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