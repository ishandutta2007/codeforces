#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

#ifdef ONLINE_JUDGE
# define LLD "%I64d"
#else
# define LLD "%ll" "d"
#endif

typedef long long llint;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

int main(void)
{
  set<int> used;

  int n, k; scanf("%d %d", &n, &k);
  int mini = n/2;

  if (n == 1) {
    if (k == 0) { printf("1\n"); return 0; }
    puts("-1"); return 0;
  }

  if (mini > k) {
    puts("-1");
    return 0;
  }

  int A, B;
  if (n >= 2) {
    int use_k = k - (mini-1);
    A = use_k;
    B = 2*use_k;
    used.insert(A);
    used.insert(B);
  }

  static int tt = 1;
  auto get_rp = [&used]() {
    do {
      if (used.count(tt) == 0 && used.count(tt+1) == 0) {
        used.insert(tt);
        used.insert(tt+1);
        return make_pair(tt, tt+1);
      }
      ++tt;
    } while(true);
  };

  int left = n;
  vector<int> V;
  while (left > 3) {
    pair<int, int> p = get_rp();
    V.push_back(p.first);
    V.push_back(p.second);
    k -= gcd(p.first, p.second);
    left -= 2;
  }

  if (n >= 2) {
    V.push_back(A);
    V.push_back(B);
    k -= gcd(A, B);
    left -= 2;
  }
  
  if (left == 1) { 
    pair<int, int> p = get_rp();
    V.push_back(p.first);
    -- left;
  }
  
  assert(left == 0);
  assert(k == 0);
  assert((int)V.size() == n);
  REP(i, n) printf("%d%c", V[i], i+1 == n ? '\n' : ' ');

  return 0;
}