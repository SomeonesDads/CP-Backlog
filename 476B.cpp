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
    double fact[11];
    fact[0] = 1;
    REP(i, 11) if(i) fact[i] = fact[i-1]*i;
    string s1, s2; cin >> s1 >> s2;
    int target = 0;
    int questions = 0;
    REP(i, s1.size()) (s1[i] == '+' ? target++ : target--);
    REP(i, s2.size()) (s2[i] == '+' ? target-- : (s2[i] == '-' ? target++ : questions++)); // Dosen worst nightmare
    double ans;
    debug(questions, target);
    if(questions == 0){
        if(target) ans = 0;
        else ans = 1;
    }
    else if(abs(target) > questions || (abs(target)%2 != questions%2)) ans = 0;
    else{
        target = abs(target);
        int plus = questions;
        int minus = (questions - target)/2;
        plus -= minus;

        ans = fact[questions]/fact[minus]/fact[plus]/pow(2, questions);
    }
    cout <<fixed << setprecision(12) << ans;
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
