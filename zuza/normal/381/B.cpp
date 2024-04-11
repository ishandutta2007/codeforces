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
  vector<int> V(n);
  REP(i, n) scanf("%d", &V[i]);
  sort(V.begin(), V.end());
  
  vector<int> A, B;
  for (int i = 0; i < n; ) {
    int cnt = 0;
    int curr = V[i];
    for (; i < n && curr == V[i]; ++i) {
      ++cnt;
    }

    --cnt;
    A.push_back(curr);

    if (i != n && cnt > 0) {
      --cnt;
      B.push_back(curr);
    }
  }

  reverse(B.begin(), B.end());
  REP(i, (int)B.size()) A.push_back(B[i]);
  
  int sz = A.size();
  printf("%d\n", sz);
  REP(i, sz) printf("%d%c", A[i], i+1 == sz ? '\n' : ' ');

  return 0;
}