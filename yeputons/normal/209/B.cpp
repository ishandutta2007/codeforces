#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS)
#define sz(x) ((int)(x).size())
#define all(x) (all).begin(), (all).end()

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

ll getAns(ll b, ll c) {
  if (b > c) swap(b,c);

  if (b == 0) return 0;
  else if (b == 1) return c;
  else {
    if (b % 2 == 0) return b;
    else return c;
  }
}

int main(int argc, char* argv[]) {
  #ifdef DEBUG
  {
    string filename = "std";
    if (argc >= 2) {
      filename = argv[1];
      int l = sz(filename);
      if (l >= 3 && string(filename, l - 3, 3) == ".in")
        filename = string(filename, 0, l - 3);
    }
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
  }
  #endif

  ll a, b, c;
  while (scanf("%I64d%I64d%I64d", &a, &b, &c) >= 1) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);

    ll ans = 1e18;
    ans = min(ans, getAns(b - a, c + a) + a);
    ans = min(ans, getAns(c - a, b + a) + a);
    ans = min(ans, getAns(a + b, c - b) + b);
    printf("%I64d\n",ans);
  }
  return 0;
}