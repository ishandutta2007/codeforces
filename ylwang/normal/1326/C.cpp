#include <iostream>
#define MOD 998244353
using namespace std;
int a[200005];
int main()
{
 int n,k;
 long long ans=1,res=0;
 cin>>n>>k;
 int lp=0;
 for(int i=1;i<=n;i++)
 {
  cin>>a[i];
  if(a[i]>=n-k+1)
  {
   if(!lp)lp=i;
   else
   {
    ans=ans*(i-lp)%MOD;
    lp=i;
   }
   res+=a[i];
  }
 }
 cout<<res<<' '<<ans<<endl;
 return 0;
}