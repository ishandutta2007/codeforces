#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 1e2;
const int MAXS = 1.1e2;

void take(double *prob, int startcnt, int &ccnt, double &ans) {
  assert(ccnt > 0);

  ans -= prob[0];
  for (int i = 0; i <= startcnt; i++) {
    double nprob = prob[i] * double(ccnt - i) / ccnt;
    if (i < startcnt)
      nprob += prob[i + 1] * double(i + 1) / ccnt;
    prob[i] = nprob;
  }
  ccnt--;
  ans += prob[0];
}
double prob[MAXN][MAXS + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi scnt(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &scnt[i]);

    memset(prob, 0, sizeof prob);
    double ans = 0;
    for (int i = 0; i < n; i++) {
       prob[i][scnt[i]] = 1;
       if (scnt[i] == 0) ans++;
    }

    vi ccnt = scnt;
    int q;
    scanf("%d", &q);
    while (q --> 0) {
      int a, b, cnt;
      scanf("%d%d%d", &a, &b, &cnt), a--, b--;
      for (int i = 0; i < cnt; i++)
        take(prob[a], scnt[a], ccnt[a], ans);
      ccnt[b] += cnt;
      printf("%.18e\n", ans);
    }
  }
  return 0;
}