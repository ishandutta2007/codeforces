#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<ll, ll> P;
typedef tuple<ll, int, int> E;
typedef pair<ll, int> B;

const int MN = 200200;
P lr[MN];

P dis[MN];

int used[MN];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll l, r;
        cin >> l >> r;
        lr[i] = P(l, r);
    }
    vector<E> ev;
    for (int i = 0; i < n-1; i++) {
        dis[i] = P(lr[i+1].first-lr[i].second, lr[i+1].second-lr[i].first);
        ev.push_back(E(dis[i].first, 0, i));
        ev.push_back(E(dis[i].second, 2, i));
    }

    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        ev.push_back(E(x, 1, i));
    }
    memset(used, -1, sizeof(used));
    sort(ev.begin(), ev.end());
    set<B> s;
    for (E e: ev) {
        ll x; int id, t;
        tie(x, t, id) = e;
        if (t == 0) {
            s.insert(B(dis[id].second, id));
        } else if (t == 1) {
            if (!s.size()) continue;
            int id2;
            tie(ignore, id2) = *s.begin();
            s.erase(s.begin());
            used[id2] = id;
        } else {
            if (used[id] == -1) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < n-1; i++) {
        cout << used[i]+1 << " ";
    } cout << endl;
    return 0;
}