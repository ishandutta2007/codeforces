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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

class V {
public:
    int l;
    int nx[26];
    int w;
    int w1;
    vi all;
};

vector<V> pool(200000);

int main() {
    int n, k;
    cin >> n >> k;
    vs v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    pool[0].l = 0;
    for (int i = 0; i < n; ++i) {
        pool[0].all.push_back(i);
    }
    int sz = 1;
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < 26; ++j) pool[i].nx[j] = -1;
        int l = pool[i].l;
        for (int j = 0; j < pool[i].all.size(); ++j) if (l < v[pool[i].all[j]].size()) {
            int ind = v[pool[i].all[j]][l] - 'a';
            if (pool[i].nx[ind] == -1) {
                pool[i].nx[ind] = sz;
                pool[sz].l = l + 1;
                ++sz;
//                assert(sz < pool.size());
            }
            pool[pool[i].nx[ind]].all.push_back(pool[i].all[j]);
        }
    }
    for (int i = sz - 1; i >= 0; --i) {
        pool[i].w = 0;
        pool[i].w1 = 0;
        int cnt = 0;
        for (int j = 0; j < 26; ++j) if (pool[i].nx[j] != -1) {
            ++cnt;
            if (pool[pool[i].nx[j]].w == 0)
                pool[i].w = 1;
            if (pool[pool[i].nx[j]].w1 == 0)
                pool[i].w1 = 1;
        }
        if (cnt == 0) pool[i].w1 = 1;
//        cerr << i << ' ' << pool[i].w << endl;
    }
    int w = pool[0].w;
    int w1 = pool[0].w1;
    if (w && (w1 || k % 2)) {
        printf("First\n");
    } else {
        printf("Second\n");
    }
    return 0;
}