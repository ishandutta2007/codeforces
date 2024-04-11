#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

char buf[1024];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s", buf) >= 1) {
    int l = 0;
    int lev = 0;

    for (int i = 0; buf[i];) {
      assert(buf[i++] == '<');
      if (buf[i] == '/') {
        i++;
        lev--;
        for (int i2 = 0; i2 < lev; i2++)
          printf("  ");
        printf("</%c>\n", buf[i]);
        i++;
      } else {
        for (int i2 = 0; i2 < lev; i2++)
          printf("  ");
        printf("<%c>\n", buf[i]);
        lev++;
        i++;
      }
      assert(buf[i++] == '>');
    }
  }
  return 0;
}