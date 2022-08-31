//I hate math.

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <tuple>
#include <cstring>
#include <set>
#include <valarray>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    a = abs(a); b = abs(b);
    if (!a) return b;
    return gcd(b%a, a);
}

typedef pair<int, int> P;
const int MN = 110;
const ll INF = 1LL<<55;
ll d[MN][MN];
ll a[MN], b[MN];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> d[i][j];
        }
    }
    a[0] = 0;
    for (int j = 0; j < m; j++) {
        b[j] = d[0][j];
    }
    for (int i = 0; i < n; i++) {
        a[i] = d[i][0]-b[0];
    }
    ll u = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            u = gcd(u, d[i][j]-a[i]-b[j]);
        }
    }
    if (u == 0) {
        cout << "YES" << endl;
        cout << INF << endl;
        for (int i = 0; i < n; i++) {
            cout << (a[i]+INF)%INF << " ";
        } cout << endl;
        for (int j = 0; j < m; j++) {
            cout << (b[j]+INF)%INF << " ";
        } cout << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        a[i] %= u;
        a[i] = (a[i]+u)%u;
    }
    for (int j = 0; j < m; j++) {
        b[j] %= u;
        b[j] = (b[j]+u)%u;
    }
    bool f = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((a[i]+b[j])%u != d[i][j]) {
                f = false;
            }
        }
    }
    if (!f) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << u << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    } cout << endl;
    for (int j = 0; j < m; j++) {
        cout << b[j] << " ";
    } cout << endl;
    return 0;
}