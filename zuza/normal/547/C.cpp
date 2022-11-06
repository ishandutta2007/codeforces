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

const int MAXN = 5e5 + 1000;

template<typename T>
ostream& operator << (ostream& os, vector<T> v) {
  os << "{";
  bool first = true;
  for (auto val : v) {
    if (first) first = false; else os << ", ";
    os << val;
  }
  return os << "}";
}

int main(void) {
  static int popcnt[1<<12]; popcnt[0] = 0;
  FOR(i, 1, 1<<12) popcnt[i] = popcnt[i>>1] + (i&1);

  static int pd[MAXN] = {1}; // !?
  for (int i = 2; i*i < MAXN; ++i)
    if (pd[i] == 0)
      for (int j = i*i; j < MAXN; j += i)
        pd[j] = i;

  REP(i, MAXN) if (pd[i] == 0) pd[i] = i;

  int n, q; scanf("%d %d", &n, &q);
  static int A[MAXN];
  static bool pun[MAXN];

  REP(i, n) {
    scanf("%d", A+i);
    pun[i] = false;
  }

  static llint bins[MAXN] = {0};

  llint ans = 0;

  REP(iq, q) {
    int idx; scanf("%d", &idx); --idx;

    vector<int> ps;
    for (int tmp = A[idx]; tmp > 1; ) {
      int p = pd[tmp];
      while (tmp%p == 0) {
        tmp /= p;
      }
      ps.push_back(p);
    }

    int sz = ps.size();
    REP(state, 1<<sz) {
      int sign = (popcnt[state]%2 == 0) ? +1 : -1;
      int d = 1;
      REP(i, sz) if ((state>>i)&1) d *= ps[i]; 

      ans -= sign * bins[d] * (bins[d]-1) / 2;
      if (pun[idx]) --bins[d];
      else ++bins[d];
      ans += sign * bins[d] * (bins[d]-1) / 2;
    }

    pun[idx] ^= 1;
    printf("%lld\n", ans);
  }

  return 0;
}