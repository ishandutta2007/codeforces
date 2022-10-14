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

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

struct Proc {
  string name;
  vector<string> args;

  bool matchesTo(const Proc &p) {
    if (name != p.name) return false;
    if (sz(args) != sz(p.args)) return false;

    for (int i = 0; i < sz(args); i++) {
      if (p.args[i] == "T") continue;
      if (args[i] != p.args[i]) return false;
    }
    return true;
  }
};


Proc readProc(bool readVoid) {
  Proc p;

  char buf[21];
  if (readVoid) scanf(" void");
  assert(scanf(" %[a-z0-9] (", buf) == 1);
  p.name = buf;
  while (scanf(" %[Ta-z0-9]", buf) == 1) {
    p.args.pb(buf);
    scanf(" ,");
  }
  scanf(" )");
  return p;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<Proc> ps(n);

    for (int i = 0; i < n; i++)
      ps[i] = readProc(true);

    map<string, string> types;
    int m;
    scanf(" %d", &m);
    while (m --> 0) {
      char type[21], name[21];
      scanf(" %s %s", type, name);
      types[name] = type;
    }

    scanf(" %d", &m);
    while (m --> 0) {
      Proc p = readProc(false);
      for (int i = 0; i < sz(p.args); i++)
        p.args[i] = types[p.args[i]];

      int cnt = 0;
      for (int i = 0; i < n; i++) if (p.matchesTo(ps[i]))
        cnt++;
      printf("%d\n", cnt);
    }
  }
  return 0;
}