#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MN = 5010;
const ll MA = 1e9+10;
ll a[MN];
set<ll> b;
bool f[5000] = {};
vector<ll> p;
ll solve(ll a) {
    ll r = 0;
    for (int i = 0; i < p.size(); i++) {
        ll d = p[i];
        int h = (f[i]) ? -1 : 1;
        while (!(a%d)) {
            a /= d;
            r += h;
        }
    }
    if (a != 1) {
        r += (b.count(a)) ? -1 : 1;
    }
    return r;
}
ll gcd(ll a, ll b) {
    if (b==0) return a;
    return gcd(b, a%b);
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a2;
        scanf("%d", &a2);
        a[i] = a2;
    }
    for (int i = 0; i < m; i++) {
        int b2;
        scanf("%d", &b2);
        b.insert(b2);
    }
    bool us[100000] = {};
    for (ll i = 2; i*i <= MA; i++) {
        if (!us[i]) {
            p.push_back(i);
            for (ll j = i; j*j <= MA; j += i) {
                us[j] = true;
            }
        }
    }
    for (int i = 0; i < p.size(); i++) {
        f[i] = b.count(p[i]);
    }
    ll r = 0;
    /*for (ll d: b) {
        int u = 100000;
        for (int j = 0; j < n; j++) {
            int u2 = 0;
            while (!(a[j]%d)) {
                u2++;
                a[j] /= d;
            }
            if (!j) u = u2;
            u = min(u, u2);
            r -= u2-u;
        }
    }*/
    for (int i = 0; i < n; i++) {
        r += solve(a[i]);
    }
    ll gc[MN];
    gc[0] = a[0];
    for (int i = 1; i < n; i++) {
        gc[i] = gcd(gc[i-1], a[i]);
    }
    int t = 1;
    for (int i = n-1; i >= 0; i--) {
        gc[i] /= t;
        ll u = solve(gc[i]);
        if (u < 0) {
            r -= u*(i+1);
            t *= gc[i];
        }
    }
    cout << r << endl;
    return 0;
}