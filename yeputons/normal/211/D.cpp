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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define all(x) (all).begin(), (all).end()

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

struct Item {
  int L, R;
  ll val;
  int len() const { return L + R + 1; }
  bool operator<(const Item &b) const { return len() < b.len(); }
};

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

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    vi prle(n, -1), nel(n, n);
    {
      vector<pii> st;
      for (int i = 0; i < n; i++) {
        while (!st.empty() && st.back().first > as[i])
          st.pop_back();
        if (!st.empty())
          prle[i] = st.back().second;
        st.pb(mp(as[i], i));
      }
    }
    {
      vector<pii> st;
      for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.back().first >= as[i])
          st.pop_back();
        if (!st.empty())
          nel[i] = st.back().second;
        st.pb(mp(as[i],i));
      }
    }

    vector<Item> ps(n);
    for (int i = 0; i < n; i++) {
      ps[i].L = i - prle[i] - 1;
      ps[i].R = nel[i] - i - 1;
      ps[i].val = as[i];
    }
    vector<Item> sps = ps;
    sort(sps.begin(), sps.end());

    vvi evs(n + 1);
    for (int i = 0; i < n; i++) {
      evs[ps[i].L + 1].pb(i);
      evs[ps[i].R + 1].pb(i);
    }

    ll cdiff = 0;
    for (int i = 0; i < n; i++)
      cdiff += ps[i].val;
    vector<long double> ans(n + 1);
    long double cans = 0;
    int ptr = 0;

    for (int k = 1; k <= n; k++) {
      while (ptr < sz(sps) && sps[ptr].len() < k) {
        cans -= sps[ptr].val;
        cdiff += sps[ptr].val;
        ptr++;
      }
      cans += cdiff;

      ans[k] = cans;

      for (int i = 0; i < sz(evs[k]); i++) {
        int id = evs[k][i];
        cdiff -= ps[id].val;
      }
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int k;
      scanf("%d", &k);
      printf("%.18e\n", (double)(ans[k] / (n - k + 1)));
    }
    #ifdef DEBUG
    printf("\n");
    #endif
  }
  return 0;
}