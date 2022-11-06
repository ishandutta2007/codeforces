#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

int main(void)
{
  int n; scanf("%d", &n);

  const int MAXN = 1e5 + 123;
  static int A[MAXN];

  REP(i, n) scanf("%d", A+i);

  if (n == 1) {
    puts("-1");
    return 0;
  }

  sort(A, A+n);
  map<int, int> gap_cnt;
  REP(i, n-1) gap_cnt[A[i+1] - A[i]]++;

  vector<int> output;

  REP(i, n-1) {
    int gap = A[i+1] - A[i];
    if (gap%2 == 0) {
      if ((--gap_cnt[gap]) == 0) gap_cnt.erase(gap);

      if (gap_cnt.size() == 0 || (gap_cnt.size() == 1 && gap_cnt.begin()->first == gap/2))
        output.push_back(A[i] + gap/2);

      ++gap_cnt[gap];    
    }

  }

  if (gap_cnt.size() == 1) {
    int gap = gap_cnt.begin()->first;
    output.push_back(A[0] - gap);
    output.push_back(A[n-1] + gap);
  }

  sort(output.begin(), output.end());
  output.resize(unique(output.begin(), output.end()) - output.begin());
  int sz = output.size();
  printf("%d\n", sz);
  REP(i, sz) printf("%d%c", output[i], i+1 == sz ? '\n' : ' ');

  return 0;
}