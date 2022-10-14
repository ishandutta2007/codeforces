#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

int eprintf(const char *format, ...) {
  #ifdef DEBUG
  va_list args;
  va_start(args, format);
  int ret = vfprintf(stderr, format, args);
  va_end(args);
  return ret;
  #else
  return 0;
  #endif
}

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;

#define INF 2000000000
#define mp make_pair
#define pb push_back

#ifdef linux
#define LLD "%lld"
#elif _WIN32
#define LLD "%I64d"
#endif

bool build_edges(vi ty, int needt, vpii &es, ll m) {
  ll n = 0;
  vi ids;
  for (int i = 0; i < ty.size(); i++)
    if (ty[i] & needt) { n++; ids.pb(i); }
  if (m < n - 1) return false;
  if (m > ((n * (n - 1)) >> 1)) return false;

  for (int i = 1; i < ids.size(); i++)
    es.pb(mp(ids[i - 1], ids[i]));
  m -= (n - 1);
  for (int a = 0; (m > 0) && (a < ids.size()); a++)
    for (int b = a + 2; b < ids.size(); b++) {
      es.pb(mp(ids[a], ids[b]));
      if (!--m) break;
    }
  return true;
}

int main() {
  int n, v; ll m;
  while (scanf("%d" LLD "%d", &n, &m, &v) >= 3) {
    v--;
    
//    ll na = (n + 1) >> 1;
    ll na = 2;
    ll nb = n - na + 1;
    ll mcnt = ((na * (na - 1)) >> 1) + ((nb * (nb - 1)) >> 1);
    if ((m < n - 1) || (mcnt < m)) {
      printf("-1\n");
      break;
    }
    vi ty(n, -1);
    ty[v] = 3;
    int pos = 0;
    for (int i = 0; i < na - 1; i++) {
      if (ty[pos] < 0) {
        ty[pos++] = 1;
      } else {
        pos++;
        i--;
      }
    }
    for (int i = 0; i < nb - 1; i++) {
      if (ty[pos] < 0) {
        ty[pos++] = 2;
      } else {
        pos++;
        i--;
      }
    }

    vpii es;
    ll mcnt1 = (na * (na - 1)) >> 1;
//    while ((m - mcnt) < nb - 1) mcnt1++;
    if ((m - mcnt1) < nb - 1)
      mcnt1 -= nb - 1 - (m - mcnt1);

    assert(build_edges(ty, 1, es, mcnt1));
    assert(build_edges(ty, 2, es, m - mcnt1));
    for (int i = 0; i < es.size(); i++)
      printf("%d %d\n", es[i].first + 1, es[i].second + 1);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}