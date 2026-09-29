#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;
    long long a[n], b[m];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int b0 = 0;
    for (int i = 0; i < m; i++){
        cin >> b[i];
        if (b[i] < 0){
            b0++;
        }
    }
    int jumlah0 = n - m;
    // pos = min(pos1, pos2);
    long long score = 0;    
    int indexa = 0;
    for(int i = 0; i < m; i++){
        if(i == b0){
            for(int j = 0; j < jumlah0; j++){
                indexa++;
            }
        }
        score += a[indexa]*b[i];
        indexa++;
    }
    cout << score;
}