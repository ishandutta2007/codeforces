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

const llint inf = 1e16;

struct Data {
  llint P, M, maks;
  Data(llint P = -inf, llint M = -inf, llint maks = -inf) : 
    P(P), M(M), maks(maks) {}
  friend Data merge(const Data& a, const Data& b) {
    return Data(max(a.P, b.P), 
                max(a.M, b.M), 
                max(max(a.maks, b.maks), a.M + b.P));
  }
};

struct Tour {
  int offset;
  vector<Data> data;
  
  Tour(int n) {
    offset = 1; while (offset < n) offset *= 2;
    data.resize(2*offset);
  }

  void update(int idx, Data val) {
    int ptr = idx+offset;
    data[ptr] = val;
    for (ptr /= 2; ptr > 0; ptr /= 2)
      data[ptr] = merge(data[2*ptr], data[2*ptr+1]);
  }

  Data query(int ptr, int clo, int chi, int tlo, int thi) {
    if (tlo <= clo && chi <= thi) return data[ptr];
    if (thi <= clo || chi <= tlo) return Data();
    return merge(query(2*ptr, clo, (clo+chi)/2, tlo, thi),
                 query(2*ptr+1, (clo+chi)/2, chi, tlo, thi));
  }
};

int main(void) {
  int nt, nq; scanf("%d %d", &nt, &nq);

  const int MAXN = 2e5 + 123;
  static llint H[MAXN];
  static llint D[MAXN];
  static llint prefD[MAXN];

  REP(i, nt) {
    scanf("%lld", D+i);
    D[i+nt] = D[i];
  }
  REP(i, nt) {
    scanf("%lld", H+i);
    H[i+nt] = H[i];
  }

  Tour T(2*nt);
  REP(i, 2*nt+1) prefD[i] = (i == 0) ? 0 : prefD[i-1] + D[i-1];
  REP(i, 2*nt) T.update(i, Data(2*H[i]+prefD[i], 2*H[i]-prefD[i], -inf));

  REP(iq, nq) {
    int lo, hi; scanf("%d %d", &lo, &hi); --lo, --hi;
    if (lo > hi) hi += nt;
    ++hi;
    
    printf("%lld\n", T.query(1, 0, T.offset, hi, lo+nt).maks);
  }

  return 0;
}