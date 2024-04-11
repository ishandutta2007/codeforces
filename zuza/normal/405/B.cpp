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

int main(void)
{
  int n; scanf("%d", &n);
  const int MAXLEN = 5e3 + 123;
  static char buff[MAXLEN]; scanf("%s", buff);

  static int left_idx[MAXLEN];
  static int right_idx[MAXLEN];

  int idx = -1;
  REP(i, n) {
    if (buff[i] == '.') left_idx[i] = idx;
    else idx = i;
  }
  idx = -1;
  for (int i = n-1; i >= 0; --i) {
    if (buff[i] == '.') right_idx[i] = idx;
    else idx = i;
  }

  int cnt = 0;
  REP(i, n) {
    if (buff[i] != '.') continue;
    int r = right_idx[i];
    int l = left_idx[i];
    if (r == -1 && l == -1) ++cnt;
    else if (l == -1) { 
      cnt += (buff[r] == 'R');
    } else if (r == -1) {
      cnt += (buff[l] == 'L');
    } else {
      if (buff[l] == 'L') ++cnt;
      else {
        cnt += ((i-l) == (r-i));
      }
    }
  }

  printf("%d\n", cnt);
  return 0;
}