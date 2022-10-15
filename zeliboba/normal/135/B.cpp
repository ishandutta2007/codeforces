#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<ll, ll> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

pii sub (pii a, pii b) {
    return pii(a.first - b.first, a.second - b.second);
}

ll norm (pii a) {
    return a.first * a.first + a.second * a.second;
}

ll scal (pii a, pii b) {
    return a.first * b.first + a.second * b.second;
}

bool check (vii & v) {
    sort(v.begin(), v.end());
    do {
        vii a(4);
        for (int i = 0; i < 4; ++i)
            a[i] = sub(v[(i + 1) % 4], v[i]);
        bool ok = 1;
        for (int i = 0; i < 3; ++i) if (scal(a[i], a[i + 1]) != 0)
            ok = 0;
        if (ok) {
            return 1;
        }
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}

bool sq (const vii & v) {
    ll d = norm(sub(v[0], v[3]));
    for (int i = 0; i < 3; ++i)
        if (norm(sub(v[i], v[i + 1])) != d)
            return 0;
    return 1;
}

int main() {
    int n = 8;
    vii v(8);
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i].first >> v[i].second;
//    sort(v.begin(), v.end());
    for (int mask = 0; mask < 1 << 8; ++mask) {
        vii v1, v2;
        for (int i = 0; i < 8; ++i) {
            if (mask & (1 << i))
                v1.push_back(v[i]);
            else v2.push_back(v[i]);
        }
        if (v1.size() == 4 && check(v1) && check(v2) && sq(v1)) {
            cout << "YES\n";
            for (int i = 0; i < 8; ++i) if (mask & (1 << i))
                cout << i + 1 << " ";
            cout << endl;
            for (int i = 0; i < 8; ++i) if (!(mask & (1 << i)))
                cout << i + 1 << " ";
            cout << endl;
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}