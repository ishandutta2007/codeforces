#include<bits/stdc++.h>
#define maxn 310
using namespace std;
int a[maxn],ls,tr[maxn],n,Q,ans,ans1,lim;
long long T;
void add(int x,int a){for(;x<=lim;x+=x&-x)tr[x]=max(tr[x],a);}
int query(int x){int ans=0;for(;x;x-=x&-x)ans=max(ans,tr[x]);return ans;}
int main(){
	//scanf("%d",&Q);
	Q=1;
	while(Q--){
		scanf("%d%lld",&n,&T),ans=ans1=0;lim=300;
		for(int i=1;i<=lim;++i)tr[i]=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int cir=min((long long)n,T)*n;
		for(int i=1,j=0;i<=cir;++i){
			if(j==n)j=1;else j++;
			add(a[j],ls=query(a[j])+1);
			ans=max(ans,ls);
		}
		if(n>=T){
			printf("%d\n",ans);
			continue;
		} else {
			for(int i=1;i<=n;++i){
				add(a[i],ls=query(a[i])+1);
				ans1=max(ans1,ls);
			}
			printf("%lld\n",ans+(ans1-ans)*(T-n));
		}
	}
}