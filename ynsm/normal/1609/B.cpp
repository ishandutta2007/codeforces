#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m, ans;
string s;

int f(int i) {
  return (0 <= i && i + 2 < n && s[i] == 'a' && s[i + 1] == 'b' &&
          s[i + 2] == 'c');
}
void solve() {
  cin >> n >> m >> s;
  for (int i = 0; i < n; i++)
    ans += f(i);
  while (m--) {
    int i;
    char x;
    cin >> i >> x;
    --i;
    for (int j = -2; j <= 2; j++)
      ans -= f(i + j);
    s[i] = x;
    for (int j = -2; j <= 2; j++)
      ans += f(i + j);
    cout << ans << endl;
  }
}
int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}