#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

int n, l;
V<ll> a, b;

bool check(int m) {
    int lw = -1, up = -1;
    for (int i = 0; i < 3*n; i++) {
        if (a[0]-m <= b[i] && b[i] <= a[0]+m) {
            lw = i;
            break;
        }
    }
    if (lw == -1) return false;
    up = lw;
    while (up < 3*n && b[up] <= a[0]+m) up++;
    for (int i = 1; i < n; i++) {
        lw++; up++;
        while (lw < 3*n && b[lw] < a[i]-m) lw++;
        while (up > 0 && a[i]+m < b[up-1]) up--;
        if (lw >= up) return false;
    }
    return true;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    cin >> n >> l;
    a = V<ll>(n); b = V<ll>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i] -= l;
    }
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    for (int ph = 1; ph <= 2; ph++) {
        for (int i = 0; i < n; i++) {
            b.push_back(b[i] + ph*l);
        }
    }

    int lw = -1, up = l/2;
    while (up-lw > 1) {
        int md = (lw+up)/2;
        if (!check(md)) {
            lw = md;
        } else {
            up = md;
        }
    }
    cout << up << endl;
    return 0;
}