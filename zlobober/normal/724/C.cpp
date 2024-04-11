#include <cstdio>
#include <algorithm>
#include <cassert>
#include <set>
using namespace std;

typedef long long llong;

const int N = 200500;

int n, m;

struct field {
    set<pair<int, int>> by_ymx[N];

    pair<set<pair<int, int>>*, set<pair<int, int>>::iterator> pos[N];

    const int sy, sx;

    field(int _sy, int _sx) : sy(_sy), sx(_sx) {}

    set<pair<int, int>>& get(int diff) {
        assert(diff < n && diff > -m);
        return by_ymx[diff + m];
    }

    inline void add(int y, int x, int i) {
        int ymx = y - x + m;
        pos[i] = make_pair(&by_ymx[ymx], by_ymx[ymx].insert(make_pair(min(x, y), i)).first);
    }

    inline void init() {
    }

    void erase(int i) {
        pos[i].first->erase(pos[i].second);
    }

} F[2][2] = {
    {field(0, 0), field(0, 1)},
    {field(1, 0), field(1, 1)}
}; // sy sx

llong ans[N];

int main() {
    int k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &y, &x);
        F[0][0].add(y, x, i);
        F[1][0].add(n - y, x, i);
        F[0][1].add(y, m - x, i);
        F[1][1].add(n - y, m - x, i);
        ans[i] = -1;
    }
    for (int sy = 0; sy < 2; sy++) {
        for (int sx = 0; sx < 2; sx++) {
            F[sy][sx].init();
        }
    }

    int sy = 0, sx = 0;

    llong py = 0, px = 0;

    while (true) {
        llong ymx = px - py;
        assert(-m <= ymx && ymx <= n);


        vector<pair<int, int>> todel;
        for (const auto& pr : F[sy][sx].get(ymx)) {
            int id = pr.second;
            int dt = pr.first;
            ans[id] = max(py, px) + dt;
            todel.push_back(pr);
        }

        for (const auto& pr : todel) {
            int id = pr.second;
            for (int sy = 0; sy < 2; sy++) {
                for (int sx = 0; sx < 2; sx++) {
                    F[sy][sx].erase(id);
                }
            }
        }

        if (py + n < px + m) {
            py += n;
            sy ^= 1;
        } else if (py + n > px + m) {
            px += m;
            sx ^= 1;
        } else {
            break;
        }
    }

    for (int i = 0; i < k; i++) {
        printf("%lld\n", ans[i]);
    }

}