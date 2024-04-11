#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, K = 20;
int n, m, lg[N];
pair<int, int> p[N], tmp[N];
long long val[N], c[N];
long long pre[N], suf[N];
struct ST {
    long long mx[N][K];
    void init(long long *a) {
        for (int i = n; i; --i) {
            mx[i][0] = a[i];
            for (int k = 1; k < K && i + (1 << k) - 1 <= n; ++k) {
                mx[i][k] = max(mx[i][k - 1], mx[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    long long query(int l, int r) {
        if (l > r) {
            return -1e18;
        }
        int k = lg[r - l + 1];
        return max(mx[l][k], mx[r - (1 << k) + 1][k]);
    }
} t1, t2, t3;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for (int i = 2; i < N; ++i) {
        lg[i] = lg[i >> 1] + 1;
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> p[i].first >> p[i].second;
            tmp[i] = p[i];
            val[i] = 0;
        }
        sort(p + 1, p + n + 1);
        {
            multiset<int> s;
            long long sum = 0;
            for (int i = 1; i <= n; ++i) {
                while (!s.empty() && *s.begin() < p[i].first) {
                    sum -= *s.begin();
                    s.erase(s.begin());
                }
                s.insert(p[i].first + p[i].second);
                sum += p[i].first + p[i].second;
                val[i] += sum - (long long) s.size() * p[i].first;
            }
        }
        {
            multiset<int> s;
            long long sum = 0;
            for (int i = n; i; --i) {
                while (!s.empty() && *--s.end() > p[i].first) {
                    sum -= *--s.end();
                    s.erase(--s.end());
                }
                val[i] += (long long) s.size() * p[i].first - sum;
                s.insert(p[i].first - p[i].second);
                sum += p[i].first - p[i].second;
            }
        }
        t1.init(val);
        for (int i = 1; i <= n; ++i) {
            c[i] = val[i] - p[i].first;
        }
        t2.init(c);
        for (int i = 1; i <= n; ++i) {
            c[i] = val[i] + p[i].first;
        }
        t3.init(c);
        auto find = [&](int x) {
            return upper_bound(p + 1, p + n + 1, make_pair(x, (int) 2e9)) - p - 1;
        };
        for (int i = 1; i <= n; ++i) {
            int x = tmp[i].first, y = tmp[i].second;
            int l = find(x - y - 1) + 1, m = find(x), r = find(x + y);
            if (max(t1.query(1, l - 1), t1.query(r + 1, n)) > ::m) {
                cout << "0";
            } else if (max(t2.query(l, m) + x - y, t3.query(m + 1, r) - x - y) > ::m) {
                cout << "0";
            } else {
                cout << "1";
            }
        }
        cout << "\n";
    }
    return 0;
}