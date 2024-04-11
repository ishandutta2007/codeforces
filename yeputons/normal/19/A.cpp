#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

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

struct command {
  int score;
  int throwed, got;
  int id;
  command() { score = throwed = got = 0; id = -1; }
  int diff() const { return throwed - got; }
  bool operator<(const command &b) const {
    if (score != b.score) return score < b.score;
    if (diff() != b.diff()) return diff() < b.diff();
    return throwed < b.throwed;
  }
};

vector<string> names;
bool cmp2(const command &a, const command &b) {
  return names[a.id] < names[b.id];
}

char buf[256];
int main() {
  int n;
  while (scanf("%d", &n) >= 1) {
    map<string, int> ids;
    names = vector<string>(n);
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      names[i] = buf;
      ids.insert(mp(names[i], i));
    }

    vector<command> cmds(n);
    for (int i = 0; i < n; i++) cmds[i].id = i;
    int m = (n * (n - 1)) >> 1;
    for (int i = 0; i < m; i++) {
      int g1, g2; char *buf2;
      assert(scanf(" %s %d:%d", buf, &g1, &g2) >= 3);
      for (int i = 0;; i++)
        if (buf[i] == '-') {
          buf[i] = 0;
          buf2 = buf + (i + 1);
          break;
        }
      int id1 = ids.find(buf)->second, id2 = ids.find(buf2)->second;
      cmds[id1].throwed += g1;
      cmds[id1].got += g2;
      cmds[id2].throwed += g2;
      cmds[id2].got += g1;
      
      if (g1 > g2) {
        cmds[id1].score += 3;
      } else if (g1 == g2) {
        cmds[id1].score += 1;
        cmds[id2].score += 1;
      } else {
        cmds[id2].score += 3;
      }
    }
    sort(cmds.begin(), cmds.end());
    sort(cmds.begin() + (n >> 1), cmds.end(), cmp2);
    for (int i = (n >> 1); i < n; i++)
      printf("%s\n", names[cmds[i].id].c_str());

    break;
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}