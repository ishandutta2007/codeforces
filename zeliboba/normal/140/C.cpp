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

vi a;
vvi res;

bool make(int k) {
    res.assign(k, vi(3, 0));
    for (int i = 0; i < k; ++i)
        res[i][0] = a[i];
    int it = k;
    for (int i = 0; i < k; ++i) {
        while (it < a.size()) {
            if (a[it] > res[i][0]) {
                res[i][1] = a[it];
                ++it;
                break;
            }
            ++it;
        }
        if (it >= a.size() && res[i][1] == 0) {
//            cerr << i << " " << it << endl;
            return 0;
        }
    }
    for (int i = 0; i < k; ++i) {
        while (it < a.size()) {
            if (a[it] > res[i][1]) {
                res[i][2] = a[it];
                ++it;
                break;
            }
            ++it;
        }
        if (it >= a.size() && res[i][2] == 0) {
//            cerr << i << " " << it << " " << 2 << endl;
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int l = 0, r = n / 3 + 1;
    while (r - l > 1) {
        int x = (r + l) / 2;
//        cerr << x << endl;
        if (make(x))
            l = x;
        else r = x;
    }
    cout << l << endl;
    make(l);
    for (int i = 0; i < res.size(); ++i) {
        printf("%d %d %d\n", res[i][2], res[i][1], res[i][0]);
    }
    return 0;
}