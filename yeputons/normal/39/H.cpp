#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
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

string calc(int x, int n) {
  string res = "";
  for (; x; x /= n) res = string(1, '0' + (x % n)) + res;
  return res;
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    for (int a = 1; a <= n - 1; a++, printf("\n"))
    for (int b = 1; b <= n - 1; b++) {
      int c = a * b;
      string s = calc(c, n);
      if (b > 1)
        printf(" %2s", s.c_str());
      else
        printf("%1s", s.c_str());
    }

    #ifndef DEBUG
    break;
    #endif
  } 
  return 0;
}