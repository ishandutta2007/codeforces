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

const int MAXL = 1010;
const int MAXL2 = MAXL * MAXL;
char s[MAXL + 1];
char t[MAXL + 1];

int c1[MAXL2], c2[MAXL2];

inline int go(char a, char b) {
  if (a == b) return 0;

  const char *ws = "RSP";
  int p1 = strchr(ws, a) - ws;
  int p2 = strchr(ws, b) - ws;
  if ((p1 + 1) % 3 == p2) return 1;
  else return -1;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  ll n;
  while (scanf("%I64d%s%s", &n, s, t) >= 1) {
    int l1 = strlen(s), l2 = strlen(t);
    int l = l1 * l2;

    memset(c1, 0, sizeof c1);
    memset(c2, 0, sizeof c2);

    int p1 = 0, p2 = 0;
    int sc1 = 0, sc2 = 0;
    for (int i = 0; i < l; i++)  {
      int c = go(s[p1], t[p2]);
      if (c == -1) c1[i] = 1;
      else if (c == 1) c2[i] = 1;

      sc1 += c1[i];
      sc2 += c2[i];

      if (++p1 >= l1) p1 = 0;
      if (++p2 >= l2) p2 = 0;
    }

    ll ac1 = (n / l) * sc1;
    ll ac2 = (n / l) * sc2;
    n %= l;
    for (int i = 0; i < n; i++) {
      ac1 += c1[i];
      ac2 += c2[i];
     }
     printf("%I64d %I64d\n", ac1, ac2);
  }
  return 0;
}