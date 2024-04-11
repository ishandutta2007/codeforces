#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500, mod = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= mod)
    a -= mod;
  return a;
}
int sub(int a, int b) {
  a -= b;
  if (a < 0)
    a += mod;
  return a;
}
int mult(int a, int b) { return 1ll * a * b % mod; }

int n, a[N];
stack<int> st;
int l[N], r[N];

int dp[N];

void solve() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    while (!st.empty() && a[st.top()] >= a[i]) {
      r[st.top()] = i - 1;
      st.pop();
    }
    if (st.empty())
      l[i] = 1;
    else
      l[i] = st.top() + 1;
    st.push(i);
  }
  while (!st.empty()) {
    r[st.top()] = n;
    st.pop();
  }
  if(n & 1)
    dp[0] = mod - 1;
  else
    dp[0] = 1;
  int k = 0;
  for (int i = 1; i <= n; i++) {
    int x = mult(sub(dp[i - 1], (l[i] == 1 ? 0 : dp[l[i] - 2])), a[i]);
    x = sub(0, x);
    dp[i] = add(dp[i], x);
    dp[r[i] + 1] = sub(dp[r[i] + 1], x);
    k = add(k, dp[i]);
    dp[i] = add(k, dp[i - 1]);
  }
  printf("%d\n", k);
}
int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--)
    solve();
}