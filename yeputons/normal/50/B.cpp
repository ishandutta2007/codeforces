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

int eprintf(const char* format, ...) {
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

typedef pair<int, int> pii;
typedef vector<pii> vpii;

char s[(int)1e5 + 100];
int cnt[256];

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif
  
  while (scanf("%s", s) >= 1) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; s[i]; i++)
      cnt[(int)s[i]]++;

    long long ans = 0;
    for (int a = 0; a < 256; a++)
      ans += (long long)cnt[a] * cnt[a];
    printf("%I64d\n", ans);
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}