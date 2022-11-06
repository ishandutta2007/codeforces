/** Superlogaritamska 2D - tested (brute) **/

#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

#define REP(i, n) FOR(i, 0, n)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

struct Loga2d {
  int R, S;
  vector<vector<llint> > data;
  Loga2d(int R, int S) : R(R), S(S) {
    data.clear(); data.resize(R+1);
    REP(i, R+1) data[i].resize(S+1, 0);
  }

  void update(int sx, int sy, llint delta) {
    for (int x = sx+1; x <= R; x += x&-x)
      for (int y = sy+1; y <= S; y += y&-y)
        data[x][y] ^= delta;
  }

  llint query(int sx, int sy) { // pravokutnik [0, x>, [0, y>
    llint suma = 0;
    for (int x = sx; x; x -= x&-x)
      for (int y = sy; y; y -= y&-y)
        suma ^= data[x][y];
    return suma;
  }
};

llint xor_mult(llint a, llint kol) {
  if (kol%2 == 0) return 0;
  return a;
}

struct SuperLoga2d {
  int R, S;
  Loga2d XY, X, Y, add;
  SuperLoga2d(int R, int S) : R(R), S(S), XY(R, S), X(R, S), Y(R, S), add(R, S) {}

  void update(int x1, int x2, int y1, int y2, llint v) {
    XY.update(x1, y1, v);
    X.update(x1, y1, xor_mult(v, y1));
    Y.update(x1, y1, xor_mult(v, x1));
    add.update(x1, y1, xor_mult(v, x1*y1));

    XY.update(x1, y2, v);
    X.update(x1, y2, xor_mult(v, y2));
    Y.update(x1, y2, xor_mult(v, x1));
    add.update(x1, y2, xor_mult(v, x1*y2));

    XY.update(x2, y1, v);
    X.update(x2, y1, xor_mult(v, y1));
    Y.update(x2, y1, xor_mult(v, x2));
    add.update(x2, y1, xor_mult(v, x2*y1));

    XY.update(x2, y2, v);
    X.update(x2, y2, xor_mult(v, y2));
    Y.update(x2, y2, xor_mult(v, x2));
    add.update(x2, y2, xor_mult(v, x2*y2));
  }

  llint query(int x, int y) {
    return
      xor_mult(XY.query(x, y), x*y) ^
      xor_mult(X.query(x, y), x) ^ 
      xor_mult(Y.query(x, y), y) ^
      add.query(x, y);
  }
  llint query(int x1, int x2, int y1, int y2) {
    return query(x2, y2) ^ query(x2, y1) ^ query(x1, y2) ^ query(x1, y1);
  }
};

int main(void)
{
  int nn, nq; scanf("%d %d", &nn, &nq);
  static SuperLoga2d super(nn, nn);
  
  REP(iq, nq) {
    int type, x1, y1, x2, y2; scanf("%d %d %d %d %d", &type, &x1, &y1, &x2, &y2); --x1, --y1;
    if (type == 1) { // query
      llint ans = super.query(x1, x2, y1, y2);
      printf(LLD "\n", ans);
    } else { // update
      llint v; scanf(LLD, &v);
      super.update(x1, x2, y1, y2, v);
    }
  }

  return 0;
}