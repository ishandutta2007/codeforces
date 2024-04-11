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

int Swin(int A, int B, int k) {
  if (k == 0) return B%2 == 1;

  if (k%2 == 0) {
    if (A+B > k && A<=k/2) {
      if ((A+B)%2 == 1) {
        return true;
      }
    }
  } else { // k%2 == 1
    if (A <= k/2) {
      if (A+B > k && (A+B)%2 == 0)
        return true;
    } else { // svi
      if (B >= k/2+1) return true;
    }
  }
  return false;
}

int main(void) {
  int n, k; scanf("%d %d", &n, &k);
  int A = 0, B = 0;
  REP(i, n) {
    int x; scanf("%d", &x);
    if (x%2) ++B;
    else ++A;
  }

  puts(Swin(A, B, n-k) ? "Stannis" : "Daenerys");
  return 0;
}