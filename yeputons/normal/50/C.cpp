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

using namespace std;

int eprintf(const char* format, ...) {
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

#define pb push_back
#define mp make_pair

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

struct pt {
  int x, y;
  pt() {}
  pt(int _x, int _y) : x(_x), y(_y) {}
  bool operator<(const pt &p2) const {
    if (y == p2.y) return x < p2.x;
    return y < p2.y;
  }
  bool operator==(const pt &p2) const { return x == p2.x && y == p2.y; }
  const pt operator-(const pt &p2) const { return pt(x - p2.x, y - p2.y); }
  const int operator*(const pt &p2) const {
    ll res = (ll)x * p2.y - (ll)y * p2.x;
    if (res < 0) return -1;
    else return !!res;
  }
};

pt root;
bool cmp(const pt &p1, const pt &p2) {
  int s = (p1 - root) * (p2 - root);
  if (!s) return p1 < p2;
  return s > 0;
}

bool bad(pt a, pt b, pt c) {
  return (b - a) * (c - b) <= 0;
}

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif
                    
  int n;
  while (scanf("%d", &n) >= 1) {
    vector<pt> pts(4 * n);
    for (int i = 0; i < n; i++) {
      pt p;
      scanf("%d%d", &p.x, &p.y);
      for (int d = 0; d < 4; d++)
        pts[i * 4 + d] = pt(p.x + dx[d], p.y + dy[d]);
    }
    n *= 4;

    sort(pts.begin(), pts.end());
    pts.resize(n = (unique(pts.begin(), pts.end()) - pts.begin()));

    root = pts[0]; pts.erase(pts.begin());
                  
    sort(pts.begin(), pts.end(), cmp);

    vector<pt> ans(n); int ae = 0;
    ans[ae++] = root;
    for (int i = 0; i < pts.size(); i++) {
      while (ae >= 2 && bad(ans[ae - 2], ans[ae - 1], pts[i]))
        ae--;
      ans[ae++] = pts[i];
    }
    ans.resize(ae);
    ans.pb(ans[0]);

    ll answer = 0;
    for (int i = 0; i + 1 < ans.size(); i++) {
      answer += max(abs(ans[i].x - ans[i + 1].x), abs(ans[i].y - ans[i + 1].y));
    }
    printf("%I64d\n", answer);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}