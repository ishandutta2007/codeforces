#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> b[200001];
int64_t cnt_left[200001];
int64_t cnt_right[200001];
int64_t total_left;
int64_t total_right;
int64_t total_same;

int64_t get_total(int avoid) {
    return (total_left - cnt_left[avoid]) * (total_right - cnt_right[avoid]) - total_same + cnt_left[avoid] * cnt_right[avoid];
}

void pop_right(int val) {
    total_same -= cnt_right[val] * cnt_left[val];
    cnt_right[val]--;
    total_right--;
    total_same += cnt_right[val] * cnt_left[val];
}
void push_left(int val) {
    total_same -= cnt_right[val] * cnt_left[val];
    cnt_left[val]++;
    total_left++;
    total_same += cnt_right[val] * cnt_left[val];
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) b[i].clear();
    for (int i = 1, a, bb; i <= n; i++) {
        cin >> a >> bb;
        b[a].push_back(bb);
    }
    for (int i = 1; i <= n; i++) cnt_right[i] = 0;
    for (int i = 1; i <= n; i++) cnt_left[i] = 0;
    total_left = 0;
    total_same = 0;
    for (int i = 1; i <= n; i++)
        for (auto&& bb : b[i]) cnt_right[bb]++;
    total_right = n;
    int64_t ans = 0;
    {
        int64_t choose[4];
        choose[0] = 1;
        choose[1] = choose[2] = choose[3] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 3; j >= 1; j--) choose[j] += choose[j - 1] * cnt_right[i];
        }
        ans += choose[3];
    }
    {
        int64_t choose[4];
        choose[0] = 1;
        choose[1] = choose[2] = choose[3] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 3; j >= 1; j--) choose[j] += choose[j - 1] * b[i].size();
        }
        ans += choose[3];
    }
    for (int a = 1; a <= n; a++) {
        for (auto&& bb : b[a]) pop_right(bb);
        for (auto&& bb : b[a]) ans -= get_total(bb);
        for (auto&& bb : b[a]) push_left(bb);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}