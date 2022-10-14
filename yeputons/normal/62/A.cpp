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

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

bool can(int a, int b) {
  if (a > b + 1) return false;
  if (b > 2 * (a + 1)) return false;
  return true;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int al, ar, bl, br;
  while (scanf("%d%d%d%d", &al, &ar, &bl, &br) >= 4) {
    if (can(ar, bl) || can(al, br))
      printf("YES\n");
    else
      printf("NO\n");
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}