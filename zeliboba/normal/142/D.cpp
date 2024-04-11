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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> vs(n);
    bool okf = 0, oks = 0;
    vi a(n);
    int cnt = 0;
    if (m == 1) {
        cout << "Second\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> vs[i];
        if (m == 2 && vs[i][0] == vs[i][1])
            continue;
        int wasg = 0, wasr = 0;
        for (int j = 0; j < vs[i].size(); ++j) {
            if (vs[i][j] == 'G')
               wasg = 1 + j;
            if (vs[i][j] == 'R')
                wasr = 1 + j;
        }
        if (wasg && !wasr)
            okf = 1;
        if (wasr && !wasg)
            oks = 1;
        if (wasg && wasr) {
            a[i] = abs(wasg - wasr) - 1;
            ++cnt;
        }
    }
    if (okf && oks) {
        cout << "Draw\n";
        return 0;
    }
    if (okf && !oks) {
        cout << "First\n";
        return 0;
    }
    if (oks && !okf) {
        cout << "Second\n";
        return 0;
    }
    vl cur(20);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < cur.size(); ++j)
            if (a[i] & (1 << j))
                cur[j]++;
    }
    bool ok = 0;
    for (int i = 0; i < cur.size(); ++i)
        if (cur[i] % (k + 1))
            ok = 1;
    if (ok) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
    return 0;
}