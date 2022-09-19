# include <bits/stdc++.h>
using namespace std;
char s[511];
int main() {
  scanf("%s", s);
  char low = 'a' - 1;
  for (int i = 0; s[i]; ++i) {
    if (s[i] > low + 1) {
      printf("NO\n");
      return 0;
    }
    low = max(low, s[i]);
    
  }
  printf("YES\n");
}