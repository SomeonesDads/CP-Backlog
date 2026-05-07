#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    int R;
    int x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    double distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double r = 0.5 * (distance + R);
    double grad = ((y2-y1)*1.0)/((x2-x1)*1.0);
    // grad = y/x, y = grad*x
    // r = ||sqrt(x^2 + (grad*x)^2)||
    // r^2 = x^2 + grad^2x^2
    // r^2 = (1+grad^2)x^2
    // r^2/(1+grad^2) = x^2
    // x = sqrt(r^2/(1+grad^2))
    double x = sqrt(pow(r,2)/(1+pow(grad,2)));
    cout << r << " " << x << " " << grad*x << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    cin >> test;
    while(test--){
       solve();
    }
    return 0;
}