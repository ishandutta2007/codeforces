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

const int MAXN = 2e5 + 123;

int n_a, n_b;
int p;
int A[MAXN];
int B[MAXN];

struct Multi {
  llint a, b, c;

  void clear() {
    a = b = c = 0;
  }

  void insert(llint x) {
    a += x;
    b += x*x;
    c += x*x*x;
  }

  void erase(llint x) {
    a -= x;
    b -= x*x;
    c -= x*x*x;
  }

  friend bool isEqual(Multi& A, Multi& B) {
    if (A.a != B.a) return false;
    if (A.b != B.b) return false;
    if (A.c != B.c) return false;
    return true;
  }
};

int main(void)
{
  scanf("%d %d", &n_a, &n_b);
  scanf("%d", &p);

  static Multi b_S; b_S.clear();
  REP(i, n_a) scanf("%d", A+i);
  REP(i, n_b) scanf("%d", B+i);
  REP(i, n_b) b_S.insert(B[i]);

  vector<int> output;

  for (int start = 0; start < p; ++start) {
    static Multi S; S.clear();
    for (int i = start; i < n_a; i += p) {
      S.insert(A[i]);
      if (i-llint(p)*n_b >= 0) S.erase(A[i-p*n_b]);
      if (isEqual(b_S, S)) output.push_back(i-p*(n_b-1));
    }
  }

  sort(output.begin(), output.end());
  int sz = output.size();
  printf("%d\n", sz);
  REP(i, sz) printf("%d%c", output[i]+1, i+1 == sz ? '\n' : ' ');

  return 0;
}