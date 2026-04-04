#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <map>
#include <sstream>
using namespace std;

const int MAX_VAL = 200005;
vector<int> spf(MAX_VAL);

void sieve() {
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i < MAX_VAL; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX_VAL; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

void get_prime_factors(int n, set<int>& factors) {
    while (n > 1) {
        int p = spf[n];
        factors.insert(p);
        while (n % p == 0) n /= p;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while (t--) {
        int n_for_b_array;
        if (cin.peek() == '\n') cin.ignore();
        string line1, line2, b_line;
        getline(cin, line1);
        getline(cin, line2);
        getline(cin, b_line);
        stringstream ss1(line1);
        int n;
        ss1 >> n;
        stringstream ss2(line2);
        vector<int> a(n);
        for(int i=0; i<n; ++i) ss2 >> a[i];
        set<int> seen_primes_a;
        bool cost_0 = false;
        for (int x : a) {
            set<int> current_factors;
            int num = x;
            while (num > 1) {
                int p = spf[num];
                if (seen_primes_a.count(p)) {
                    cost_0 = true;
                    break;
                }
                current_factors.insert(p);
                while (num % p == 0) num /= p;
            }
            if(cost_0) break;
            seen_primes_a.insert(current_factors.begin(), current_factors.end());
        }
        if (cost_0) {
            cout << 0 << "\n";
            continue;
        }
        bool cost_1 = false;
        for (int x : a) {
            set<int> factors_a_plus_1;
            get_prime_factors(x + 1, factors_a_plus_1);
            for (int p : factors_a_plus_1) {
                if (seen_primes_a.count(p)) {
                    cost_1 = true;
                    break;
                }
            }
            if(cost_1) break;
        }
        if (cost_1) cout << 1 << "\n";
        else cout << 2 << "\n";
    }
    return 0;
}
