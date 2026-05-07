#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i = 0;i<n;i++)

void solve() {
    string s; 
    cin >> s;
    int len = s.size();
    map<char, int> dict;
    set<char> alphabets;
    REP(i, len){
        dict[s[i]]++;
        alphabets.insert(s[i]);
    }

    queue<pair<char, int>> longans;
    queue<char> shorts;
    for(char c : alphabets){
        if(dict[c] >= 2){
            longans.push({c, dict[c] / 2}); 
            dict[c] %= 2;
        }
        if(dict[c] == 1){
            shorts.push(c);
        }
    }

    queue<pair<char, int>> longans2 = longans;
    vector<string> ans;
    string temp = "";
    while(!longans.empty()){
        auto a = longans.front(); longans.pop();
        temp += string(a.second, a.first);
    }
    if(!shorts.empty()) {
        temp += shorts.front(); 
        shorts.pop();
    }
    string right = "";
    while(!longans2.empty()){
        auto a = longans2.front(); longans2.pop();
        right = string(a.second, a.first) + right;
    }
    temp += right;
    if(!temp.empty()) ans.push_back(temp);
    while(!shorts.empty()){
        string single(1, shorts.front());
        shorts.pop();
        ans.push_back(single);
    }
    cout << ans.size() << "\n";
    for(auto &x : ans) cout << x << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;
    // cin >> test;
    while(test--){
        solve();
    }
    return 0;
}
