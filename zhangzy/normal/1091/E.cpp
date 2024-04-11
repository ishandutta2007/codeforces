#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, a[505000], ans[505000], b[505000];
ll l[505000], r[505000], sb[505000];

ll cal(int n,ll t){
  int p=lower_bound(b+1,b+n+1,t)-b-1;
  //printf(" cal %d %lld :: %lld\n",n,t,sb[p]+(n-p)*t+t*(t-1));
  return sb[p]+(n-p)*t+t*(t-1);
}

int main(){
  cin>>n;
  for (int i=1;i<=n;++i) scanf("%d",&a[i]), b[i]=a[i];
  sort(a+1,a+n+1,greater<int>());
  sort(b+1,b+n+1);
  for (int i=1;i<=n;++i) sb[i]=sb[i-1]+b[i];
  
  for (int i=0;i<=n;++i){
    l[i]= i==n? 0: a[i+1];
    r[i]= i==0? n: a[i];
  }
  ll sum=0;
  {
    ll res=0; 
    for (int i=1;i<=n;++i){
      sum+=a[i];
      ll t=cal(n-i,i);
      if (sum>t){
	if (sum-t>i) res=n+3;
	else res=max(res,sum-t);
      }
      //printf(" L  %d %lld\n",i,res);
      l[i]=max(l[i],res);
    }
  }
  {
    ll res=n;
    for (int i=n-1;i>=0;--i){
      sum-=a[i+1];
      ll t=cal(n-i,i+1);
      res=min(res,t-sum);
      r[i]=min(r[i],res);
    }
  }
  {
    sum=0;
    for (int i=1;i<=n;++i) sum^=a[i]&1;
  }
  int fl=0;
  for (int i=0;i<=n;++i){
    for (ll j=l[i];j<=r[i];++j)
      if ((j+sum)%2==0)
	ans[j]=fl=1;
  }
  if (!fl){
    puts("-1");
  }else{
    for (int i=0;i<=n;++i)
      if (ans[i]) printf("%d ",i);
    puts("");
  }
}