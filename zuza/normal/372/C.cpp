#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

const llint inf = 1e14;

struct MaxQueue {
  deque<llint> Q;
  deque<llint> falling;

  void push(llint x) {
    Q.push_back(x);
    while (!falling.empty() && falling.back() < x)
      falling.pop_back();
    falling.push_back(x);
  }

  void pop() {
    llint front = Q.front();
    Q.pop_front();
    if (front == falling.front())
      falling.pop_front();
  }

  void clear() { falling.clear(); Q.clear(); }
  llint get_max() { return falling.empty() ? -inf : falling.front(); }
};

int main(void)
{
  cin.sync_with_stdio(false);

  int n_len, n_works;
  llint d; cin >> n_len >> n_works >> d; 

  const int MAXLEN = 15e4 + 123;
  static llint dp[2][MAXLEN];
  memset(dp[0], 0, sizeof dp[0]);

  int last_t = 1;
  REP(iter, n_works) {
    llint bonus, sred, t; cin >> sred >> bonus >> t; --sred;
    int delta = t - last_t;

    REP(i, n_len) dp[1][i] = -inf;

    int ul = 0, ur = 0;
    static MaxQueue Q; Q.clear();

    REP(i, n_len) {
      int l = max<llint>(0, i - delta*d);
      int r = min<llint>(n_len, i + delta*d + 1);
      while (ur < r) { Q.push(dp[0][ur]); ++ur; }
      while (ul < l) { Q.pop(); ++ul; }
      dp[1][i] = Q.get_max() + bonus - llabs(sred - i);
    }

    REP(i, n_len) dp[0][i] = dp[1][i];
    last_t = t;
  }

  llint maks = -inf; REP(i, n_len) maks = max(maks, dp[0][i]);
  cout << maks << endl;

  return 0;
}