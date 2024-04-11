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
typedef pair<ll, int> pli;
typedef pair<double, double> pdd;
typedef vector<string> vs;
const int P = 131;
const int mod = 989324527;

int main() {
  int n, m;
  string s;
  cin >> n >> s >> m;
  char w[1005];
  map<pli, int> h;
  vi was(1e6);
  vector<string> ws(m);
  for (int i = 0; i < m; ++i) {
    scanf("%s", w);
    ll x = 0, y = 0;
    int len = strlen(w);
    ws[i].resize(len);
    for (int j = 0; j < len; ++j) {
      ws[i][j] = w[j];
      char c = tolower(w[j]);
      x = x*P + c;
      y = (y*P + c) % mod;
    }
    h[pli(x, y)] = i;
    was[y%was.size()] = 1;
  }
  vi d(s.size() + 1, -1);
  vi ind(s.size() + 1, -1);
  d[0] = 0;
  vl pw(1e5, 1);
  vl pwmod(pw.size(), 1);
  for (int i = 1; i < pw.size(); ++i) {
    pw[i] = pw[i-1]*P;
    pwmod[i] = pwmod[i-1]*P%mod;
  }
  for (int i = 0; i < d.size(); ++i) if (d[i] >= 0) {
    ll x = 0, y = 0;
    for (int l = 1; l <= 1000 && i+l < d.size(); ++l) {
      x += s[i+l-1]*pw[l-1];
      y = (y + s[i+l-1]*pwmod[l-1]) % mod;
      if (d[i+l] < 0 && was[y%was.size()] && h.count(pli(x, y))) {
        d[i+l] = i;
        ind[i+l] = h[pli(x, y)];
      }
    }
  }
  assert(d.back() >= 0);
  int cur = s.size();
  vs res;
  while (cur != 0) {
    res.push_back(ws[ind[cur]]);
    cur = d[cur];
  }
  reverse(res.begin(), res.end());
  for (const auto & s : res) {
    cout << s << ' ';
  }
  cout << endl;
  return 0;
}