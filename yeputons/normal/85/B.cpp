#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
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
typedef pair<int, int> pii;
typedef vector<pii> vpii;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  const int m = 3; 
  vll k(m), t(m);
  while (scanf("%I64d%I64d%I64d", &k[0], &k[1], &k[2]) >= 3) {
    scanf("%I64d%I64d%I64d", &t[0], &t[1], &t[2]);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < m; i++)
      k[i] = min(k[i], (ll)n);

    vector<pair<ll, ll> > ct(n);
    for (int i = 0; i < n; i++)
      scanf("%I64d", &ct[i].first), ct[i].second = 0;

    for (int step = 0; step < m; step++) {
      multiset<ll> fr;
      for (ll i = 0; i < k[step]; i++)
        fr.insert(0);

      sort(ct.begin(), ct.end());
      for (int i = 0; i < n; i++) {
        ll stime = *fr.begin(); fr.erase(fr.begin());
        stime = max(stime, ct[i].first);
        stime += t[step];
        ct[i].second += stime - ct[i].first;
        ct[i].first = stime;
        fr.insert(stime);
      }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
      ans = max(ans, ct[i].second);
    printf("%I64d\n", ans);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}