#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
    int n;
    scanf("%d", &n);
    vi a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
    }
    vi was(n);
    vvi c;
    for (int i = 0; i < n; ++i) if (!was[i]) {
        int cur = i;
        c.push_back(vi());
        while (!was[cur]) {
            was[cur] = 1;
            c.back().push_back(cur);
            cur = a[cur];
        }
    }
    for (int i = 0; i < c.size(); ++i) {
        if (c[i].size() == 1) {
            cout << "YES\n";
            int b = c[i][0];
            for (int v = 0; v < n; ++v) if (b != v) {
                cout << v+1 << ' ' << b + 1 << endl;
            }
            return 0;
        }
    }
    bool alleven = 1;
    for (int i = 0; i < c.size(); ++i) if (c[i].size() % 2) {
        alleven = 0; break;
    }
    if (alleven) {
        for (int i = 0; i < c.size(); ++i) if (c[i].size() == 2) {
            cout << "YES\n";
            cout << c[i][0] + 1 << ' ' << c[i][1] + 1 << endl;
            for (int j = 0; j < c.size(); ++j) if (j != i) {
                for (int l = 0; l < c[j].size(); ++l) {
                    cout << c[j][l] + 1 << ' ' << c[i][l%2] + 1 << endl;                
                }
            }
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}