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

namespace suf {
  const int MAXLOG = 19; // 1<<MAXLOG mora bit >= len+1, moze bit i vece 
  const int MAXLEN = 4e5 + 123; // >= len+1
 
  struct SS {
    pair<int, int> p;
    int idx;
    friend bool operator < (const SS& a, const SS& b) { return a.p < b.p; };
  };

  SS suf[MAXLEN];
  int pos_suf[MAXLEN];

  int L = -1, len;
  int bucket[MAXLOG][MAXLEN];
  int A[MAXLEN]; // copy of the string

  void init(const char* Aorig, int new_len) { // or const int* Aorig
    assert((1<<MAXLOG) >= MAXLEN+1);    
    len = new_len;
    REP(i, len) A[i] = Aorig[i];

    REP(i, len) suf[i] = {make_pair(A[i], 0), i};
    REP(i, len) bucket[0][i] = A[i];
    sort(suf, suf+len);

    for (L = 1; ; ++L) {
      REP(i, len) {
        int pos = i+(1<<(L-1));
        suf[i] = {{bucket[L-1][i], pos<len ? bucket[L-1][pos] : (int)-1e9}, i};
      }
      sort(suf, suf+len);

      int cnt = 0;
      REP(i, len) {
        if (i == 0 || suf[i-1] < suf[i]) ++cnt;
        bucket[L][suf[i].idx] = cnt-1;
      }
      if (cnt == len) { ++L; break; }
    }

    REP(i, len) pos_suf[suf[i].idx] = i;
  }
 
  // first SA position in [slo, shi> where l-th char is >= c
  int lower_bound(int slo, int shi, int c, int l) {
    while (slo < shi) {
      int mid = (slo + shi) / 2;
      if (A[suf[mid].idx+l] >= c)
        shi = mid;
      else
        slo = mid + 1;
    }
    return slo;
  }
}

struct Fenwick {
  int n;
  vector<int> data;
  Fenwick(int n) : n(n) {
    data.assign(n+1, 0);
  }

  void update(int x, int y) {
    for (++x; x <= n; x += x&-x)
      data[x] += y;
  }

  int query(int x) {
    int ans = 0;
    for (; x; x -= x&-x)
      ans += data[x];
    return ans;
  }
};

int main(void) {
  const int MAXLEN = 5e5 + 123;
  static char S[MAXLEN]; int len = 0;

  static int pos_w[MAXLEN];

  static int wlo[MAXLEN];
  static int whi[MAXLEN];
  static int salo[MAXLEN];
  static int sahi[MAXLEN];

  int n, q; scanf("%d %d", &n, &q);
  REP(i, n) {
    static char buff[MAXLEN];
    scanf("%s", buff); int bl = strlen(buff);

    wlo[i] = len;
    REP(j, bl) {
      pos_w[len] = i;
      S[len++] = buff[j];
    }
    whi[i] = len;
    S[len++] = '#';
  }

  enum { QS, INS };
  struct E {
    int type, x, y;
    int qidx; char sign;
  };
  vector<E> es;

  suf::init(S, len);
  REP(i, len) {
    int x = i;
    int y = pos_w[suf::suf[i].idx];
    es.push_back({INS, x, y, -1, 0});
  }

  REP(i, n) {
    int lo = 0, hi = len;
    FOR(j, wlo[i], whi[i]) {
      lo = suf::lower_bound(lo, hi, S[j], j-wlo[i]);
      hi = suf::lower_bound(lo, hi, S[j]+1, j-wlo[i]);
    }
    salo[i] = lo;
    sahi[i] = hi;
  }

  static int qans[MAXLEN]; memset(qans, 0, sizeof qans);
  REP(iq, q) {
    int lo, hi, k; scanf("%d %d %d", &lo, &hi, &k); --lo; --k;
    int x1 = salo[k], x2 = sahi[k];
    int y1 = lo, y2 = hi;

    // [x1, x2> [y1, y2>
    es.push_back({QS, x2, y2, iq, +1});
    es.push_back({QS, x2, y1, iq, -1});
    es.push_back({QS, x1, y2, iq, -1});
    es.push_back({QS, x1, y1, iq, +1});
  }
  sort(es.begin(), es.end(), [](const E& a, const E& b) {
      if (a.x != b.x) return a.x < b.x;
      return a.type < b.type;
    });

  Fenwick ds(n);
  for (const auto& e : es) {
    if (e.type == INS) {
      ds.update(e.y, +1);
    } else if (e.type == QS) {
      int val = ds.query(e.y);
      qans[e.qidx] += e.sign * val;
    }
  }

  REP(iq, q) printf("%d\n", qans[iq]);
  return 0;
}