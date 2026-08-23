#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,n) for(int i=0; i<n; i++)

void solve() {
    int n; 
    cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a[i];

    // 1. Kumpulkan semua kandidat target yang mungkin dikunjungi
    vector<ll> candidates;
    REP(i, n) {
        ll cur = a[i];
        int visitone = 0, visittwo = 0;
        while (true) {
            candidates.push_back(cur);
            if (cur == 1) visitone++;
            if (cur == 2) visittwo++;
            if (visitone >= 2 && visittwo >= 2) break;

            if (cur % 2 == 0) cur /= 2;
            else cur += 1;
        }
    }

    // Urutkan dan buang duplikat untuk mendapatkan list target yang valid
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    int num_candidates = candidates.size();
    vector<ll> totalCost(num_candidates, 0);
    vector<int> reach_count(num_candidates, 0);

    // 2. Hitung cost untuk setiap elemen ke kandidat target
    REP(i, n) {
        ll cur = a[i];
        ll steps = 0;
        int visitone = 0, visittwo = 0;

        // Kita gunakan map temporer lokal hanya untuk menandai apa yang sudah dikunjungi
        // di dalam SATU jalur angka ini (ukurannya kecil sekali, maksimal 60 elemen)
        map<ll, ll> path_steps;

        while (true) {
            if (path_steps.find(cur) == path_steps.end()) {
                path_steps[cur] = steps;
            }

            if (cur == 1) visitone++;
            if (cur == 2) visittwo++;
            if (visitone >= 2 && visittwo >= 2) break;

            if (cur % 2 == 0) cur /= 2;
            else cur += 1;
            steps++;
        }

        // Petakan langkah dari path_steps ke array totalCost menggunakan bsearch
        REP(j, num_candidates) {
            ll target = candidates[j];
            if (path_steps.find(target) != path_steps.end()) {
                reach_count[j]++;
                totalCost[j] += path_steps[target];
            }
        }
    }

    // 3. Cari target yang bisa dicapai oleh SEMUA angka dengan cost minimal
    ll ans = LLONG_MAX;
    REP(j, num_candidates) {
        if (reach_count[j] == n) {
            ans = min(ans, totalCost[j]);
        }
    }

    cout << ans << "\n";
}

int main() {
    // Pengoptimal kecepatan I/O standar C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; 
    cin >> t;
    while(t--) solve();

    return 0;
}