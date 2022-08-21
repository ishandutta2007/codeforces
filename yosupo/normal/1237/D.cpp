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
    int n;
    cin >> n;
    V<int> a(4 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[n + i] = a[n + n + i] = a[n + n + n + i] = a[i];
    }

    V<int> res(n);
    deque<int> st;
    int r = 4 * n;
    for (int i = 4 * n - 1; i >= 0; i--) {
        int d = a[i];

        while (st.size() && a[st.back()] < (d + 1) / 2) {
            r = st.back();
            st.pop_back();
        }
        if (i < n) res[i] = r;
        while (st.size() && d <= a[st.front()]) st.pop_front();
        st.push_front(i);

    }

    dbg(res);
    for (int i = 0; i < n; i++) {
        int ans = res[i] - i;
        if (res[i] == 4 * n) ans = -1;
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}