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

string trim(string s) {
  while (sz(s) && strchr(" \t\n\r", s[0])) s = string(s, 1);
  while (sz(s) && strchr(" \t\n\r", s[sz(s) - 1])) s = string(s, 0, sz(s) - 1);
  return s;
}

char buf[1024];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    fgets(buf, sizeof buf, stdin);

    string ctype = ""; int cid = -1;
    vector<int> stk;
    string ans = "Unhandled Exception";

    for (int i = 0; i < n; i++) {
      fgets(buf, sizeof buf, stdin);
      string s = trim(buf);
      if (!sz(s)) continue;
//      eprintf("s=|%s|\n", s.c_str());

      if (s[1] == 'r') { // try
//        eprintf("try\n");
        stk.pb(i);
      } else if (s[1] == 'h') { // throw
        s = string(s, s.find("(") + 1);
        s = string(s, 0, sz(s) - 1);
        s = trim(s);
        ctype = s; cid = i;
//        eprintf("throw |%s|\n", s.c_str());
      } else if (s[1] == 'a') { // catch
        s = string(s, s.find("(") + 1);
        s = string(s, 0, sz(s) - 1);
        string a = trim(string(s, 0, s.find(",")));
        string b = trim(string(s, s.find(",") + 1));
        b = string(b, 1, sz(b) - 2);
//        eprintf("catch |%s|%s|\n", a.c_str(), b.c_str());

        assert(sz(stk) > 0);
        if (stk.back() <= cid && ctype == a) {
          ans = b;
          cid = -1;
        }
        stk.pop_back();
      } else
        assert(false);
    }
    printf("%s\n", ans.c_str());
  }
  return 0;
}