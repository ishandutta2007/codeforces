#include <bits/stdc++.h>
using namespace std;
int n;
int64_t a, b;
int64_t x[200001];
int64_t s[200001];
class CHT {
public:
    class LineSegment {
    public:
        int64_t a, b;  // ax + b
        int64_t operator()(const int64_t& x) const { return a * x + b; }
        int64_t FindFirstDom(const LineSegment& other) const {
            assert(a < other.a);
            if (b <= other.b) return -1e18;
            // a*x + b < other.a*x + other.b
            // (other.a - a) * x > (b - other.b)
            int64_t min_x = (b - other.b) / (other.a - a);
            while (operator()(min_x) > other(min_x)) min_x++;
            return min_x;
        }
    };
    deque<pair<LineSegment, int64_t>> lines;

    void AddLineSegment(const LineSegment& value) {
        while ((!lines.empty()) && (value.FindFirstDom(lines.back().first) <= lines.back().second)) lines.pop_back();
        if (lines.empty()) lines.emplace_back(value, -1e8);
        else lines.emplace_back(value, value.FindFirstDom(lines.back().first));
    }

    int64_t Query(int64_t x) {
        while ((lines.size() > 1) && (lines[1].second <= x)) lines.pop_front();
        assert(!lines.empty());
        return lines.front().first(x);
    }
};
void solve() {
    cin >> n >> b >> a;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + x[i];
    CHT conquer, move;
    conquer.AddLineSegment({0, 0});
    move.AddLineSegment({0, 0});

    for (int i = 1; i < n; i++) {
        int64_t move_cost = move.Query(i) + s[i] * a + x[i] * b;
        move.AddLineSegment({-x[i] * a, move_cost + -s[i] * a + a * x[i] * i - x[i] * b});
        conquer.AddLineSegment({-x[i] * a, move_cost + -s[i] * a + a * x[i] * i});
    }
    int64_t ans = conquer.Query(n) + s[n] * a;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}