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

const int MAXL = 1e5;

bool is_prefix(const char *pr, const char *s) {
  for (int i = 0; pr[i]; i++)
    if (s[i] != pr[i]) return false;
  return true;
}

char s[MAXL + 1];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int k;
  while (scanf("%s%d", s, &k) >= 1) {
    vector<string> bs(k);
    for (int i = 0; i < k; i++) {
      char buf[11];
      scanf("%s", buf);
      bs[i] = buf;
    }

    int n = strlen(s);
    vi bads(n);
    for (int i = 0; i < n; i++) {
      int val = n - 1;
      for (int i2 = 0; i2 < k; i2++)
        if (is_prefix(bs[i2].c_str(), s + i)) {
          val = min(val, i + (int)bs[i2].length() - 2);
        }
      bads[i] = val;
    }

    int blen = 0, bst = 0;
    int cbord = n - 1;
    for (int st = n - 1; st >= 0; st--) {
      cbord = min(cbord, bads[st]);
      if (st <= cbord && blen < cbord - st + 1) {
        blen = cbord - st + 1;
        bst = st;
      }
    }
    #ifdef DEBUG
    eprintf("%s\n", string(s, bst, blen).c_str());
    #endif
    printf("%d %d\n", blen, bst);
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}