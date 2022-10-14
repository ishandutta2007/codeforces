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
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n;
  while (scanf("%d", &n) >= 1) {
    if (n == 1) printf("a\na\nb\nb\n");
    else if (n == 2) printf("aa\nbb\ncc\ndd\n");
    else {
      if (n % 2 == 1) {
        for (int i = 0; i < 4; i++) {
          if (i >= 2)
            printf("e");
          for (int i2 = 0; i2 + 2 <= n; i2 += 2) {
            char c = 'a' + 2 * (i % 2) + (i2 / 2) % 2;
            printf("%c%c", c, c);
          }
          if (i < 2)
            printf("e");
          printf("\n");
        }
      } else {
        for (int i2 = 0; i2 < n; i2 += 2) {
          char c = 'a' + (i2 / 2) % 2;
          printf("%c%c", c, c);
        }
        printf("\n");
        for (int i = 0; i < 2; i++) {
          printf("c");
          for (int i2 = 1; i2 + 2 <= n; i2 += 2) {
            char c = 'd' + (i2 / 2) % 2 + 2 * i;
            printf("%c%c", c, c);
          }
          printf("c\n");
        }
        for (int i2 = 0; i2 < n; i2 += 2) {
          char c = 'a' + (i2 / 2) % 2;
          printf("%c%c", c, c);
        }
        printf("\n");
      }
    }
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}