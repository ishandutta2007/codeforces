#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }
int mpow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = mmul(a, a))
    if (b & 1) res = mmul(res, a);
  return res;
}

const int MAXN = 110;
char s[MAXN + 1];

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  while (scanf("%s", s) >= 1) {
    int n = strlen(s);
    reverse(s, s + n);

    int ans = 0, ccnt = 1;
    for (int i = 0; i < n; i++) {
      ans = mmul(ans, 2);
      if (s[i] == '1') {
        int ps = mmul(ccnt, ccnt);
        madd(ans, ps);
      }
      ccnt = mmul(ccnt, 2);
    }
    printf("%d\n", ans);
  }
  return 0;
}