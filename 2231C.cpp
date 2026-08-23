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
 
void solve() {
    int n; 
    cin >> n;
    map<ll, int> freq;
    vector<ll> a(n); 
    REP(i, n){ cin >> a[i]; freq[a[i]]++;}
    int uniques = freq.size();
    
    // 1. PINDAH KE SINI: Menghindari MLE karena map otomatis di-reset tiap test case
    // 2. PAKAI UNORDERED: Jauh lebih cepat dari map biasa, ditambah optimasi reserve
    unordered_map<ll, ll> sumop; 
    unordered_map<ll, int> count;
    
    // Alokasi memori di awal agar tidak ada overhead resizing di dalam loop while
    sumop.reserve(uniques * 60);
    count.reserve(uniques * 60);
    sumop.max_load_factor(0.25);
    count.max_load_factor(0.25);
    
    for (auto const& [val, freq] : freq) {
        ll current = val;
        ll steps = 0;
        bool visittwo = false;
        bool visitone = false;
        while (true) {
            count[current]++;
            sumop[current] += steps * freq;
 
            if (current == 1) visitone = true;
            if(current == 2) visittwo = true;
            if (visitone && visittwo) break;
            if (current % 2 == 0) current /= 2;
            else current += 1;
            steps++;
        }
    }
    ll ans = -1;
    for (auto const& [target, count] : count) if (count == uniques) if (ans == -1 || sumop[target] < ans) ans = sumop[target];
    cout << ans << "\n";
}
 
// TLE kena, MLE kena, mati ajala heang