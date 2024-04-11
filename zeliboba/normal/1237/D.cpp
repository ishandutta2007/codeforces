#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

const int N = 19;
int mi[1 << N][N];
int ma[1 << N][N];
char good[1 << N][N];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(4 * n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < a.size(); ++i) {
    a[i] = a[i % n];
    mi[i][0] = a[i];
    ma[i][0] = a[i];
    good[i][0] = 1;
  }
  for (int t = 1; t < N; ++t) {
    for (int i = 0; i < a.size(); ++i) if (i + (1 << t) <= a.size()) {
      mi[i][t] = min(mi[i][t - 1], mi[i + (1 << (t - 1))][t - 1]);
      ma[i][t] = max(ma[i][t - 1], ma[i + (1 << (t - 1))][t - 1]);
      good[i][t] = good[i][t-1] && good[i + (1 << (t - 1))][t - 1] && 2 * mi[i + (1 << (t - 1))][t - 1] >= ma[i][t - 1];
    }
  }
  for (int i = 0; i < n; ++i) {
    int l = 1, curma = a[i];
    for (int t = N - 1; t >= 0; --t) if (i + l + (1 << t) <= a.size()) {
      if (good[i + l][t] && mi[i + l][t] * 2 >= curma) {
        curma = max(curma, ma[i + l][t]);
        l += (1 << t);
      }
    }
    if (l + i == a.size()) l = -1;
    cout << l << ' ';
  }
  return 0;
}