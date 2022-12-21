#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int n,c,i,M,G,dec,ans;
map<int,int>Map;
int main()
{
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&c),G=__gcd(c,G),M=max(M,c);
    if (!Map[c]) Map[c]=1,dec--;
  }
  ans=M/G-dec;
  if (ans&1) puts("Alice");else puts("Bob");
  return 0;
}