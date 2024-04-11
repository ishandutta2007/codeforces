#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

char buf[100];
char buf2[100];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n;
  while (scanf("%d", &n) >= 1) {
    vector<vector<string> > ns(4);
    for (int i = 0; i < n; i++) {
      scanf("%s%s", buf, buf2);
      if (!strcmp(buf2, "rat")) ns[0].pb(buf);
      if (!strcmp(buf2, "woman") || !strcmp(buf2, "child")) ns[1].pb(buf);
      if (!strcmp(buf2, "man")) ns[2].pb(buf);
      if (!strcmp(buf2, "captain")) ns[3].pb(buf);
    }
    for (int p = 0; p < 4; p++)
      for (int i = 0; i < ns[p].size(); i++)
        printf("%s\n", ns[p][i].c_str());
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}