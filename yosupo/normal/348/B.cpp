#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

ll lcm(ll a, ll b) {
    return a/gcd(a, b)*b;
}

ll a[100010];
ll po[300010], r[300010];
vector<int> v[300010];

void solve(int b, int p) {
    if (r[p] != -1) return;
    ll s = v[p].size()-1;
    if (!s) {
        po[p] = 1;
        r[p] = a[p];
        return;
    }
    ll m = 10e15;
    ll g = 1;
    for (int u: v[p]) {
        if (u == b) continue;
        solve(p, u);
        g = lcm(g, po[u]);
        m = min(m, r[u]);
        if (g > m) {
            r[p] = 0;
            po[p] = 1;
            return;
        }
    }
    ll d = (m/g)*g*s;
    r[p] = d;
    po[p] = g*s;
    if (!po[p] && (s && g)) exit(15);
    return;
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    ll u = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        u += a[i];
    }
    for (int i = 0; i < 300010; i++) {
        r[i] = -1;
        po[i] = 1;
    }
    int x, y;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        x--; y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    v[0].push_back(0);
    solve(0, 0);
    cout << u - r[0] << endl;
    return 0;
}