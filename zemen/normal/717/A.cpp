#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int mod = 1e9 + 7;
const int N = 1010;

int add(int x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}

int sub(int x, int y) {
    x -= y;
    if (x < 0)
        x += mod;
    return x;
}

int mul(ll x, ll y) {
    return x * y % mod;
}

int bin(int x, int n) {
    int y = 1;
    while (n) {
        if (n & 1)
            y = mul(x, y);
        x = mul(x, x);
        n >>= 1;
    }
    return y;
}

int inv(int x) {
    assert(x != 0);
    return bin(x, mod - 2);
}


struct Num {
    int x, y;

    Num operator + (const Num &o) const {
        return {add(x, o.x), add(y, o.y)};
    }
    Num operator - (const Num &o) const {
        return {sub(x, o.x), sub(y, o.y)};
    }
    Num operator * (const Num &o) const {
        int a = mul(x, o.x);
        a = add(a, mul(5, mul(y, o.y)));
        int b = add(mul(x, o.y), mul(y, o.x));
        return {a, b};
    }

    bool operator == (const Num &o) const {
        return x == o.x && y == o.y;
    }

    Num operator ~ () const {
        return {x, sub(0, y)};
    }

    int norm() const {
        return sub(mul(x, x), mul(5, mul(y, y)));
    }

    Num operator / (int a) const {
        int b = inv(a);
        return {mul(x, b), mul(y, b)};
    }

    Num operator / (const Num &o) const {
        return ((*this) * (~o)) / o.norm();
    }
};

Num num(int x) {
    return Num{x, 0};
}


int f[N], s[N], fib[N], rf[N], c[N][N];
Num phi, s5, hi;

void pre() {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < N; ++i)
        fib[i] = add(fib[i - 1], fib[i - 2]);

    f[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = mul(i, f[i - 1]);

    for (int i = 0; i < N; ++i)
        rf[i] = inv(f[i]);

    //for (int i = 0; i < mod; ++i) {
        //if (mul(i, i) == 5) {
            //cout << i << endl;
            //return;
        //}
    //}

    for (int i = 0; i < N; ++i)
        c[i][0] = 1;
    for (int i = 1; i < N; ++i)
        for (int j = 1; j < N; ++j)
            c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);

    phi = Num{1, 1} / num(2);
    hi = Num{mod - 1, 0} / phi;
    s5 = Num{0, 1};
}

Num binn(Num a, ll to) {
    Num b = num(1);
    while (to) {
        if (to & 1)
            b = b * a;
        a = a * a;
        to >>= 1;
    }
    return b;
}

Num getSumProb(Num a, ll n) { // 1 + ... + a^(n - 1)
    if (a == num(1))
        return num(n % mod);
    Num up = binn(a, n) - num(1);
    Num down = a - num(1);
    return up / down;
}

int getFibSum(int k, ll n) {
    Num ans = num(0);
    for (int i = 0; i <= k; ++i) {
        Num bon = num(mul(c[k][i], bin(mod - 1, k - i)));

        Num cur = binn(phi, i) * binn(hi, k - i);

        ans = ans + (bon * getSumProb(cur, n));
    }

    ans = ans / binn(s5, k);
    assert(ans.y == 0);
    return ans.x;
}

int getFib(int n) {
    Num ans = binn(phi, n) - binn(hi, n);
    ans = ans / s5;
    assert(ans.y == 0);
    return ans.x;
}

int getFibSumNaive(int k, int n) {
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = add(ans, bin(fib[i], k));
    return ans;
}

void testFib() {
    for (int k = 0; k < 100; ++k) {
        for (int n = 0; n < 100; ++n) {
            int l = getFibSum(k, n);
            int r = getFibSumNaive(k, n);
            if (l != r) {
                cout << k << " " << n << endl;
                cout << l << " " << r << endl;
                return;
            }
        }
    }
}


int k;
ll l, r;
int C[N];

void read() {
    cin >> k >> l >> r;
    r += 3;
    l += 2;
}

void kill() {
    for (int i = 0; i < N; ++i) {
        int x = 1;
        for (int j = 0; j < k; ++j)
            x = mul(x, sub(fib[i], j));
        x = mul(x, rf[k]);
        s[i] = x;
    }

    for (int i = 1; i < N; ++i)
        s[i] = add(s[i], s[i - 1]);
}

int getSum(ll r) {
    fill(C, C + N, 0);
    C[0] = 1;
    for (int i = 0; i < k; ++i) {
        for (int j = N - 1; j >= 1; --j) 
            C[j] = sub(C[j], mul(i, C[j - 1]));
    }

    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int bon = getFibSum(k - i, r);
        ans = add(ans, mul(C[i], bon));
    }

    ans = mul(ans, rf[k]);

    return ans;
}

int naiveSum(ll r) {
    return s[r - 1];
}

void testSum() {
    for (int i = 1; i < 100; ++i)
        assert(getSum(i) == naiveSum(i));
    return;
    for (int i = 0; i < N; ++i)
        if (getSum(i) != naiveSum(i)) {
            cerr << "wrong at " << i << endl;
            return;
            //assert(getSum(i) == naiveSum(i));
        }
}

void finish_him() {
    ll ans = sub(getSum(r), getSum(l));
    cout << ans << endl;
}

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif

    pre();
    //testFib();

    read();
    kill();

    //testSum();
    finish_him();
    cerr << "Time: " << clock()/1000 << endl;
    //test();
    return 0;
}