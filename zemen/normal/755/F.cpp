#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 1001000;
int p[maxn];
bool used[maxn];
int cnt[maxn];
int n, k;
vector<int> a;

int gcd(int a, int b) {
    while (a && b)
        if (a >= b)
            a %= b;
        else
            b %= a;
    return a + b;
}

bitset<maxn> bs, nbs;
int solveMn() {
    if (k == 1)
        return k + 1;

    bs[0] = 1;
    int B = 0;
    forn (i, maxn) {
        if (cnt[i] == 0)
            continue;
        //cerr << i << ' ' << cnt[i] << '\n';
        B += cnt[i] * i;
        if (cnt[i] <= 10) {
            forn (iter, cnt[i]) {
                bs |= bs << i;
                if (bs[k]) {
                    return k;
                }
            }
            continue;
        }
        forn (rem, i) {
            int cc = 0;
            int block = i * (cnt[i] + 1);
            for (int j = rem; j <= B; j += i) {
                cc += bs[j];
                if (j - block >= 0)
                    cc -= bs[j - block];
                nbs[j] = cc > 0;
            }
        }
        bs = nbs;
        //cerr << B << ' ' << bs[B] << '\n';
        if (bs[k])
            return k;
    }
    if (bs[k])
        return k;

    //cerr << B << '\n';
    //forn (i, B)
        //if (bs[i])
            //cerr << i << '\n';

    return k + 1;
}

int solveMx() {
    int q = 0;
    for (int x: a)
        q += x / 2;
    if (k <= q)
        return k * 2;
    return min(n, q * 2 + (k - q));
}

int main() {
    #ifdef LOCAL
    assert(freopen("f.in", "r", stdin));
    #else
    #endif
    cin >> n >> k;
    forn (i, n) {
        scanf("%d", p + i);
        --p[i];
    }
    forn (i, n) {
        if (used[i])
            continue;
        int u = i;
        int x = 0;
        while (!used[u]) {
            used[u] = true;
            ++x;
            u = p[u];
        }
        a.push_back(x);
        cnt[x]++;
    }
    //for (int x: a)
        //cerr << x << '\n';
    cout << solveMn() << ' ' << solveMx() << '\n';
}