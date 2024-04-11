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

const int P = 27;
const int n2 = P * P * P * P;

string getStr(int id) {
  string res = "";
  for (; id; id /= P)
    res = string(1, 'a' + id % P - 1) + res;
  return res;
}
void addes(char *s, vi &es, int cur, int rem) {
  if (!rem) { assert(0 <= cur && cur < n2); es.pb(cur); return; }
  if (!s[0]) return;

  addes(s + 1, es, cur * P + s[0] - 'a' + 1, rem - 1);
  addes(s + 1, es, cur, rem);
}

vvi es;
vi p1, p2;
vb was;

bool dfs(int v) {
  if (was[v]) return false;

  was[v] = true;
  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i];
    if (p2[b] < 0) {
      p2[b] = v;
      p1[v] = b;
      return true;
    } else if (dfs(p2[b])) {
      p2[b] = v;
      p1[v] = b;
      return true;
    }
  }
  return false;
}

char s[11];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    es = vvi(n);
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      addes(s, es[i], 0, 1);
      addes(s, es[i], 0, 2);
      addes(s, es[i], 0, 3);
      addes(s, es[i], 0, 4);
    }

    p1 = vi(n, -1);
    p2 = vi(n2, -1);
    int res = 0;
    for (;;) {
      bool cont = false;
      was = vb(n, false);
      for (int i = 0; i < n; i++)
        if (p1[i] < 0 && dfs(i)) {
          cont = true;
          res++;
        }
      if (!cont) break;
    }

    if (res < n) {
      printf("-1\n");
    } else {
      for (int i = 0; i < n; i++) {
        assert(p1[i] >= 0);
        printf("%s\n", getStr(p1[i]).c_str());
      }
    }
  }
  return 0;
}