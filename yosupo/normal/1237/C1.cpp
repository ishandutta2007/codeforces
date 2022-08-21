//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL
#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

#ifdef LOCAL
struct PrettyOS {
    ostream& os;
    bool first;
    template <class T> auto operator<<(T&& x) {
        if (!first) os << ", ";
        first = false;
        os << x;
        return *this;
    }
};
template <class... T> void dbg0(T&&... t) {
    (PrettyOS{cerr, true} << ... << t);
}
#define dbg(...)                                            \
    do {                                                    \
        cerr << __LINE__ << " : " << #__VA_ARGS__ << " = "; \
        dbg0(__VA_ARGS__);                                  \
        cerr << endl;                                       \
    } while (false);
#else
#define dbg(...)
#endif

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

struct P {
    int x, y, z, id;
};
// all z is same
int solve(V<P> ps) {
    map<int, V<P>> ps2;
    for (auto p: ps) {
        ps2[p.y].push_back(p);
    }
    V<int> ids;
    for (auto p : ps2) {
        sort(p.second.begin(), p.second.end(), [&](P a, P b) {
            return a.x < b.x;
        });
        while (int(p.second.size()) >= 2) {
            cout << p.second.back().id;
            p.second.pop_back();
            cout << " " << p.second.back().id << endl;
            p.second.pop_back();
        }
        if (p.second.size()) ids.push_back(p.second[0].id);
    }
    while (int(ids.size()) >= 2) {
        cout << ids.back();
        ids.pop_back();
        cout << " " << ids.back() << endl;
        ids.pop_back();
    }
    if (ids.size()) return ids[0];
    return -1;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    map<int, V<P>> ps;
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        ps[z].push_back(P{x, y, z, i + 1});
    }
    V<int> ids;
    for (auto p: ps) {
        int u = solve(p.second);
        if (u != -1) ids.push_back(u);
    }
    while (ids.size()) {
        cout << ids.back();
        ids.pop_back();
        cout << " " << ids.back() << endl;
        ids.pop_back();
    }
    return 0;
}