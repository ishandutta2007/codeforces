#include <bits/stdc++.h>
using namespace std;
class BracketSequence {
  public:
    inline static string s;
    int low, high, weight;
    vector<vector<int>> pos;
    vector<int> prefix_low;

    BracketSequence() {
        cin >> s;
        weight = 0;
        low = 1e9;
        high = -1e9;
        pos.clear();
        prefix_low.clear();
        for (auto&& c : s) {
            if (c == '(') {
                weight++;
                if (weight > high) high = weight;
                if (weight < low) low = weight;
            } else {
                weight--;
                if (weight > high) high = weight;
                if (weight < low) low = weight;
            }
            prefix_low.push_back(low);
        }
        pos.resize(high - low + 1);
        for (auto&& x : pos) x.clear();
        int current = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                current++;
            } else {
                current--;
            }
            pos[current - low].push_back(i);
        }
    }

    int count_valid_position(int starting_offset) {
        // count the number of position that is == - starting_offset
        if (starting_offset + low > 0) return 0;
        int indx = -starting_offset - low;
        if (indx >= pos.size()) return 0;
        if (indx < 0) return 0;
        int low = 0, high = prefix_low.size() - 1, mid, res = -1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (starting_offset + prefix_low[mid] < 0) {
                high = mid - 1;
            } else {
                low = mid + 1;
                res = mid;
            }
        }
        if (res == -1) return 0;
        if (pos[indx].back() <= res) return pos[indx].size();
        return upper_bound(pos[indx].begin(), pos[indx].end(), res) - pos[indx].begin();
    }
};
vector<BracketSequence> bs;
int n;
class {
  public:
    int weight, f;
} dp[1 << 20];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) bs.emplace_back();
    for (int i = 0; i < (1 << n); i++) {
        dp[i].weight = 0;
        dp[i].f = -1e9;
    }
    for (int i = 1; i < (1 << n); i++) {
        for (int j = 0; j < n; j++)
            if ((i >> j) & 1) {
                dp[i].weight = dp[i ^ (1 << j)].weight + bs[j].weight;
                break;
            }
    }
    dp[0].f = 0;
    int ans = 0;
    for (int i = 0; i < (1 << n); i++)
        if (dp[i].f >= 0) {
            ans = max(ans, dp[i].f);
            for (int j = 0; j < n; j++)
                if (!((i >> j) & 1)) {
                    int res = dp[i].f + bs[j].count_valid_position(dp[i].weight);
                    if (dp[i].weight + bs[j].low >= 0) {
                        dp[i ^ (1 << j)].f = max(dp[i ^ (1 << j)].f, res);
                    } else {
                        ans = max(ans, res);
                    }
                }
        }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}