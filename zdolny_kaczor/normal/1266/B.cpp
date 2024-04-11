#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d",&t);
  while(t--) {
    long long x;
    scanf("%lld",&x);
    if (x>14&&x%14>=1&&x%14<=6) puts("YES"); else puts("NO");
  }
}