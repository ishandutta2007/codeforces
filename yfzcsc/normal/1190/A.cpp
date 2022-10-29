#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pi[101000];
int main(){
	ll n,m,K;
	scanf("%lld%lld%lld",&n,&m,&K);
	for(int i=1;i<=m;++i)
		scanf("%lld",&pi[i]);
	ll nw=1,step=0,ans=0,ptr=1;
	while(ptr<=m){
	//	printf("{%lld<%lld,%lld>}",ptr,step,nw);
		if(nw*K+step<pi[ptr]){
			nw=(pi[ptr]-1-step)/K+1;
			continue;
		}
		ll nstep=0;
		while(nw*K+step>=pi[ptr]&&ptr<=m){
			ptr++,nstep++;
		}
		step+=nstep;
		ans++;
	}
	printf("%lld",ans);
}