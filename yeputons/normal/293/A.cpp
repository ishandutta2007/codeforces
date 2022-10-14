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

pii getRes(int c0, int c1, int c2) {
  if (c0 >= 2) {
    pii res = getRes(c0 % 2, c1, c2);
    return res;
  }
  if (c0 == 1) {
    pii res = getRes(0, c2, c1);
    swap(res.first, res.second);
    res.first++;
    return res;
  }
  if (c1 && c2) {
    int x = min(c1, c2);
    pii res = getRes(0, c1 - x, c2 - x);
    res.first += x;
    res.second += x;
    return res;
  }
  if (c1) {
    return mp(c1 / 2 + c1 % 2, 0);
  }
  if (c2) {
    return mp(0, c2 / 2);
  }
  return mp(0, 0);
}

const int MAXL = 2e6 + 100;
char s[MAXL + 1], t[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%d%s%s", &n, s, t) >= 1) {
    int l = strlen(s);
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < l; i++) {
      if (s[i] == '1' && t[i] == '1') c0++;
      if (s[i] == '1' && t[i] == '0') c1++;
      if (s[i] == '0' && t[i] == '1') c2++;
    }

    pii res = getRes(c0, c1, c2);
    if (res.first > res.second) printf("First\n");
    else if (res.first == res.second) printf("Draw\n");
    else printf("Second\n");
  }
  return 0;
}