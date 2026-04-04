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
    string s; cin >> s;
    long long sum = 0;
    vector<int> nums;
    char first = s[0];
    ll count = 0;
    REP(i, s.size()){
        if (s[i] == first) count++;
        int d = s[i] - '0';
        nums.push_back(d);
        sum += d;
    }
    if(sum <= 9){
        cout << 0 << "\n";
        return;
    }
    sort(nums.rbegin(), nums.rend());
    int moves = 0;
    debug(first, count);
    REP(i, nums.size()){
        debug(sum, i);
        if((nums[i]) == (first - '0')){
            if(count>1) sum-= nums[i];
            else sum-=(nums[i]-1);
            count--;
        }
        else sum -= nums[i];    
        debug(sum, i);
        moves++;
        if(sum <= 9) break;
    }
    cout << moves << "\n"; 
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
