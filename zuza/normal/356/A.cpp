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

inline int myrand() { return ((rand()&((1<<15)-1)) << 15) ^ (rand()&((1<<15)-1)); }
typedef long long llint;

const int MAXN = 3e5 + 123;

int A[1048576];
int offset = 524288;
int L, R, X;

void down(int x, int l, int r) {
  if (R <= l || r <= L) return;
  if (L <= l && r <= R) {
    A[x] = X;
    return;
  }

  if (A[x] != -2) { // prop
    A[2*x] = A[x];
    A[2*x+1] = A[x];
  }

  down(2*x, l, (l+r)/2);
  down(2*x+1, (l+r)/2, r);

  if (A[2*x] == A[2*x+1]) { // update
    A[x] = A[2*x];
  } else {
    A[x] = -2;
  }
}

void upd(int a, int b, int x) {
  L = a; R = b; X = x;
  down(1, 0, offset);
}

int query(int X) {
  int x = 1;
  int l = 0, r = offset;
  while (true) {
    if (A[x] != -2) return A[x];
    int mid = (l+r) / 2;
    if (mid <= X) { x = 2*x+1; l = mid; }
    else { x = 2*x; r = mid; }
  }
  return -1;
}

int main(void)
{
  int n, m; scanf("%d %d", &n, &m);

  memset(A, -1, sizeof A);
  static int aa[MAXN], bb[MAXN], xx[MAXN];
  
  REP(i, m) {
    int a, b, x; scanf("%d %d %d", &a, &b, &x); --a, --b, --x;
    aa[i] = a;
    bb[i] = b;
    xx[i] = x;
  }

  for (int i = m-1; i >= 0; --i) {
    int a = aa[i];
    int b = bb[i] + 1;
    int x = xx[i];
    upd(a, x, x);
    upd(x+1, b, x);
  }    

  REP(i, n) printf("%d%c", query(i)+1, i+1 == n ? '\n' : ' ');

  return 0;
}