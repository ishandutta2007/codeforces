#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
vector<int> pos[1000001];
int total = 0;

int get(const vector<int>& pos) {
    // keep from l + 1 -> r =>
    // (r - l) - (sum[r] - sum[l]) + sum[l] + (sum[n] - sum[r])
    // sum[n] + (r - 2sum[r]) - (l - 2sum[l])
    int high = -1;
    int sum = 0;
    int low = 1e9;
    for (int i = 0; i < pos.size(); i++) {
        sum += pos[i];
        int cost = i - sum * 2;
        low = min(low, cost - high);
        high = max(high, cost);
    }
    low += sum;
    return (total - sum) + low;
}

void solve() {
    cin >> n >> k >> s;
    for (int i = 0; i < k; i++) pos[i].clear();
    total = 0;
    for (int i = 0; i < n; i++) {
        pos[i % k].emplace_back(s[i] - '0');
        if (s[i] == '1') {
            total++;
        }
    }
    int ans = total;
    for (int i = 0; i < k; i++) ans = min(get(pos[i]), ans);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}