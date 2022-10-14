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

bool mycmp(const pii &a, const pii &b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}
int main() {
  int n;
  while (scanf("%d", &n) >= 1) {
    vpii segs(n);
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &segs[i].first, &segs[i].second);
      if (segs[i].first > segs[i].second)
        swap(segs[i].first, segs[i].second);
    }
    sort(segs.begin(), segs.end(), mycmp);

    vi ans;
    int lastp = segs[0].second;
    ans.pb(segs[0].second);
    for (int i = 0; i < n; i++) {
      if (segs[i].first <= lastp) continue;
      lastp = segs[i].second;
      ans.pb(lastp);
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
      printf("%d%c", ans[i], "\n "[i + 1 < ans.size()]);
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}