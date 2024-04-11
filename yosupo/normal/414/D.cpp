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
#include <map>
#include <complex>
using namespace std;

typedef long long ll;
const int MN = 101000;
vector<int> g[MN];
vector<int> h;
void dfs(int a, int b, int hh) {
    h.push_back(hh);
    for (int i: g[a]) {
        if (i == b) continue;
        dfs(i, a, hh+1);
    }
}

int main() {
    int n;
    ll k, p;
    cin >> n >> k >> p;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, -1, 0);
    sort(h.begin(), h.end(), greater<int>());
    ll pp = 0, j = 0, res = 1, r = 0;
    for (int i = 0; i < n-1; i++) {
        if (i) {
            pp -= (h[i-1]-h[i])*(j-i);
        }
        while (j < n-1) {
            if (pp+h[i]-h[j] > p) break;
            pp += h[i]-h[j];
            j++;
        }
        res = max(res, j-i);
    }
    cout << min(res, k) << endl;
    return 0;
}