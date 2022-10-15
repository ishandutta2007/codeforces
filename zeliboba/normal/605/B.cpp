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
    int n, m;
    cin >> n >> m;
    vii a, b;
    for (int i = 0; i < m; ++i) {
      int x,y;
      scanf("%d%d", &x, &y);
      if (y == 1) a.push_back(pii(x, i));
      else b.push_back(pii(x, i));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vii res(m);
    bool fail = 0;
    for (int i = 0; i < a.size(); ++i) {
      res[a[i].second] = pii(i, i + 1);
    }
    pii p(n-3, n-1);
    for (int i = b.size() - 1; i >= 0; --i) {
      while (p.second && (b[i].first < a[p.second - 1].first || p.first < 0)) {
        --p.second;
        p.first = p.second - 2;
      }
      if (p.first < 0) {
        fail = 1;
        break;
      }
      res[b[i].second] = p;
      --p.first;
    }
    if (fail) {
      printf("-1\n");
    } else {
      for (int i = 0; i < m; ++i) {
        printf("%d %d\n", res[i].first + 1, res[i].second + 1);
      }    
    }
    return 0;
}