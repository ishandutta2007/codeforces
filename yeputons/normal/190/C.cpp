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

vi ty;
string res;
int pos;

void go() {
  if (pos >= sz(ty)) throw 0;
  if (ty[pos] == 0) { pos++; res += "int"; return; }
  assert(ty[pos] == 1); pos++;

  res += "pair<";
  go();
  res += ",";
  go();
  res += ">";
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int nen = -1;
  assert(scanf("%d", &nen) >= 1);

  for (;;) {
    int _n = nen;
    if (_n < 0) break;

    res = "";
    ty.clear();
    nen = -1;

    for (int i = 0;; i++) {
      char buf[16];
      if (scanf("%s", buf) < 0) break;

      if (!strcmp(buf, "pair")) ty.pb(1);
      else if (!strcmp(buf, "int")) ty.pb(0);
      else { sscanf(buf, "%d", &nen); break; }
    }

    pos = 0;
    try {
      go();
      if (pos < sz(ty)) throw 0;
      printf("%s\n", res.c_str());
    } catch (...) {
      printf("Error occurred\n");
    }
  }
  return 0;
}