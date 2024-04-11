#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

//typedef unsigned long long ll;
typedef long double ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int n;
/*vector<double> getProb(const char *s, char c) {
  vi poses;
  ll csum = 0;
  for (int i = 0; i < n; i++) if (s[i] == c) {
    poses.pb(i);
    csum += n - i;
  }
  ll scnt = n * ll(n + 1) / 2;

  eprintf("%I64d %I64d\n", csum, scnt);
  vector<double> res(n, 0);
  int ptr = 0;
  for (int i = 0; i < n; i++) {
    while (ptr < sz(poses) && poses[ptr] < i) {
      csum -= n - poses[ptr];
      ptr++;
    }
    eprintf("%I64d / %I64d\n", csum, scnt);
    res[i] = (double)csum / scnt;
  }
  return res;
}*/

const int MAXL = 2e5 + 1e3;
char a[MAXL + 1];
char b[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d%s%s", &n, a, b) >= 1) {
    n = strlen(a);
    assert(n == strlen(b));

    ll ans = 0;
    for (int c = 0; c < 26; c++) {
      vi p1, p2;
      for (int i = 0; i < n; i++) {
        if (a[i] == 'A' + c) p1.pb(i);
        if (b[i] == 'A' + c) p2.pb(i);
      }

      int ptr = 0;
      ll suml = 0, sumr = 0;
      for (int i = 0; i < sz(p2); i++)
        sumr += n - p2[i];
      
      ll cans = 0;
      for (int i = 0; i < sz(p1); i++) {
        int pos = p1[i];
        while (ptr < sz(p2) && p2[ptr] < pos) {
          suml += p2[ptr] + 1;
          sumr -= n - p2[ptr];
          ptr++;
        }
        cans += suml * ll(n - p1[i]);
        cans += ll(p1[i] + 1) * sumr;
      }
      ans += cans;
    }

    ll scnt = 0;
    for (int i = 0; i < n; i++) {
      scnt += ll(n - i) * ll(n - i);
    }
    printf("%.18e\n", (double)(double(ans) / scnt));
  }
  return 0;
}