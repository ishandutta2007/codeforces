#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

bool go(int &a, int &b, int cur) {
  if (cur == 0) { // Maximize a cnt
    for (int ca = min(a, 2); ca >= 0; ca--) {
      int rem = 22 - ca * 10;
      if (b >= rem) {
        a -= ca;
        b -= rem;
        return true;
      }
    }
  } else { // Minimize a cnt
    for (int ca = 0; ca <= min(a, 2); ca++) {
      int rem = 22 - ca * 10;
      if (b >= rem) {
        a -= ca;
        b -= rem;
        return true;
      }
    }
  }
  return false;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int a, b;
  while (scanf("%d%d", &a, &b) >= 1) {
    int cur = 0;
    while (go(a, b, cur)) {
      cur = !cur;
    }
    printf(cur == 0 ? "Hanako\n" : "Ciel\n");
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}