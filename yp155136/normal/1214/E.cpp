#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 200006;
#define F first
#define S second

int d[N];

int f1(int i) {
    return 2 * i - 1;
}

int f2(int i) {
    return 2 * i;
}

int a[N];

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pii> v;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        v.push_back({d[i], i});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    if (v[0].F == 1) {
        for (int i = 1; i < 2 * n; ++i) {
            cout << i << ' ' << i + 1 << endl;
        }
        return 0;
    }
    vector<pii> e;
    int len = v[0].F + 1;
    a[1] = f1(v[0].S);
    a[len] = f2(v[0].S);
    for (int i = 2; i < len; ++i) {
        a[i] = f1(v[i - 1].S);
    }
    int ptr = 1;
    int ed = len;
    for (int i = 2; i < len; ++i) {
        a[i] = f1(v[ptr].S);
        e.push_back({a[i + v[ptr].F - 1], f2(v[ptr].S)});
        if (i + v[ptr].F - 1 == ed) {
            a[ed + 1] = f2(v[ptr].S);
            ++ed;
        }
        ++ptr;
    }
    while (ptr != n) {
        e.push_back({a[1], f1(v[ptr].S)});
        if (v[ptr].F != 1)e.push_back({a[1 + v[ptr].F - 2], f2(v[ptr].S)});
        else e.push_back({f1(v[ptr].S), f2(v[ptr].S)});
        ++ptr;
    }
    for (pii p: e) {
        cout << p.F << ' ' << p.S << '\n';
    }
    for (int i = 1; i < len; ++i) {
        cout << a[i] << ' ' << a[i + 1] << '\n';
    }
}