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

// bit op
int popcnt(uint x) { return __builtin_popcount(x); }
int popcnt(ull x) { return __builtin_popcountll(x); }
int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }

//binary gcd
int gcd(int _a, int _b) {
    uint a = abs(_a), b = abs(_b);
    if (a == 0) return b;
    if (b == 0) return a;
    int shift = bsf(a|b);
    a >>= bsf(a);
    do {
        b >>= bsf(b);
        if (a > b) swap(a, b);
        b -= a;
    } while (b);
    return (a << shift);
}

struct StopWatch {
    bool f = false;
    clock_t st;
    void start() {
        f = true;
        st = clock();
    }
    int msecs() {
        assert(f);
        return (clock()-st)*1000 / CLOCKS_PER_SEC;
    }
} sw;


void unko() {
    cout << "NO" << endl;
    exit(0);
}

int ck = 0;
int n;
V<int> ans;
V<int> a;
V<int> bgc;
bool dfs(int p, int g1, int g2) {    
    ck++;
    if (ck == 100'000) {
        ck = 0;
        if (sw.msecs() > 450) unko();
    }
    if (g1 == 1 && g2 == 1) {
        for (int i = p; i < n; i++) {
            ans[i] = 0;
        }
        return true;
    }
    if (p == n) return false;
    if (gcd(g1, bgc[p]) != 1 || gcd(g2, bgc[p]) != 1) {
        return false;
    }

    int ng1 = gcd(g1, a[p]), ng2 = gcd(g2, a[p]);

    if (ng1 != g1 || ng2 == g2) {
        ans[p] = 0;
        if (dfs(p + 1, ng1, g2)) return true;
    }
    if (ng2 != g2) {
        ans[p] = 1;
        if (dfs(p + 1, g1, ng2)) return true;
    }
    return false;
}

int main() {
    sw.start();    
    srand(time(NULL));
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> n;

    V<int> _a(n);
    for (int i = 0; i < n; i++) {
        cin >> _a[i];
    }

    /*V<int> prs = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for (int i = 0; i < n; i++) {
        _a[i] = 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23;
    }

    int L = int(prs.size());

    for (int i = 0; i < L; i++) {
        _a[i] /= prs[i];
        _a[i + 1] /= prs[i];
    }*/

    V<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    for (int i = 0; i < 10; i++) random_shuffle(idx.begin(), idx.end());

    a = V<int>(n);
    for (int i = 0; i < n; i++) {
        a[idx[i]] = _a[i];
    }   
    bgc = V<int>(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        bgc[i] = gcd(bgc[i + 1], a[i]);
    }

    ans = V<int>(n);
    if (!dfs(0, 0, 0)) unko();
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        int d = ans[idx[i]];
        cout << d + 1 << " ";
    }
    cout << endl;
    return 0;
}