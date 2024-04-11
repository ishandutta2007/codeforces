#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef long double R;

const int MN = 100100;

int n, m, k;
vector<int> fo;
int deg[MN];
int num[MN];
vector<int> g[MN];
bool used[MN];

bool calc(R md) {
    for (int i = 0; i < n; i++) {
        num[i] = deg[i];
    }
    queue<int> q;
    for (int d: fo) {
        q.push(d);
    }
    fill_n(used, MN, false);
    while (q.size()) {
        int p = q.front(); q.pop();
        if (used[p]) continue;
        used[p] = true;
        for (int d: g[p]) {
            if (used[d]) continue;
            num[d]--;
            if ((R)num[d]/deg[d] < md) {
                q.push(d);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!used[i]) return true;
    }
    return false;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int d;
        cin >> d; d--;
        fo.push_back(d);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++; deg[b]++;   
    }

    R l = 0, r = 1;
    for (int i = 0; i < 100; i++) {
        R md = (l+r)/2;
        if (calc(md)) {
            l = md;
        } else {
            r = md;
        }
    }
    calc(l);
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (!used[i]) res.push_back(i);
    }
//    cout << l << " " << r << endl;
    cout << res.size() << endl;
    for (int d: res) {
        cout << d+1 << " ";
    } cout << endl;
    return 0;
}