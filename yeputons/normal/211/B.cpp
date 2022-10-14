#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define all(x) (all).begin(), (all).end()

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int MAXL = 1e6 + 1e3;
char s[MAXL + 1];

const int HSZ = 1 << 17;
const int HMSK = HSZ - 1;
map<int, int> htbl[HSZ];
const int P = 239017;

int hash(int x) {
  int ch = x + (x >> 4) * P + (x >> 9) * P + (x >> 19) * P;
  return ch & HMSK;
}

int main(int argc, char* argv[]) {
  #ifdef DEBUG
  {
    string filename = "std";
    if (argc >= 2) {
      filename = argv[1];
      int l = sz(filename);
      if (l >= 3 && string(filename, l - 3, 3) == ".in")
        filename = string(filename, 0, l - 3);
    }
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
  #endif

  int k;
  while (scanf("%s%d", s, &k) >= 1) {
    int n = strlen(s);
    for (int i = 0; i < HSZ; i++) htbl[i].clear();
    vi myid(k, -1); int lastid = 0;
    vi ans(k, 0);
    for (int i = 0; i < k; i++) {
      int cmsk = 0;
      char buf[100];
      scanf("%s", buf);
      for (int i2 = 0; buf[i2]; i2++)
        cmsk |= 1 << (buf[i2] - 'a');
      int ch = hash(cmsk);
      if (!htbl[ch].count(cmsk)) htbl[ch][cmsk] = lastid++;
      myid[i] = htbl[ch][cmsk];
    }

    vvi poses(26);
    for (int i = 0; i < n; i++)
      poses[s[i] - 'a'].pb(i);
    for (int i = 0; i < 26; i++)
      poses[i].pb(n);

    vi firptr(26, 0);

    for (int l = 0; l < n; l++) {
      for (int i = 0; i < 26; i++)
        while (poses[i][firptr[i]] < l)
          firptr[i]++;

      int r = n - 1;
      if (l > 0) {
        int pr = s[l - 1] - 'a';
        r = min(r, poses[pr][firptr[pr]] - 1);
      }
      int cmsk = 0;
      for (int i = 0; i < 26; i++)
        if (poses[i][firptr[i]] <= r)
          cmsk |= 1 << i;

      vector<pii> ord;
      for (int i = 0; i < 26; i++) if (cmsk & (1 << i))
        ord.pb(mp(poses[i][firptr[i]] - 1, i));
      sort(ord.begin(), ord.end());
      int ptr = sz(ord) -1 ;

      while (l <= r) {
        assert(cmsk > 0);
        int ch = hash(cmsk);
        if (htbl[ch].count(cmsk))
          ans[htbl[ch][cmsk]]++;

        assert(ptr >= 0);
        r = ord[ptr].first;
        assert(cmsk & (1 << ord[ptr].second));
        cmsk ^= 1 << ord[ptr].second;
        ptr--;
      }
    }

    for (int i = 0; i < k; i++)
      printf("%d\n", ans[myid[i]]);
  }
  return 0;
}