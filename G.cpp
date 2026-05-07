#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

class Mex {
    private:
        map<int, int> frequency;
        set<int> missing_numbers;
        vector<int> A;

    public:
        Mex(vector<int> const& A) : A(A) {
            for (int i = 0; i <= A.size(); i++)
                missing_numbers.insert(i);

            for (int x : A) {
                ++frequency[x];
                missing_numbers.erase(x);
            }
        }

        int mex() {
            return *missing_numbers.begin();
        }

        void update(int idx, int new_value) {
            if (--frequency[A[idx]] == 0)
                missing_numbers.insert(A[idx]);
            A[idx] = new_value;
            ++frequency[new_value];
            missing_numbers.erase(new_value);
        }
};

void solve() {
    //pre compute xor
    vector<vector<ll>> xo(2e30);
    REP(i, 2e30){
        xo = 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    while(test--) {
        solve();
    }
    return 0;
}