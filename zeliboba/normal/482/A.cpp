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

int main() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        for (int i = 1; i <= n; ++i)
            printf("%d ", i);
        return 0;
    }
    int m = (n+1)/2;
    printf("%d ", m);
    vvi v(2);
    for (int i = n; i > m; --i)
        v[0].push_back(i);
    for (int i = 1; i < m; ++i)
        v[1].push_back(i);
    int t = 0;
    while (k > 1) {
        --k;
        printf("%d ", v[t].back());
        v[t].pop_back();
        t = 1-t;
    }
    for (int i = (int)v[1-t].size() - 1; i >= 0; --i)
        printf("%d ", v[1-t][i]);
    for (int i = 0; i < v[t].size(); ++i)
        printf("%d ", v[t][i]);
    return 0;
}