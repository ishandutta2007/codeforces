#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

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

const int MOD = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

const int MAXL = 110;
char s[MAXL + 1];

const int MAXV = 25;
const int MAXS = MAXL * MAXV;

int d[MAXL + 1][MAXS + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  memset(d, 0, sizeof d);
  d[0][0] = 1;
  for (int l = 0; l < MAXL; l++)
  for (int ps = 0; ps <= MAXS; ps++)
    for (int nv = 0; nv <= MAXV && ps + nv <= MAXS; nv++)
      add(d[l + 1][ps + nv], d[l][ps]);

  int TC;
  assert(scanf("%d", &TC) >= 1);
  while (TC --> 0) {
    scanf("%s", s);
    int l = strlen(s), sum = 0;
    for (int i = 0; i < l; i++)
      sum += s[i] - 'a';
    int res = d[l][sum];
    add(res, MOD - 1);
    printf("%d\n", res);
  }
  return 0;
}