#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;
int a[400000];
int b[400000];
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(10) << fixed;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  for (int i = 0; i < 30; i++) {
    int m = (1 << (i + 1)) - 1;
    int pow = (1 << i);
    for (int j = 0; j < N; j++) {
      b[j] = a[j] & m;
    }
    sort(b, b + N);
    ll all = (N * (N - 1)) / 2;
    ll cnt1 = 0;
    for (int j = 0; j < N; j++) {
      int N1 = (b + N) - lower_bound(b + j + 1, b + N, 3 * pow - b[j]);
      int N2 = (b + N) - lower_bound(b + j + 1, b + N, 2 * pow - b[j]);
      int N3 = (b + N) - lower_bound(b + j + 1, b + N, pow - b[j]);
      cnt1 += (N1 + N3) - N2;
      // if(i < 5) cout << N1 << ' ' << N2 << ' ' << N3 << endl;
    }
    if (cnt1 % 2 == 1) ans += pow;
  }
  cout << ans << endl;
}