#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
bool cek(ll cur){
    ll cnt = 0;
    for(ll x = -cur ; x <= cur ; x++){
        // x^ 2 + y^2 = r ^2
        ll y = (int) sqrt(cur * cur - x * x);
        cnt += 2*y + 1;
    }
    return (cnt >= n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    ll low = 0;
    ll high = 3 * 1e6;
    ll ans = 3 * 1e6;

    while(low <= high){
        ll mid = low + (high - low)/2;
        if(cek(mid)){
            ans = min(ans,mid);
            high = mid-1;
        }
        else low = mid+1;
    }
    cout << ans << endl;
    return 0;
}