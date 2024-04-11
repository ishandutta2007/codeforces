#include<bits/stdc++.h>
#include<cstdio>
#define maxn 10010000
using namespace std;
typedef long long ll;
int psz,mu[maxn],vis[maxn],d[maxn],c[maxn],n,pri[maxn];
ll dis1=0,dis2=0,dis3=0,dis0=0;
int main(){
	scanf("%d",&n),mu[1]=c[1]=1;
	for(int i=2;i<=n;++i){
		if(!vis[i]){pri[++psz]=i,c[i]=i,mu[i]=-1;}
		for(int j=1;j<=psz&&pri[j]*i<=n;++j){
			vis[i*pri[j]]=1;
			if(i%pri[j]){
				mu[i*pri[j]]=-mu[i],c[i*pri[j]]=pri[j];
			} else {
				mu[i*pri[j]]=0,c[i*pri[j]]=pri[j];
				break;
			}
		}
		if(!vis[i]&&i>n/2)dis0++;
		d[c[i]]++;
	}
	dis0=dis0*(n-dis0-1)+dis0*(dis0-1)/2;
	for(int i=1;i<=n;++i)
		d[i]+=d[i-1];
	for(int i=1;i<=n;++i)
		dis2+=1ll*(d[i]-d[i-1])*d[n/i]-(1ll*c[i]*c[i]<=n);
	for(int i=1;i<=n;++i)
		dis1+=1ll*mu[i]*(n/i)*(n/i);
	dis1-=2*n-1;
	dis1=1ll*(n-1)*(n-2)/2-dis1/2;
	dis2++;
	dis2=dis2/2-dis1;
//	printf("[%lld,%lld]",dis1,dis2);
	ll ans=dis1*1+dis2*2+(1ll*(n-1)*(n-2)/2-dis1-dis2-dis0)*3;
	printf("%lld",ans);
}