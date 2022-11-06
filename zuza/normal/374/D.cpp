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

typedef long long llint;

const int MAXE = 1e6 + 123;
const int MAXA = 1e6 + 123;

int A[MAXA];
int inp[MAXE];

struct Tour {
  vector<int> data;
  int offset, n;

  Tour(int n) : n(n) {
    offset = 2; for (; offset < n; offset *= 2);
    data.resize(2*offset, 0);
  }
  void insert(int x, int kol) {
    for (x += offset; x; x /= 2) data[x] += kol; 
  }
  int query(int rank) {
    int ptr = 1;
    while (ptr < offset) {
      if (rank - data[2*ptr] < 0) ptr = ptr*2;
      else { rank -= data[2*ptr]; ptr = ptr*2 + 1; }
    }
    assert(rank == 0);
    return ptr - offset;
  }
} T(1e6 + 1);

int main(void)
{
  int n_e, n_a; scanf("%d %d", &n_e, &n_a);
  REP(i, n_a) { scanf("%d", A+i); --A[i]; }

  int total = 0;
  int sz = 0;
  REP(i, n_e) {
    int type; scanf("%d", &type);
    if (type != -1) { 
      inp[total] = type; ++sz; 
      T.insert(total, 1);
      ++total;
    } else {
      int makni = lower_bound(A, A+n_a, sz) - A;

      for (int j = makni - 1; j >= 0; --j) {
        int pos = T.query(A[j]);
        T.insert(pos, -1);
        --sz;
      }
    }
  }

  if (sz > 0) {
    REP(i, total) if (T.data[i+T.offset] == 1) printf("%d", inp[i]); putchar('\n');
  } else {
    puts("Poor stack!");
  }
  return 0;
}