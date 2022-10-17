#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int n,s;

int a[N];

int m,x,y;

int solve(int p)
{
   if(p<1||p>n)
      return 2e18;
   int v=a[p];
   return max(x-v,0ll)+max(y-(s-v),0ll);
}

signed main()
{
   scanf("%lld",&n);
   for(int i=1;i<=n;i++)
      scanf("%lld",&a[i]),s+=a[i];
   sort(a+1,a+n+1);
   scanf("%lld",&m);
   while(m--)
   {
      scanf("%lld%lld",&x,&y);
      int p=lower_bound(a+1,a+n+1,x)-a;
      int ans=2e18;
      ans=min(ans,solve(p));
      ans=min(ans,solve(p-1));
      p=lower_bound(a+1,a+n+1,s-y)-a;
      ans=min(ans,solve(p));
      ans=min(ans,solve(p-1));
      printf("%lld\n",ans);
   }
}