#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, v, m;
    cin >> n >> v >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    bool useSkill = false;
    if(m > 4) useSkill = true;
    long long ans = 0;
    for(int i = 0; i <n; i++){
        if(!useSkill){
            ans += (a[i] + v - 1)/v;
        }
        else{
            long long skillDMG = v+v/4;
            long long turns = (a[i]+skillDMG-1)/skillDMG;
            long long nskill = turns / m;
            ans += nskill + (nskill*m);
            a[i] -= (nskill*m)*skillDMG;
            
            // Nentuin sisa
            long long withskill = (a[i]+skillDMG-1)/(skillDMG) + 1;
            long long withoutskill = (a[i]+v-1)/v;

            ans += min(withskill, withoutskill);
            a[i] = 0;
        }
    }
    cout << ans;
}