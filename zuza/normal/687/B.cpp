#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  cin.sync_with_stdio(false);

  int n, k; cin >> n >> k;
  vector<pair<int, int> > fs;

  for (int i = 2; k > 1; ++i) {
    if (i*i > k) i = k;
    if (k%i == 0) {
      int f = 1;
      while (k%i == 0) {
        f *= i;
        k /= i;
      }
      fs.push_back({f, 0});
    }
  }

  int cnt = fs.size();
  REP(i, n) {
    int a; cin >> a;
    REP(j, fs.size()) {
      if (fs[j].second == false && a%fs[j].first == 0) {
        fs[j].second = true;
        --cnt;
      }
    }
  }

  puts(cnt == 0 ? "Yes" : "No");
  return 0;
}