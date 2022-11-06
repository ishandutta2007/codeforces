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

int main(void)
{
  int n; scanf("%d", &n);
  vector<int> A(n);
  REP(i, n) {
    scanf("%d", &A[i]);
  }
  int jed = 0;
  llint sum = 0;
  REP(i, n) {
    if (A[i] == 0) sum += jed;
    else ++jed;
  }
  cout << sum << endl;
  return 0;
}