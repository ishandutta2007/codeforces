#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 1e5;

int n, v[maxn];
priority_queue<long long> q;
long long sub;

long long Melt(int t) {
  long long ans = 0;
  while (!q.empty() && -q.top() - sub <= t) {
    ans += -q.top() - sub;
    q.pop();
  }
  sub += t;
  return ans + q.size() * (long long)t;
}

int main(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", v + i);
  }
  for (int i = 0; i < n; ++i) {
    int t;
    scanf("%d", &t);
    q.push(-(v[i] + sub));
    printf("%lld\n", Melt(t));
  }
  return 0;
}