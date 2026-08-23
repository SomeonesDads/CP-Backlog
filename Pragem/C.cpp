#include <bits/stdc++.h>
using namespace std;

class edge{
    public:
    int u, v;
    long long w;
};
int main() {
    int n, m; cin >> n >> m;
    vector<edge> a(m);
    for(int i = 0; i < m; i++) cin >> a[i].u >> a[i].v >> a[i].w;
    
    double l = -1e9; double r = 1e9;
    for(int i = 0; i < 100; i++){        // 10 dh bisa 1.9, 50 dh 2.33333, 100kan aj biar aman 
        double mid = l + (r - l)/2;
        bool need = false;

        vector<double> dist(n+1, 0);
        for(int j = 0; j < n; j++){
            bool changed = false;
            for(edge e: a){
                double neww = e.w - mid;
                if(dist[e.u] + neww < dist[e.v]){
                    changed = true;
                    dist[e.v] = dist[e.u] + neww;
                }
            }
            if(!changed) break;
            else if(j == n-1) need = true;
        }

        if (need) r = mid; 
        else l = mid;  
    }
    
    cout << r << "\n";
    return 0;
}
