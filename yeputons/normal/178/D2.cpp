#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

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

const int pcnt = 8;
const int px[] = { 0, 1, 2, 0, 1, 2, 0, 3 };
const int py[] = { 0, 0, 0, 1, 1, 1, 2, 3 };

const int ocnt = 8;
const int ox[] = { 3, 3, 0, 1, 1, 2, 3, 2 };
const int oy[] = { 0, 1, 3, 2, 3, 3, 2, 2 };
const int ot[] = { 2, 2, 0, 1, 0, 2, 0, 0 };

const int dx[] = { 0, 1, 1, 1 };
const int dy[] = { -1, -1, 0, 1 };

int n, s;
bool check(const vi &as) {
        bool g = true;
        for (int y = 0; y < n; y++) {
          int cs = 0;
          for (int x = 0; x < n; x++)
            cs += as[y * n + x];
          if (cs != s) return false;
        }
        for (int x = 0; x < n; x++) {
          int cs = 0;
          for (int y = 0; y < n; y++)
            cs += as[y * n + x];
          if (cs != s) return false;
        }
        int cs1 = 0, cs2 = 0;
        for (int x = 0; x < n; x++) {
          cs1 += as[x * n + x];
          cs2 += as[(n - 1 - x) * n + x];
        }
        if (cs1 != s) return false;
        if (cs2 != s) return false;
        return true;
}

vector<pii> rems;
vi asvals;
vi cvals;

int mat[4][4];

vi nrems;
vi tmpas;

bool go(int cpos) {
  if (cpos >= pcnt) {
    for (int i = 0; i < pcnt; i++)
      mat[py[i]][px[i]] = rems[cvals[i]].first;

    for (int i = 0; i < sz(rems); i++)
      nrems[i] = rems[i].second;
    for (int i = 0; i < ocnt; i++) {
      int x0 = ox[i], y0 = oy[i], ty = ot[i];

      int sum = 0;
      for (int d = -3; d <= 3; d++) if (d) {
        int x = x0 + dx[ty] * d, y = y0 + dy[ty] * d;
        if (x < 0 || y < 0 || x >= n || y >= n) continue;
        sum += mat[y][x];
      }
      int nval = s - sum;
      int id = lower_bound(asvals.begin(), asvals.end(), nval) - asvals.begin();
      
      if (id >= sz(asvals)) return false;
      if (asvals[id] != nval) return false;
      if (!nrems[id]) return false;
      nrems[id]--;

      mat[y0][x0] = nval;
    }

    tmpas.resize(n * n);
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
      tmpas[y * n + x] = mat[y][x];
    if (!check(tmpas)) return false;

    printf("%d\n", s);
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++) {
      printf("%d%c", mat[y][x], "\n "[x + 1 < n]);
    }
    return true;
  }

  for (int cv = 0; cv < sz(rems); cv++) if (rems[cv].second) {
    rems[cv].second--;
    cvals[cpos] = cv;
    if (go(cpos + 1)) return true;
    rems[cv].second++;
  }
  return false;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    vi as(n * n);
    s = 0;
    for (int i = 0; i < n * n; i++) {
      scanf("%d", &as[i]);
      s += as[i];
    }
    assert((s % n) == 0);
    s /= n;
    sort(as.begin(), as.end());

    if (n <= 3) {
      do {
        if (check(as)) {
          printf("%d\n", s);
          for (int y = 0; y < n; y++)
          for (int x = 0; x < n; x++)
            printf("%d%c", as[y * n + x], "\n "[x + 1 < n]);
          goto end;
        }
      } while (next_permutation(as.begin(), as.end()));
    } else {
      asvals = as;
      asvals.erase(unique(asvals.begin(), asvals.end()), asvals.end());
      rems = vector<pii>(sz(asvals));
      nrems = vi(sz(rems));
      for (int i = 0; i < sz(as); i++) {
        int id = lower_bound(asvals.begin(), asvals.end(), as[i]) - asvals.begin();
        assert(asvals[id] == as[i]);
        rems[id].first = as[i];
        rems[id].second++;
      }

      cvals = vi(pcnt);
      if (go(0)) goto end;
    }

    assert(false);
    end:;
    break;
  }
  return 0;
}