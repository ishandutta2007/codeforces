#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>

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

char buf1[210];
char buf2[210];
int cnt[256];
int main() {
  while (1) {
    memset(buf1, 0, sizeof buf1);
    memset(buf2, 0, sizeof buf2);
    fgets(buf1, sizeof buf1, stdin);
    fgets(buf2, sizeof buf2, stdin);
    if (!buf1[0] || !buf2[0]) break;
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; buf1[i]; i++)
      if (buf1[i] != ' ')
	cnt[buf1[i]]++;
    
    bool g = true;
    for (int i = 0; buf2[i]; i++)
      if (buf2[i] != ' ')
	if (--cnt[buf2[i]] < 0) g = false;
    printf(g ? "YES\n" : "NO\n");
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}