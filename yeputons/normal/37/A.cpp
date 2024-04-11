#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
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

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define sqr(a, b) ((a) * (a))
#define INF 2000000000
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef double dbl;
typedef vector<dbl> vdbl;

typedef long long ll;
typedef vector<ll> vll;

typedef pair<int, int> pii;

typedef vector<bool> vb;
typedef vector<string> vs;

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++) scanf("%d", &as[i]);
    sort(as.begin(), as.end());

    int cnt = 0, bans = 0;
    int cans = 1;
    for (int i = 1; i < n; i++) {
      if (as[i - 1] == as[i]) {
        cans++;
      } else {
        cnt++; bans = max(bans, cans);
        cans = 1;
      }
    }
    cnt++; bans = max(bans, cans);
    printf("%d %d\n", bans, cnt);

    #ifndef DEBUG
    break;
    #endif
  } 
  return 0;
}