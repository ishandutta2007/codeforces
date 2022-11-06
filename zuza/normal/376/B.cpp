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
  const int MAXN = 123;
  int n, e; scanf("%d %d", &n, &e);
  static int phi[MAXN] = {0};
  REP(i, e) { 
    int a, b, c; scanf("%d %d %d", &a, &b, &c); --a, --b;
    phi[a] -= c;
    phi[b] += c;
  }
  int sum = 0;
  REP(i, n) sum += max(0, phi[i]);
  printf("%d\n", sum);
  return 0;
}