#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) {}
#endif

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

int n;
char buf1[11], buf2[11];
int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    set<pair<string, string> > ls;
    for (int i = 0; i < n; i++) {
      scanf("%s%s", buf1, buf2);
      ls.insert(mp(buf1, buf2));
    }
    printf("%d\n", ls.size());
    
    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}