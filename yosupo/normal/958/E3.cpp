#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

struct P {
    int x, y, id;
    P operator-(const P &r) const {
        return P{x-r.x, y-r.y, -1};
    }
};

int cross(P a, P b) {
    return a.x * b.y - a.y * b.x;
}

// -1, 1 : clock, cclock;
int ccw(P b, P c) {
    int x = cross(b, c);
    assert(x);
    if (cross(b, c) > 0) return 1;
    else return -1;
}
int ccw(P a, P b, P c) { return ccw(b-a, c-a); }

using Pol = V<P>;

Pol up_convex(const Pol &p) {
    if (p.size() <= 2) return p;
    Pol up;
    for (P d: p) {
        while (up.size() > 1 && ccw(up[up.size()-2], up[up.size()-1], d) == 1) up.pop_back();
        up.push_back(d);
    }
    return up;
}

bool comp(const P &a, const P &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n;
    cin >> n;
    Pol points;
    for (int i = 0; i < 2*n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(P{x, y, i});
    }
    sort(begin(points), end(points), comp);

    V<int> res(n);

    V<Pol> st; st.push_back(points);

    while (st.size()) {
        Pol v = st.back(); st.pop_back();
        if (v.size() == 0) continue;
        bool c1 = v.front().id < n;
        bool c2 = v.back().id < n;
        if (c1 != c2) {
            auto uv = up_convex(v);
            int m = int(uv.size());
            int id1 = -1, id2 = -1;
            for (int i = 0; i < m-1; i++) {
                bool c1 = uv[i].id < n;
                bool c2 = uv[i+1].id < n;
                if (c1 != c2) {
                    id1 = uv[i].id; id2 = uv[i+1].id;
                    break;
                }
            }
            assert(id1 != -1);
            if (id1 > id2) swap(id1, id2);
            res[id1] = id2 - n;

            v.erase(remove_if(begin(v), end(v), [&](P p){
                return p.id == id1 || p.id == id2;
            }), end(v));
            st.push_back(v);
        } else {
            int cnt = 0;
            int m = int(v.size());
            for (int i = 0; i < m; i++) {
                assert(i != m-1);
                bool c1 = v[i].id < n;
                if (c1) cnt++;
                else cnt--;
                if (cnt == 0) {
                    auto vl = Pol(begin(v), begin(v)+i+1);
                    auto vr = Pol(begin(v)+i+1, end(v));
                    st.push_back(vl);
                    st.push_back(vr);
                    break;
                }
            }
        }
    }

    for (int d: res) {
        cout << d+1 << endl;
    }
    return 0;
}