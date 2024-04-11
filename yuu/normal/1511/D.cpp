#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> ans;
void make(int low) {
    ans.push_back(low);
    ans.push_back(low);
    for (int i = k; i > low + 1; i--) {
        ans.push_back(i);
        ans.push_back(low);
    }
    if (low < k) {
        make(low + 1);
        ans.push_back(low);
    }
}
void solve() {
    cin >> n >> k;
    make(1);
    ans.pop_back();
    set<pair<char, char>> s;
    for (int i = 0; i < ans.size(); i++) s.insert({ans[i], ans[(i + 1) % ans.size()]});
    assert(s.size() == ans.size());
    for (int i = 0; i < n; i++) cout << char(ans[i % ans.size()] - 1 + 'a');
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}