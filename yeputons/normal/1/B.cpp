#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define INF 2000000000
#define mp make_pair
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef double dbl;

typedef long long ll;
typedef vector<ll> vll;

typedef vector<bool> vb;
typedef vector<string> vs;

char buf[1024];
const char* encode(int id) {
  int l = 1, cnt = 26;
  for (; cnt < id; l++, id -= cnt, cnt *= 26);

  buf[l] = 0;
  for (int i = l - 1; i >= 0; i--) {
    buf[i] = 'A' + (id % 26);
    id /= 26;
  }
  return buf;
}
int decode(char* buf) {
  int id = 0;
  for (int i = 0; buf[i]; i++)
    id = id * 26 + (buf[i] - 'A' + 1);
  return id;
}

int main() {
  #ifdef DEBUG
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    for (int i = 0; i < n; i++) {
      scanf(" %s", buf);
      int r, c;
      if (sscanf(buf, "R%dC%d", &r, &c) == 2) {
        printf("%s%d\n", encode(c - 1), r);
      } else {
        int r = 0;
        for (int i = 0;; i++)
          if ((buf[i] >= '0') && (buf[i] <= '9')) {
            assert(sscanf(buf + i, "%d", &r) == 1);
            buf[i] = 0; break;
          }
        printf("R%dC%d\n", r, decode(buf));
      }
    }

    #ifndef DEBUG
    break;
    #endif
  }

  return 0;
}