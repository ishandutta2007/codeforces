#include<bits/stdc++.h>
#define ll long long
#define N 300010
using namespace std;
int n,m,s[N];ll sum;
int main()
{
  int x;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",&s[i]),sum+=s[i];
  sort(s+1,s+n+1);
  scanf("%d",&m);
  while(m--)
  {
    scanf("%d",&x);
    printf("%lld\n",sum-s[n-x+1]);
  }
  return 0;
}