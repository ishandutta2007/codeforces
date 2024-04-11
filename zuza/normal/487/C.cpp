#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>

#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

bool is_prime(int x) {
  if (x < 2) return false;
  for (int i = 2; i*i <= x; ++i)
    if (x%i == 0) return false;
  return true;
}

llint power_mod(llint b, llint e, llint mod) {
  llint ans = 1, p2 = b;
  for (; e; e /= 2, p2 = p2*p2 % mod) {
    if (e&1) ans = ans*p2 % mod;
  }
  return ans;
}

int main(void) {
  int n; scanf("%d", &n);

  if (n == 4) {
    printf("YES\n");
    printf("%d\n%d\n%d\n%d\n", 1, 3, 2, 4);
    exit(0);
  }
  if (n == 2) {
    printf("YES\n");
    printf("%d\n%d\n", 1, 2);
    exit(0);
  }
  if (n == 1) {
    printf("YES\n");
    printf("%d\n", 1);
    exit(0);
  }

  if (!is_prime(n)) {
    printf("NO\n");
    exit(0);
  }

  printf("YES\n");
  int g; for (g = 2; g < n; ++g) {
    static set<int> S; S.clear();
    llint p = 1;
    while (true) {
      if (S.insert(p).second == false) break;
      p = p*g % n;
    }

    if ((int)S.size() == n-1) break;
  }

  REP(i, n-1) {
    if (i%2 == 0) {
      printf("%lld\n", power_mod(g, n-1-i, n));
    } else {
      printf("%lld\n", power_mod(g, i, n));
    }
  }

  printf("%d\n", n);
  return 0;
}