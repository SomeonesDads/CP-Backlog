#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;
    long long a[n];
    bool flag = true;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] > m){
            flag = false;
        }
    }
    if (flag){
        cout << "YA" << endl;
    }
    else {
        cout << "TIDAK" << endl;
    }
}