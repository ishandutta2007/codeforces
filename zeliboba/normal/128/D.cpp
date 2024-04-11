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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int t1 = 0, t2 = 0, mi = 1000000000, ma = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] & 1)
            ++t1;
        else ++t2;
        mi = min(mi, a[i]);
        ma = max(ma, a[i]);
    }
    if (t1 != t2 || ma - mi > n) {
        cout << "NO\n";
        return 0;
    }
    vector<int> v(ma - mi + 1);
    for (int i = 0; i < n; ++i)
        v[a[i] - mi]++;
    for (int i = 0; i + 1 < v.size(); ++i) if (v[i] == 1 && v[i + 1] == 1) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 0; i < v.size(); ++i) if (v[i] == 0) {
        cout << "NO\n";
        return 0;
    }
    if (v.size() == 2) {
        cout << "YES\n";
        return 0;
    }
    vi s(v.size() + 2);
    for (int i = 0; i < v.size(); ++i) {
        s[i + 2] = s[i] + v[i];
    }
//    ma = 0;
//    int best = 0;
    for (int i = 2; i + 2 < s.size(); ++i) {
        if (s[i] - s[i + 1] > -1) {
            cout << "NO\n";
            return 0;
        }
//        ma = min(ma, s[i] - s[i - 1]);
    }
    cout << "YES\n";
    return 0;
}