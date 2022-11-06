#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " << 

typedef long long llint;

int main(void) {
  const int MAXLEN = 1e5 + 123;
  static char S[MAXLEN]; scanf("%s", S); int len = strlen(S);

  static int pi[MAXLEN]; pi[0] = -1;
  int j = -1;
  REP(i, len) {
    while (j != -1 && S[i] != S[j]) j = pi[j];
    pi[i+1] = ++j;
  }

  static int w[MAXLEN]; memset(w, 0, sizeof w);
  REP(i, len+1) w[i] = 1;
  for (int i = len; i > 0; --i) {
    w[ pi[i] ] += w[i];
  }

  vector<pair<int, int> > recon;
  int ptr = len;
  while (ptr > 0) {
    recon.push_back({ptr, w[ptr]});
    ptr = pi[ptr];
  }

  reverse(recon.begin(), recon.end());
  int sz = recon.size(); printf("%d\n", sz);
  REP(i, sz) printf("%d %d\n", recon[i].first, recon[i].second);
  return 0;
}