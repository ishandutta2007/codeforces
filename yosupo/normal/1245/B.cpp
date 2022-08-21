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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int ca;
    cin >> ca;
    for (int tm = 0; tm < ca; tm++) {
        int n;
        int a, b, c;
        cin >> n >> a >> b >> c; // R, P, S
        string s, t;
        for (int i = 0; i < a; i++) {
            s += "R";
        }
        for (int i = 0; i < b; i++) {
            s += "P";
        }
        for (int i = 0; i < c; i++) {
            s += "S";
        }
        cin >> t;

        for (char& _c: t) {
            if (_c == 'R') _c = 'P';
            else if (_c == 'P') _c = 'S';
            else _c = 'R';
        }

        while (true) {
            bool update = false;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int f0 = 0, f1 = 0;
                    f0 += (s[i] == t[i]);
                    f0 += (s[j] == t[j]);
                    f1 += (s[i] == t[j]);
                    f1 += (s[j] == t[i]);

                    if (f0 < f1) {
                        update = true;
                        swap(s[i], s[j]);
                    }
                }
            }
            if (!update) break;
        }

        int u = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == t[i]) u++;
        }
        if (u >= (n + 1) / 2) {
            cout << "YES" << endl;
            cout << s << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}