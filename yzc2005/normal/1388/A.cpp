#include <bits/stdc++.h>
using namespace std;
int main() {
  int T; scanf("%d", &T); while (T--) {
    int n; scanf("%d", &n);
    if (n <= 30) puts("NO");
    else {
      puts("YES");
      if (n == 31) puts("14 10 6 1");
      else if (n == 37) puts("6 14 15 2");
      else if (n == 41) puts("6 10 21 4");
      else if (n == 46) puts("6 14 15 11");
      else printf("6 10 15 %d\n", n - 31); 
    }
  } 
}