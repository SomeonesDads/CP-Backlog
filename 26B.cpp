#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    long long open = 0;
    long long ans = 0;

    for (char c : s) {
        if (c == '(') {
            open++;
        } else { // ')'
            if (open > 0) {
                open--;
                ans += 2;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
