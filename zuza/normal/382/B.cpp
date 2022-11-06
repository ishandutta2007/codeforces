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
  llint a, b, w, x, c; cin >> a >> b >> w >> x >> c;

  auto solve = [=](llint t) -> bool {
    llint c_end = c - t;

    llint b_end = b - t*x;
    llint a_end;
    if (b_end >= 0)
      a_end = a;
    else
      a_end = a - (-b_end + w - 1) / w;
    
    return c_end <= a_end;
  };


  llint lo = 0, hi = 1e15;
  while (lo < hi) {
    llint mid = (lo + hi) / 2;
    if (solve(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  
  cout << lo << endl;
  return 0;
}