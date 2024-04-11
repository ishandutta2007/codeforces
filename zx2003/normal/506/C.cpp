#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+5;
int n,m,k,p,i,j,h[N],a[N],lst[N];
ll L,R,M,ct[N],nw[N];
priority_queue<pii>q;
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(i=1;i<=n;++i)scanf("%d%d",h+i,a+i),R=max(R,h[i]+1ll*a[i]*m);
	for(;L<R;){
		M=L+R>>1;
		for(;!q.empty();q.pop());
		ll s=0;for(i=1;i<=n;++i)s+=ct[i]=max(0ll,(h[i]-(M-1ll*a[i]*m)+p-1)/p);if(s>m*k){L=M+1;continue;}
		for(i=1;i<=n;++i)if(ct[i])nw[i]=M,lst[i]=m+1,q.push(pii(max(0ll,m-M/a[i]+1),i));
		for(i=m;i;--i){
			for(j=0;j<k && !q.empty();){
				if(q.top().first>i)break;
				int u=q.top().second;q.pop();nw[u]-=(lst[u]-i)*a[u];
				nw[u]+=p;--ct[u];++j;
				lst[u]=i;
				if(ct[u])q.push(pii(max(0ll,i-nw[u]/a[u]),u));
			}
			if(!q.empty() && j<k)break;
		}
		if(i)L=M+1;else R=M;
	}
	printf("%lld\n",L);
	return 0;
}