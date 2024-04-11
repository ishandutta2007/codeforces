#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

using Int = long long;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << endl; }
template <class T> bool chmin(T &t, const T &f) { if (t > f) { t = f; return true; } return false; }
template <class T> bool chmax(T &t, const T &f) { if (t < f) { t = f; return true; } return false; }

constexpr int E = 16;
constexpr int MAX_K = 16;
constexpr int MAX_Q = 200'010;

int K, Q;
Int L[MAX_Q], R[MAX_Q];
int V[MAX_Q];

int fss[E][(1 << MAX_K) + 10];
int gss[E][(1 << MAX_K) + 10];

int ansF[(1 << MAX_K) + 10];
int ansG[(1 << MAX_K) + 10];

int main() {
  for (; ~scanf("%d%d", &K, &Q); ) {
    for (int q = 0; q < Q; ++q) {
      scanf("%lld%lld%d", &L[q], &R[q], &V[q]);
    }
    
    for (int e = 0; e < E; ++e) {
      fill(fss[e], fss[e] + (1 << K) + 1, 0);
      fill(gss[e], gss[e] + (1 << K) + 1, 0);
    }
    
    for (int q = 0; q < Q; ++q) {
      const int r = L[q] & ((1 << K) - 1), a = L[q] >> K;
      const int s = R[q] & ((1 << K) - 1), b = R[q] >> K;
      for (int e = 0; e < E; ++e) {
        if ((V[q] >> e) & 1) {
          if (a == b) {
            ++fss[e][r];
            --fss[e][s + 1];
          } else if (a + 1 == b) {
            ++fss[e][r];
            --fss[e][1 << K];
            ++fss[e][0];
            --fss[e][s + 1];
          } else {
            ++fss[e][0];
            --fss[e][1 << K];
          }
          ++gss[e][a];
          --gss[e][b + 1];
        }
      }
    }
    
    for (int e = 0; e < E; ++e) {
      for (int x = 0; x < 1 << K; ++x) {
        fss[e][x + 1] += fss[e][x];
        gss[e][x + 1] += gss[e][x];
      }
      for (int x = 1 << K; x--; ) {
        fss[e][x + 1] = fss[e][x] ? 1 : 0;
        gss[e][x + 1] = gss[e][x] ? 1 : 0;
      }
      for (int x = 0; x < 1 << K; ++x) {
        fss[e][x + 1] += fss[e][x];
        gss[e][x + 1] += gss[e][x];
      }
    }
    
    bool ok = true;
    for (int q = 0; q < Q; ++q) {
      const int a = L[q] >> K, r = L[q] & ((1 << K) - 1);
      const int b = R[q] >> K, s = R[q] & ((1 << K) - 1);
      for (int e = 0; e < E; ++e) {
        if (!((V[q] >> e) & 1)) {
          if (a == b) {
            ok = ok && !(fss[e][s + 1] - fss[e][r] > 0 && gss[e][a + 1] - gss[e][a] > 0);
          } else if (a + 1 == b) {
            ok = ok && !(fss[e][1 << K] - fss[e][r] > 0 && gss[e][a + 1] - gss[e][a] > 0);
            ok = ok && !(fss[e][s + 1] - fss[e][0] > 0 && gss[e][b + 1] - gss[e][b] > 0);
          } else {
            ok = ok && !(fss[e][1 << K] - fss[e][r] > 0 && gss[e][a + 1] - gss[e][a] > 0);
            ok = ok && !(fss[e][1 << K] - fss[e][0] > 0 && gss[e][b] - gss[e][a + 1] > 0);
            ok = ok && !(fss[e][s + 1] - fss[e][0] > 0 && gss[e][b + 1] - gss[e][b] > 0);
          }
        }
      }
    }
    
    if (ok) {
      fill(ansF, ansF + (1 << K), 0);
      fill(ansG, ansG + (1 << K), 0);
      for (int e = 0; e < E; ++e) {
        for (int x = 0; x < 1 << K; ++x) {
          ansF[x] |= (fss[e][x + 1] - fss[e][x]) << e;
          ansG[x] |= (gss[e][x + 1] - gss[e][x]) << e;
        }
      }
#ifdef LOCAL
for(int q=0;q<Q;++q)for(int y=L[q];y<=R[q];++y)assert(V[q]==(ansF[y&((1<<K)-1)]&ansG[y>>K]));
#endif
      puts("possible");
      for (int x = 0; x < 1 << K; ++x) {
        printf("%d\n", ansF[x]);
      }
      for (int x = 0; x < 1 << K; ++x) {
        printf("%d\n", ansG[x]);
      }
    } else {
      puts("impossible");
    }
  }
  return 0;
}