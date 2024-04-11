#include <bits/stdc++.h>
using namespace std;
vector<int> p[2];
int n, k;
int64_t get_total_dist(vector<int>& pos, bool return_to_origin) {
    if (pos.empty()) return 0;
    int64_t res = 0;
    int now = pos.size() - 1;
    while (now >= 0) {
        res += pos[now];
        if (return_to_origin) res += pos[now];
        return_to_origin = true;
        now -= k;
    }
    return res;
}

int64_t get_ans(int first, int last) { return get_total_dist(p[first], true) + get_total_dist(p[last], false); }

void solve() {
    cin >> n >> k;
    p[0].clear();
    p[1].clear();
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x > 0)
            p[0].push_back(x);
        else if (x < 0)
            p[1].push_back(-x);
    }
    sort(p[0].begin(), p[0].end());
    sort(p[1].begin(), p[1].end());
    cout << min(get_ans(0, 1), get_ans(1, 0)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}