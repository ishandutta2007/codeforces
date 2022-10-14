#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int INF = 1e9;
const int maxl = 2e5 + 100;

vi poses[26];
char buf[maxl + 1];
ll calc() {
  int l = strlen(buf);
  ll cur = 0;
  for (int i = 0; buf[i]; i++) {
    const vi &cposes = poses[buf[i] - 'a'];
    int pos = lower_bound(cposes.begin(), cposes.end(), i) - cposes.begin();
    int cd = INF;
    for (int i2 = max(pos - 1, 0); i2 <= pos + 1 && i2 < cposes.size(); i2++)
      cd = min(cd, abs(cposes[i2] - i));
    if (cd >= INF) cd = l;
    cur += cd;
  }
  return cur;
}

char s[maxl + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n, k;
  while (scanf("%d%d%s", &n, &k, s) >= 1) {
    for (int i = 0; i < 26; i++) poses[i].clear();
    for (int i = 0; i < k; i++)
      poses[s[i] - 'a'].pb(i);

    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      printf("%I64d\n", calc());
    }
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}