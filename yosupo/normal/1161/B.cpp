#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
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
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x) true
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

// s[0..r[i]] == s[i..i+r[i]]
template <class S> V<int> z_algo(const S& s) {
    int n = int(s.size());
    V<int> r(n + 1);
    r[0] = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        int& k = r[i];
        k = (j + r[j] <= i) ? 0 : min(j + r[j] - i, r[i - j]);
        while (i + k < n && s[k] == s[i + k]) k++;
        if (j + r[j] < i + r[i]) j = i;
    }
    r[0] = n;
    return r;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    mt19937_64 gen(time(NULL)); // please don't hack

    int n , m;
    cin  >> n >> m;
    V<ull> d(n),hs(n);
    for (int i=0;i<n;i++) {
        d[i] = gen();
    }
    auto md = [&](int m) {
        return (m  % n + n)%  n;
    };
    for (int i= 0; i < m; i++) {
        int a,  b;
        cin >> a>>b; a--; b--;
        hs[a] ^= d[md(b - a)];
        hs[b] ^=d[md(a-b)];
    }

    auto z = z_algo(hs);
    for (int k=1; k  <n; k++)  {
        if (z[k] == (n - k) && z[n - k] == k) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}