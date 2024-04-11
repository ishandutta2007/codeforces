#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define int long long

const int maxm = 1e5;

int n, a, m, cnt_open;
long long d, t[maxm], last_open;

void Solve1(long long x) {
  if (last_open + d < x) {
    ++cnt_open;
    last_open = x;
  }
}

void SolveN(long long begin, int len) {
  int cnt_pass = (last_open + d - begin) / a + 1;
  if (last_open + d < begin) {
    cnt_pass = 0;
  }
  if (cnt_pass >= len) {
    return;
  }
  begin += cnt_pass * a;
  len -= cnt_pass;

  int cnt_once = d / a + 1;
  int repeat = (len - 1) / cnt_once;
  cnt_open += repeat;
  begin += repeat * cnt_once * (long long)a;
  len -= repeat * cnt_once;
  ++cnt_open;
  last_open = begin;
}

signed main(void) {
  scanf("%lld%lld%lld%lld", &n, &m, &a, &d);
  for (int i = 0; i < m; ++i) {
    scanf("%lld", t + i);
  }

  last_open = -2e18;
  long long a_end = a * n, a_cur = a;
  for (int i = 0; i < m; ++i) {
    // a before t
    int cnt = (min(t[i], a_end) - a_cur) / a + 1;
    if (a_cur > t[i]) {
      cnt = 0;
    }
    SolveN(a_cur, cnt);
    a_cur += a * cnt;
    // t
    Solve1(t[i]);
  }
  // a after t
  SolveN(a_cur, (a_end - a_cur) / a + 1);
  
  printf("%lld\n", cnt_open);
  return 0;
}