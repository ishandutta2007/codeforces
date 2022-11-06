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
  int R = 0;

  typedef pair<int, int> PII;
  vector<int> recon(n);
  vector<PII> V;

  REP(i, n) {
    int x; scanf("%d", &x);
    V.push_back(PII(x, i));
  }
  sort(V.begin(), V.end());

  REP(i, n) {
    int val = max(V[i].first, R);
    recon[V[i].second] = val;
    R = val + 1;
  }

  REP(i, n) printf("%d%c", recon[i], i+1 == n ? '\n' : ' ');
  return 0;
}