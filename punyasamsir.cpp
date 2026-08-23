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

bool isvalid(double x, double y){
    bool cond1, cond2, cond3, cond4, cond5;
    cond1 = false;cond2 = false;cond3 = false;cond4 = false;cond5 = false;
    if((double)15*x+(double)10*y >= (double)40) cond1 = true;
    if((double)350*x+(double)200*y >= (double)1000) cond2 = true;
    if((double)40*x+(double)20*y >= (double)75) cond3 = true;
    if((double)120*x+(double)250*y >= (double)500) cond4 = true;
    if((double)8000*x+(double)4000*y <= (double)25000) cond5 = true;
    if(cond1) cout << "1";
    if(cond2) cout << "2";
    if(cond3) cout << "3";
    if(cond4) cout << "4";
    if(cond5) cout << "5";
    cout << "\n" << (double)8000*x+(double)4000*y;
    return cond1 && cond2 && cond3 && cond4 && cond5;
}


void solve()
{
    cout << "\n";
    cout << isvalid(0, 6.25);
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
