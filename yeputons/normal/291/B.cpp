#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>

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

const int MAXL = 1e5 + 1e3;
char buf[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  for (;;) {
    if (!gets(buf)) break;

    string s = "";
    bool haslex = false;
    bool quo = false;
    for (int i = 0;; i++) {
      if ((buf[i] == ' ' || buf[i] == 0) && !quo) {
        if (haslex) printf("<%s>\n", s.c_str());
        s = "";
        haslex = false;
      } else if (buf[i] == '"') {
        quo = !quo;
        if (quo) haslex = true;
      } else {
        s += buf[i];
        haslex = true;
      }
      if (!buf[i]) break;
    }

    #ifndef DEBUG
    break;
    #else
    printf("\n");
    #endif
  }
  return 0;
}