#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define TASKNAME "std"
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int MAXL = 1e6 + 1e3;
char s[MAXL + 1];

int cnts[MAXL + 1];

int main()  {
  #ifdef DEBUG
  freopen(TASKNAME ".in", "r", stdin);
  freopen(TASKNAME ".out", "w", stdout);
  #endif

  int k;
  while (scanf("%d%s", &k, s) >= 1) {
    int n = strlen(s);
    memset(cnts, 0, sizeof cnts);

    ll res = 0;
    int csum = 0;
    cnts[csum]++;

    for (int i = 0; i < n; i++) {
      csum += s[i] == '1';
      int nsum = csum - k;
      if (nsum >= 0)
        res += cnts[nsum];
      cnts[csum]++;
    }
    printf("%I64d\n", res);
  }
  return 0;
}