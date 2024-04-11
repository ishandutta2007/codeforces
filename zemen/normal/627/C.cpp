#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)
#define sz(x) ((int) (x).size())

int main() {
#ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
#endif
    ll d, cap, n;
    cin >> d >> cap >> n;
    vector<pair<ll, ll>> a;
    forn (i, n) {
        int x, p;
        scanf("%d%d", &x, &p);
        a.emplace_back(x, p);
    }
    a.emplace_back(0, 0);
    sort(a.begin(), a.end());
    a.emplace_back(d, 0);

    ll total = cap, cost = 0;
    deque<pair<ll, ll>> q;
    forn (i, n + 1) {
        while (!q.empty() && q.back().second > a[i].second)
            q.pop_back();
        q.push_back(a[i]);

        ll dist = a[i + 1].first - a[i].first;
        if (dist > cap) {
            cout << -1 << '\n';
            return 0;
        }
        while (total < a[i + 1].first) {
            while (!q.empty() && q.front().first + cap <= total)
                q.pop_front();
            assert(!q.empty());
            ll delta = min(q.front().first + cap - total, a[i + 1].first - total);
            cost += q.front().second * delta;
            total += delta;
        }
    }
    cout << cost << '\n';
}