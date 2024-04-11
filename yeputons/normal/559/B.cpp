#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...)
#endif
#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

#ifdef DEBUG
struct Timestamper {
  string msg;
  clock_t start;

  Timestamper(const string &_msg) : msg(_msg), start(clock()) {}
  ~Timestamper() {
    eprintf("[ %s ] Time=%.3lfs\n", msg.c_str(), (clock() - start) * 1.0 / CLOCKS_PER_SEC);
  }
} __timestamper("end");
#else
struct Timestamper {};
#endif

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

const int inf = 1e9;

void norm(char *s, int n) {
  if (n % 2 == 1) return;
  int n2 = n / 2;
  norm(s, n2);
  norm(s + n2, n2);

  int k = 0;
  while (k < n2 && s[k] == s[n2 + k]) {
    k++;
  }
  if (k < n2 && s[k] > s[n2 + k]) {
    for (int i = 0; i < n2; i++)
      swap(s[i], s[n2 + i]);
  }
}

const int MAXL = int(2e5);
char s1[MAXL + 1];
char s2[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  while (scanf("%s%s", s1, s2) >= 1) {
    int n = strlen(s1);
    assert(n == (int)strlen(s2));

    norm(s1, n);
    norm(s2, n);
    #ifdef DEBUG
    eprintf("%s\n%s\n", s1, s2);
    #endif
    if (!strcmp(s1, s2)) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}