#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

const int MAXN = (1 << 20) + 123;
const int MAXVAL = MAXN + 123;

llint invs[21][2];

struct Loga {
  int n;
  vector<int> A;

  Loga(int _n) : n(_n), A(_n + 1) {}

  void update(int x, int v) {
    for (++x; x <= n; x += x&-x)
      A[x] += v;
  }

  int query(int x) { // pazi, [0, x>
    int suma = 0;
    for (; x; x -= x&-x)
      suma += A[x];
    return suma;
  }

  int query(int a, int b) {
    return query(b) - query(a);
  }
} loga(MAXVAL);

int main(void)
{
  memset(invs, 0, sizeof invs);

  int pot; scanf("%d", &pot);
  int n = 1 << pot;

  static int A[MAXN];
  static vector<int> rez;

  REP(i, n) {
    scanf("%d", A+i);
    rez.push_back(A[i]);
  }
  sort(rez.begin(), rez.end());
  rez.resize(unique(rez.begin(), rez.end()) - rez.begin());
  REP(i, n) {
    A[i] = lower_bound(rez.begin(), rez.end(), A[i]) - rez.begin();
  }

  //  REP(i, n) printf("%d%c", A[i], i+1 == n ? '\n' : ' ');

  for (int p = 1; p <= pot; ++p) {
    for (int s = 0, sk = (1<<p); s < n; s += sk) {
      llint a = 0, b = 0;

      for (int i = s; i < s+sk; ++i) {
        b += loga.query(A[i]);
        a += loga.query(A[i]+1, MAXVAL);
        loga.update(A[i], +1);
      }

      for (int i = s; i < s+sk; ++i)
        loga.update(A[i], -1);

      invs[p][0] += a;
      invs[p][1] += b;
    }
  }

  llint ans = invs[pot][0];

  int n_q; scanf("%d", &n_q);
  REP(i_q, n_q) {
    int q; scanf("%d", &q);
    ans -= invs[q][0];
    ans += invs[q][1];
    for (int i = q+1; i <= pot; ++i) {
      invs[i][0] -= invs[q][0];
      invs[i][0] += invs[q][1];

      invs[i][1] += invs[q][0];
      invs[i][1] -= invs[q][1];
    }
    for (int i = 0; i <= q; ++i) swap(invs[i][0], invs[i][1]);
    printf(LLD "\n", ans);
  }

  return 0;
}