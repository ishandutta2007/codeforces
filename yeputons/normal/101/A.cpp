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

const int MAXL = 1e5;
char s[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int k;
  while (scanf("%s%d", s, &k) >= 2) {
    int n = strlen(s);
    vector<pii> cnt(26);
    for (int i = 0; i < 26; i++)
      cnt[i] = mp(0, i);

    for (int i = 0; i < n; i++) {
      cnt[s[i] - 'a'].first++;
    }
    sort(cnt.begin(), cnt.end());

    vb rem(26, true);
    for (int i = 0; i < 26; i++) {
      if (cnt[i].first > k) break;
      k -= cnt[i].first; cnt[i].first = 0;
      rem[cnt[i].second] = false;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
      ans += !!cnt[i].first;
    printf("%d\n", ans);
    for (int i = 0; i < n; i++)
      if (rem[s[i] - 'a'])
        printf("%c", s[i]);
    printf("\n");

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}