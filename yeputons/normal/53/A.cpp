#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) {}
#endif

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (n); i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

bool prefix(string s, string p) {
  if (s.length() < p.length()) return false;
  for (int i = 0; i < p.length(); i++)
    if (s[i] != p[i]) return false;
  return true;
}

char src[1024], buf[1024];
int n;
int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  while (scanf("%s", src) >= 1) {
    scanf("%d", &n);

    vector<string> str(n);
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      str[i] = buf;
    }

    sort(str.begin(), str.end());

    bool f = false;
    for (int i = 0; i < n; i++) if (prefix(str[i], src)) {
      printf("%s\n", str[i].c_str());
      f = true;
      break;
    }
    if (!f) printf("%s\n", src);
    
    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}