#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;

char s[200];
char *s2 = "hello";
int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  while (scanf("%s", s) >= 1) {
    int n = strlen(s);
    vi le(6, 1e9);
    le[0] = 0;
    for (int b = 0; b < 5; b++) {
      for (int i = le[b]; i < n; i++)
        if (s[i] == s2[b]) {
          le[b + 1] = min(le[b + 1], i + 1);
        }
    }
    printf(le[5] <= n ? "YES\n" : "NO\n");

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}