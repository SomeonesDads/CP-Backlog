#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
vector<vector<int>> all_subsets;

void generate(int idx, vector<int>& current) {
    if (idx == n) {
        all_subsets.push_back(current);
        return;
    }

    // Tidak ambil elemen ke-idx
    generate(idx + 1, current);

    // Ambil elemen ke-idx
    current.push_back(arr[idx]);
    generate(idx + 1, current);
    current.pop_back();
}

int main() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> current;
    generate(0, current);

    // Sort sesuai aturan: panjang dulu, lalu leksikografis
    // sort(all_subsets.begin(), all_subsets.end(), [](const vector<int>& a, const vector<int>& b) {
    //     if (a.size() != b.size()) return a.size() < b.size();
    //     return a < b;
    // });

    for (auto& subset : all_subsets) {
        cout << "[";
        for (int i = 0; i < (int)subset.size(); i++) {
            cout << subset[i];
            if (i + 1 < subset.size()) cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}
