#include <bits/stdc++.h>
using namespace std;
int n;
int h[200001];
vector<int> order;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    order.clear();
    for (int i = 1; i <= n; i++) order.push_back(i);
    sort(order.begin(), order.end(), [](const int &a, const int &b) { return h[a] < h[b]; });
    if (n == 2) {
        cout << h[order[0]] << ' ' << h[order[1]] << '\n';
        return;
    }
    pair<int, int> ans = {1e9, 0};
    for (int i = 1; i < n; i++) ans = min(ans, {h[order[i]] - h[order[i - 1]], i});
    cout << h[order[ans.second - 1]] << ' ';
    for (int i = ans.second + 1; i < n; i++) cout << h[order[i]] << ' ';
    for (int i = 0; i < ans.second - 1; i++) cout << h[order[i]] << ' ';
    cout << h[order[ans.second]] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}