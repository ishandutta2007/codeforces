#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

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

#define mp make_pair
#define pb push_back

typedef long long ll;
typedef vector<ll> vll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;

char buf[100];

char* name[] = { "S", "M", "L", "XL", "XXL" };

int main() {
  vi n(5);
  while (scanf("%d%d%d%d%d", &n[0], &n[1], &n[2], &n[3], &n[4]) >= 1) {
    map<string, int> ids;
    ids["S"] = 0;
    ids["M"] = 1;
    ids["L"] = 2;
    ids["XL"] = 3;
    ids["XXL"] = 4;
    
    int k; scanf("%d", &k);
    for (int i = 0; i < k; i++) {
      scanf("%s", buf);
      int id = ids[buf];
      int bans = 1000, bi = -1;
      for (int i2 = 4; i2 >= 0; i2--) {
        if (!n[i2]) continue;
        if (abs(i2 - id) < bans) {
          bans = abs(i2 - id);
          bi = i2;
        }
      }
      n[bi]--;
      printf("%s\n", name[bi]);
    }
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}