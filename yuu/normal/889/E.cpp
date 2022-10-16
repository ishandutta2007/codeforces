#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int64_t, int>> x;
class segment_t {
public:
    int64_t c;
    int64_t l, r;

    segment_t(int64_t c = 0, int64_t l = 0, int64_t r = 0) : c(c), l(l), r(r) {}

    bool operator<(const segment_t& other) const { return c < other.c; }
};
vector<segment_t> s;
vector<segment_t> update;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while (n--) {
        int64_t a;
        cin >> a;
        if ((x.empty()) || (a < x.back().first)) x.emplace_back(a, 1);
        else x.back().second++;
    }
    s.emplace_back(0, 0, x[0].first - 1);
    int total = x[0].second;
    x.erase(x.begin());
    x.emplace_back(1, 1);
    for (auto p : x) {
        for (auto x : update) s.emplace_back(x);
        update.clear();
        sort(s.begin(), s.end(), [](const auto& A, const auto& B) { return A.l > B.l; });
        priority_queue<segment_t> q;
        while (!s.empty()) {
            auto p = s.back();
            if (!update.empty()) {
                while (update.back().r + 1 < p.l) {
                    auto f = q.top();
                    q.pop();
                    if (f.r <= update.back().r) continue;
                    update.emplace_back(f.c, update.back().r + 1, f.r);
                }
            }
            s.pop_back();
            q.push(p);
            while ((!s.empty()) && (s.back().l == p.l)) {
                q.push(s.back());
                s.pop_back();
            }
            if (update.empty()) {
                update.push_back(q.top());
                q.pop();
            } else {
                if (q.top().c > update.back().c) {
                    if (update.back().r > q.top().r) q.emplace(update.back().c, q.top().r + 1, update.back().r);
                    update.back().r = q.top().l - 1;
                    update.push_back(q.top());
                    q.pop();
                }
            }
        }
        while (!q.empty()) {
            auto f = q.top();
            q.pop();
            if (f.r <= update.back().r) continue;
            update.emplace_back(f.c, update.back().r + 1, f.r);
        }
        for (auto p : update)
            if (s.empty() || (p.c != s.back().c)) s.emplace_back(p);
            else s.back().r = p.r;
        update.clear();

        while ((!s.empty()) && (s.back().r >= p.first)) {
            auto t = s.back();
            s.pop_back();
            if (t.l < p.first) {
                s.emplace_back(t.c, t.l, p.first - 1);
                t.l = p.first;
            }
            if (t.r - t.l + 1 > p.first) t.l = t.r - p.first + 1;
            int64_t low = t.l % p.first;
            int64_t high = t.r % p.first;
            if (low <= high) {
                update.emplace_back(t.c + (t.l - t.l % p.first) * total, low, high);
            } else {
                update.emplace_back(t.c + (t.l - t.l % p.first) * total, low, p.first - 1);
                update.emplace_back(t.c + (t.r - t.r % p.first) * total, 0, high);
            }
        }
        total += p.second;
    }
    int64_t ans = 0;
    for (auto p : s) ans = max(ans, p.c);
    for (auto p : update) ans = max(ans, p.c);
    cout << ans << '\n';
}