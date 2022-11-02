#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
int n,k;ll a[N],b[N],t[N];

bool check(ll mid)
{
  ll cnt=0;
  for(int i=1;i<=n;i++)
    cnt+=max((b[i]*(k-1)-a[i]+mid-1)/mid,0ll);
  
  if(cnt>k)return false;
  int tot=0;
  for(int i=1;i<=n;i++)
    for(ll sum=a[i];sum<b[i]*(k-1);sum+=mid){
	  t[++tot]=sum/b[i];
	}
  if(tot>k)return false;
  sort(t+1,t+tot+1);
  for(int i=1;i<=tot;i++)
    if(t[i]<i-1)return false;
  return true;
}

int main()
{
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
  for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
  int tag=0;
  for(int i=1;i<=n;i++)
    if(a[i]<(k-1)*b[i])tag=1;
  if(!tag){printf("0\n");return 0;}
  ll l=1,r=1e18;
  while(r-l>1)
  {
  	ll mid=l+r>>1;
    if(check(mid))r=mid;
    else l=mid+1;
  }
  if(check(l))printf("%lld\n",l);
  else if(check(r))printf("%lld\n",r);
  else printf("-1\n");
  return 0;
}