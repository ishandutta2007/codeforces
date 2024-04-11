#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;

int eprintf(const char *format, ...) {
  #ifdef DEBUG
  va_list args;
  va_start(args, format);
  int ret = vfprintf(stderr, format, args);
  va_end(args);
  return ret;
  #else
  return 0;
  #endif
}

#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;

typedef char* str;

#define BSZ 6000
char bufs[BSZ][1001];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi xs(n);
    vi cnt(1001);
    for (int i = 0; i < n; i++) scanf("%d", &xs[i]), cnt[xs[i]]++;

    try {
      vector<vector<string> > res(1001);
      vector<char*> cur;

      memset(bufs, 0, sizeof bufs);
      cur.pb(bufs[0]);
      int pos = 1;

      for (int l = 1; l < cnt.size(); l++) {
        if (cur.size() >= n) {
          for (int i = 0; i < cur.size(); i++)
            cur[i][l - 1] = '0';
        } else {
          vector<str> ncur;
          for (int i = 0; i < cur.size(); i++) {
            strncpy(bufs[pos], cur[i], sizeof bufs[pos]);
            bufs[pos][l - 1] = '0';
            ncur.pb(bufs[pos++]);

            cur[i][l - 1] = '1';
            ncur.pb(cur[i]);
          }
          ncur.swap(cur);
        } 
        if (cur.size() < cnt[l]) throw 0;
        for (int i = 0; i < cnt[l]; i++) {
          res[l].pb(cur[0]);
          cur.erase(cur.begin());
        }
        eprintf("l=%d, sz=%d\n", l, cur.size());
        assert(pos < BSZ);
      }

      printf("YES\n");
      for (int i = 0; i < n; i++) {
        printf("%s\n", res[xs[i]].begin()->c_str());
        res[xs[i]].erase(res[xs[i]].begin());
      }
    } catch (...) { printf("NO\n"); }
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}