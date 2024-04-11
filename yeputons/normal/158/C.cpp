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

vector<string> parse(string s) {
  vector<string> res;
  string cur = "";
  s += "/";
  for (int i = 0; i < (int)s.length(); i++)
    if (s[i] == '/') {
      if (cur.length() > 0)
        res.pb(cur);
      cur = "";
    } else
      cur += s[i];
  return res;
}

char buf[1024 * 1024];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d ", &n) >= 1) {
    vector<string> cur;
    for (int step = 0; step < n; step++) { 
      scanf("%s", buf);
      if (!strcmp(buf, "pwd")) {
        for (int i = 0; i < sz(cur); i++)
          printf("/%s", cur[i].c_str());
        printf("/");
        printf("\n");
      } else {
        assert(!strcmp(buf, "cd"));
        scanf("%s", buf);
        string cmd = buf;

        if (cmd[0] == '/') {
          cur.clear();
          cmd = string(cmd, 1);
        }

        vector<string> dirs = parse(cmd);
        for (int i = 0; i < sz(dirs); i++) {
          if (dirs[i] == "..") {
            assert(sz(cur) > 0);
            cur.resize(sz(cur) - 1);
          } else {
            cur.pb(dirs[i]);
          }
        }
      }
    }
  }
  return 0;
}