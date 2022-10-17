#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long li;

const int maxn = 4e5 + 10;
int n;
priority_queue<int> q[3];

int main(void) {
  scanf("%d", &n);
  static char s[2];
  int cnt = 0;
  li ans = 0;
  for (int i = 1, x; i <= n; ++i) {
    scanf("%s%d", s, &x);
    if (s[0] == s[1] && s[0] == '0') {
      q[0].push(x);
    }
    if (s[0] == s[1] && s[0] == '1') {
      ans += x, ++cnt;
    }
    if (s[0] == '0' && s[1] == '1') {
      q[1].push(x);
    }
    if (s[0] == '1' && s[1] == '0') {
      q[2].push(x);
    }
  }
  while (!(q[1].empty() || q[2].empty())) {
    ans += q[1].top() + q[2].top();
    q[1].pop(), q[2].pop();
  }
  while (!q[1].empty()) {
    q[0].push(q[1].top());
    q[1].pop();
  }
  while (!q[2].empty()) {
    q[0].push(q[2].top());
    q[2].pop();
  }
  while (cnt && !q[0].empty()) {
    ans += q[0].top();
    q[0].pop();
    --cnt;
  }
  printf("%lld\n", ans);

  return 0;
}