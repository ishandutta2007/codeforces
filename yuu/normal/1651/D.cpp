#include <bits/stdc++.h>
using namespace std;
class Point {
  public:
    int x, y;
    int ax, ay;
    void RegisterAnswer(int nx, int ny) {
        if (abs(x - ax) + abs(y - ay) > abs(x - nx) + abs(y - ny)) {
            ax = nx;
            ay = ny;
        }
    }
} p[200001];
int n;
vector<pair<int, int>> eq[500002];  // y = x
int idx_eq[500002];
vector<pair<int, int>> op[500002];  // y = -x
int idx_op[500002];

vector<int> order;

void make(vector<pair<int, int>> &arr) {
    if (arr.empty()) return;
    arr.back().second = arr.back().first + 1;
    for (int i = arr.size() - 1; i > 0; i--) {
        if (arr[i - 1].first + 1 != arr[i].first)
            arr[i - 1].second = arr[i - 1].first + 1;
        else
            arr[i - 1].second = arr[i].second;
    }
}

void make_rev(vector<pair<int, int>> &arr) {
    if (arr.empty()) return;
    reverse(arr.begin(), arr.end());
    arr.back().second = arr.back().first - 1;
    for (int i = arr.size() - 1; i > 0; i--) {
        if (arr[i - 1].first - 1 != arr[i].first)
            arr[i - 1].second = arr[i - 1].first - 1;
        else
            arr[i - 1].second = arr[i].second;
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        eq[p[i].x - p[i].y + 250000].emplace_back(p[i].x, 1e9);
        op[p[i].x + p[i].y + 50000].emplace_back(p[i].x, 1e9);
        p[i].ax = p[i].ay = 1e7;
    }
    for (int i = 1; i <= 500000; i++) sort(eq[i].begin(), eq[i].end());
    for (int i = 1; i <= 500000; i++) sort(op[i].begin(), op[i].end());
    for (int i = 1; i <= n; i++) order.push_back(i);
    {
        for (int i = 1; i <= 500000; i++) make(op[i]);
        for (int i = 1; i <= 500000; i++) make(eq[i]);
        sort(order.begin(), order.end(), [](const int &a, const int &b) { return p[a].x < p[b].x; });
        for (auto &&i : order) {
            for (int dist = 1;; dist++) {
                {
                    int arr = p[i].x + p[i].y + 50000 + dist;
                    while ((idx_op[arr] < op[arr].size()) && (op[arr][idx_op[arr]].first < p[i].x)) idx_op[arr]++;
                    if ((idx_op[arr] == op[arr].size()) || (op[arr][idx_op[arr]].first > p[i].x)) {
                        p[i].RegisterAnswer(p[i].x, p[i].y + dist);
                        break;
                    } else {
                        int best = op[arr][idx_op[arr]].second;
                        if (best <= p[i].x + dist) {
                            p[i].RegisterAnswer(best, p[i].x + p[i].y + dist - best);
                            break;
                        }
                    }
                }
                {
                    int arr = p[i].x - p[i].y + 250000 + dist;
                    while ((idx_eq[arr] < eq[arr].size()) && (eq[arr][idx_eq[arr]].first < p[i].x)) idx_eq[arr]++;
                    if ((idx_eq[arr] == eq[arr].size()) || (eq[arr][idx_eq[arr]].first > p[i].x)) {
                        p[i].RegisterAnswer(p[i].x, p[i].y - dist);
                        break;
                    } else {
                        int best = eq[arr][idx_eq[arr]].second;
                        if (best <= p[i].x + dist) {
                            p[i].RegisterAnswer(best, best - p[i].x + p[i].y - dist);
                            break;
                        }
                    }
                }
            }
        }
    }

    {
        for (int i = 1; i <= 500000; i++) make_rev(op[i]);
        for (int i = 1; i <= 500000; i++) make_rev(eq[i]);
        for (int i = 1; i <= 500000; i++) idx_eq[i] = 0;
        for (int i = 1; i <= 500000; i++) idx_op[i] = 0;
        sort(order.begin(), order.end(), [](const int &a, const int &b) { return p[a].x > p[b].x; });
        for (auto &&i : order) {
            for (int dist = 1;; dist++) {
                {
                    int arr = p[i].x + p[i].y + 50000 - dist;
                    while ((idx_op[arr] < op[arr].size()) && (op[arr][idx_op[arr]].first > p[i].x)) idx_op[arr]++;
                    if ((idx_op[arr] == op[arr].size()) || (op[arr][idx_op[arr]].first < p[i].x)) {
                        p[i].RegisterAnswer(p[i].x, p[i].y - dist);
                        break;
                    } else {
                        int best = op[arr][idx_op[arr]].second;
                        if (best >= p[i].x - dist) {
                            p[i].RegisterAnswer(best, p[i].x + p[i].y - dist - best);
                            break;
                        }
                    }
                }
                {
                    int arr = p[i].x - p[i].y + 250000 - dist;
                    while ((idx_eq[arr] < eq[arr].size()) && (eq[arr][idx_eq[arr]].first > p[i].x)) idx_eq[arr]++;
                    if ((idx_eq[arr] == eq[arr].size()) || (eq[arr][idx_eq[arr]].first < p[i].x)) {
                        p[i].RegisterAnswer(p[i].x, p[i].y + dist);
                        break;
                    } else {
                        int best = eq[arr][idx_eq[arr]].second;
                        if (best >= p[i].x - dist) {
                            p[i].RegisterAnswer(best, best - p[i].x + p[i].y + dist);
                            break;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << p[i].ax << ' ' << p[i].ay << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}