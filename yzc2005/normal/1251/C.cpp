#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
}
const int N = 3e5 + 5;
int t, n, nxt[N][10], cnt[N][2];
char s[N];
int main() {
  for (read(t); t; --t) {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    queue<int> a[2];
    for (int i = 1; i <= n; ++i) {
      a[(s[i] - '0') & 1].push(s[i] - '0');
    }
    while (!a[0].empty() || !a[1].empty()) {
      bool flag = 0;
      for (int j = 0; j < 2; ++j) {
        if (a[j].empty()) {
          while (!a[j ^ 1].empty()) {
            printf("%d", a[j ^ 1].front());
            a[j ^ 1].pop();
          }  
          flag = 1;
        }
      }
      if (flag) {
        break;
      }
      if (a[0].front() > a[1].front()) {
        printf("%d", a[1].front());
        a[1].pop();
      } else {
        printf("%d", a[0].front());
        a[0].pop();
      }
    }
    puts("");
  }
  return 0;
}