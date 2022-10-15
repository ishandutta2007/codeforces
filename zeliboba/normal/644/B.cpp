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
#include <deque>
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
  int n, b;
  cin >> n >> b;
  vi t(n), d(n);
  vl e(n, -1);
  deque<int> q;
  ll time = 0;
  for (int qq = 0; qq < n; ++qq) {
    scanf("%d%d", &t[qq], &d[qq]);
    q.push_back(qq);
    while (time <= t[qq]) {
      time = max(time, (ll)t[q.front()]) + d[q.front()];
      e[q.front()] = time;
      q.pop_front();
    }
//    cerr << time << ' ' << q.size() << endl;
    if (q.size() > b) q.pop_back();
  }
  while (!q.empty()) {
    time = max(time, (ll)t[q.front()]) + d[q.front()];
    e[q.front()] = time;
    q.pop_front();
  }
  for (int i = 0; i < n; ++i) cout << e[i] << ' ';
  return 0;
}