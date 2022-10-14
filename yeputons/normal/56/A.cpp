#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

const char* bad[] = {
"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE", 0
};
char buf[1024];
int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    int a = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      int age;
      if (sscanf(buf, "%d", &age) >= 1) {
        if (age < 18) a++;
      } else {
        for (int i2 = 0; bad[i2]; i2++)
          if (!strcmp(bad[i2], buf)) { a++; break; }
      }
    }
    printf("%d\n", a);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}