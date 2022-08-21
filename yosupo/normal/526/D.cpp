#include <bits/stdc++.h>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

// x^n % md
ll pow_mod(ll x, ll n, ll md) {
    ll r = 1;
    while (n) {
        if (n & 1) r = (r * x) % md;
        x = (x * x) % md;
        n >>= 1;
    }
    return r;
}

/// x, , mdxmd
//ll invp(ll x, ll md) {
//    return pow_mod(x, md-2, md);
//}
inline ll invp(ll a, ll m){
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    swap(a -= t * b, b);
    swap(u -= t * v, v);
  }
  return (u % m + m) % m;
}

ll hashM = 1e9+7;
ll hashD = 750827948;
ll invHashD;
const int MN = 1000100;
ll powT[MN];
ll invT[MN];
ll roT[MN];

int n;
string s;

void init() {
    powT[0] = 1;
    for (int i = 1; i < MN; i++) {
        powT[i] = powT[i-1]*hashD;
        powT[i] %= hashM;
    }
    invHashD = invp(hashD, hashM);
    invT[0] = 1;
    for (int i = 1; i < MN; i++) {
        invT[i] = invT[i-1]*invHashD;
        invT[i] %= hashM;
    }
    roT[0] = 0;
    for (int i = 1; i <= n; i++) {
        roT[i] = roT[i-1] + s[i-1]*powT[i-1];
        roT[i] %= hashM;
    }
}

ll hashL(int l, int r) {
    ll ro = roT[r] - roT[l];
    ro = ((ro % hashM) + hashM) % hashM;
    ro *= invT[l];
    ro %= hashM;
    return ro;    
}
bool same(int p, int l, int r) {
//    assert(l < r);
    if (r > n) return false;
    // s[0..p] == s[l..r]
    ll ro = roT[r] - roT[l];
    ro = ((ro % hashM) + hashM) % hashM;
    ro *= invT[l];
    ro %= hashM;
    return roT[p] == ro;
}

int imos[MN];
bool res[MN];

char buff[MN];
int main() {
    memset(imos, -1, sizeof(imos));
    int k;
    scanf("%d %d", &n, &k);
    scanf("%s", buff);
    s = buff;
    init();
    for (int i = 1; i <= n; i++) {
        if (i * k > n) break;
        bool f = true;
        for (int j = 1; j < k; j++) {
            if (!same(i, i*j, i*(j+1))) {
                f = false;
                break;
            }
        }
        if (!f) continue;
        int l = 0, r = i+1;
        while (r - l > 1) {
            int md = (l+r)/2;
            if (same(md, i*k, i*k+md)) {
                l = md;
            } else {
                r = md;
            }
        }
        imos[i*k] = max(imos[i*k], l);
    }
    int u = -1;
    string s;
    for (int i = 0; i <= n; i++) {
        u = max(u, imos[i]);
        if (u >= 0) {
            s += '1';
        } else {
            s += '0';
        }
        u--;
    }
    s = s.substr(1, n);
    printf("%s\n", s.c_str());
    return 0;
}