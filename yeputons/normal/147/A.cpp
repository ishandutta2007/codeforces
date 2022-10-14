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

char buf[1024 * 1024];
bool isbad(char c) { return strchr(".,!?", c); }

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  for (;;) {
    memset(buf, 0, sizeof buf);
    fgets(buf, sizeof buf, stdin);
    int l = strlen(buf);
    while (l && strchr("\n\r", buf[l - 1])) buf[--l] = 0;
    if (!l) break;

    vector<string> ws;
    string cur = "";
    for (int i = 0; i <= l; i++)
      if (buf[i] == ' ' || !buf[i] || isbad(buf[i])) {
        if (cur.length())
          ws.pb(cur);
        if (isbad(buf[i]) && buf[i])
          ws.pb(string(1, buf[i]));
        cur = "";
      } else
        cur += buf[i];

    string res = "";
    for (int i = 0; i < sz(ws); i++) {
      if (res.length() && !strchr(".,!?", ws[i][0]))
        res += " ";
      res += ws[i];
    }
    printf("%s\n", res.c_str());
  }
  return 0;
}
//