#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <cassert>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>

#define pb push_back
#define mp make_pair

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

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

void merge(vi &col, int a, int b) {
  a = col[a];
  b = col[b];
  for (unsigned int i = 0; i < col.size(); i++)
    if (col[i] == a) col[i] = b;
}

int main() {
  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi targ(n);
    vi d(n);

    for (int i = 0; i < n; i++) scanf("%d", &targ[i]), targ[i]--;
    for (int i = 0; i < n; i++) scanf("%d", &d[i]);

    vi col(n);
    for (int i = 0; i < n; i++) col[i] = i;

    for (int i = 0; i < n; i++) {
      if (i >= d[i])
        merge(col, i - d[i], i);
      if (i + d[i] < n)
        merge(col, i + d[i], i);
    }

    for (int i = 0; i < n; i++)
      eprintf("%d%c", col[i], "\n "[i + 1 < n]);

    bool good = true;
    for (int i = 0; i < n; i++)
      if (col[targ[i]] != col[i]) {
        good = false;
        break;
      }
    printf(good ? "YES\n" : "NO\n");

    #ifndef DEBUG
    break;
    #endif
  }

  return 0;
}