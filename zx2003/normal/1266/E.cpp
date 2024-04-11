#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],i,q,s,t,u;
long long ans;
unordered_map<int,int>mp[N];
void add(int x,int v){ans-=max(a[x],0);a[x]+=v;ans+=max(a[x],0);}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),ans+=a[i];
	for(scanf("%d",&q);q--;){
		scanf("%d%d%d",&s,&t,&u);
		if(mp[s][t])add(mp[s][t],1);
		mp[s][t]=u;if(u)add(u,-1);
		printf("%lld\n",ans);
	}
	return 0;
}