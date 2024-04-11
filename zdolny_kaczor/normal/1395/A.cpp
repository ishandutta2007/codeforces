#include <bits/stdc++.h>
int main(){
  int t;
  scanf("%d",&t);
  while(t--) {
    int r,g,b,w;
    scanf("%d%d%d%d", &r, &g, &b, &w);
    if (r%2+g%2+b%2+w%2<=1 || (r&&g&&b&&r%2+g%2+b%2+w%2>=3)) puts("YES"); else puts("NO");
  }
}