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

const int MAXL = 1e5 + 100;

ll A(ll n, ll k) {
  ll res = 1;
  for (int i = 0; i < k; i++)
    res *= n - i;
  return res;
}

char s[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  while (scanf("%s", s) >= 1) {
    int cq = 0;
    vb was(26, false);

    for (int i = 0; s[i]; i++) {
      if (s[i] == '?') cq++;
      else if (isalpha(s[i]))
        was[s[i] - 'A'] = true;
    }

    ll cnt = 0;
    for (int i = 0; i < sz(was); i++)
      cnt += !!was[i];
    assert(cnt <= 10);
    
    ll ans = A(10, cnt);
    if (isalpha(s[0])) {
      assert(cnt >= 1);
      ans -= A(9, cnt - 1);
    }

    if (s[0] == '?') {
      cq--;
      ans *= 9;
    }

    printf("%I64d", ans);
    for (int i = 0; i < cq; i++)
      printf("0");
    printf("\n");
  }
  return 0;
}