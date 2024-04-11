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

const int MAXL = 1e6;
char buf[MAXL + 100];
int k;

string getss(const string &a) {
  int rem = k;
  for (int i = a.length() - 1; i >= 0; i--)
    if (strchr("aeiou", a[i])) {
      if (!--rem) return string(a, i, a.length() - i);
    }
  return "FF";
}
bool g(string a, string b) {
  a = getss(a);
  b = getss(b);
  if (a == "FF" || b == "FF") return false;
  return a == b;
}

int get(const vector<string> &s) {
  assert(sz(s) == 4);
  if (g(s[0], s[1]) && g(s[1], s[2]) && g(s[2], s[3])) return -1;
  if (g(s[0], s[1]) && g(s[2], s[3])) return 0;
  if (g(s[0], s[2]) && g(s[1], s[3])) return 1;
  if (g(s[0], s[3]) && g(s[1], s[2])) return 2;
  return -50;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d%d", &n, &k) >= 1) {
    vector<vector<string> > s(n);
    for (int i = 0; i < n; i++)
    for (int i2 = 0; i2 < 4; i2++) {
      scanf("%s", buf);
      s[i].pb(buf);
    }

    int ty = -1;
    try {
      for (int i = 0; i < n; i++) {
        int cty = get(s[i]);
//        eprintf("%d\n", cty);
        if (cty < -1) throw 0;
        if (cty < 0) continue;

        if (ty >= 0 && ty != cty) throw 0;
        ty = cty;
      }

      switch (ty) {
      case -1: printf("aaaa\n"); break;
      case 0: printf("aabb\n"); break;
      case 1: printf("abab\n"); break;
      case 2: printf("abba\n"); break;
      }
    } catch (...) {
      printf("NO\n");
    }
  }
  return 0;
}