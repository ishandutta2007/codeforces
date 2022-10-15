#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7,B=330;
int n,tot,blk,bel[N],L[N],R[N],num[N],cnt[B];
int hd[B],tl[B],q[B][B];
ll a[N],s[N],sum[B];
vector<int>vec[B];
inline ll calc(int j){
	return a[j]*(num[j]+cnt[bel[j]])+s[j]+sum[bel[j]];
}
inline void build(int t){
	hd[t]=1,tl[t]=0;
	for(int i:vec[t]){
		while(hd[t]<=tl[t] && calc(i)>=calc(q[t][tl[t]]))tl[t]--;
		q[t][++tl[t]]=i;
	}
}
inline int Get(){
	int p=0;ll mx=0;
	for(int i=1;i<=tot;i++){
		while(hd[i]<tl[i] && calc(q[i][hd[i]])<=calc(q[i][hd[i]+1]))hd[i]++;
		if(hd[i]>tl[i])continue;
		int j=q[i][hd[i]];
		ll res=calc(j);
		if(res>mx)mx=res,p=j;
	}
	return p;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),blk=sqrt(n);
	for(int i=1;i<=n;i++)a[i]=read(),num[i]=1;
	for(int i=1;i<=n;i++)bel[i]=bel[i-1]+((i-1)%blk==0);
	for(int i=1;i<=n;i++)R[bel[i]]=i;
	for(int i=n;i;i--)L[bel[i]]=i;
	tot=bel[n];
	for(int i=1;i<=tot;i++){
		for(int j=L[i];j<=R[i];j++)vec[i].push_back(j);
		sort(vec[i].begin(),vec[i].end(),[&](int x,int y){return a[x]==a[y]?x>y:a[x]<a[y];});
	}
	for(int i=1;i<=tot;i++)build(i);
	ll ans=0;
	while(1){
		int x=Get();ll res=calc(x);
		if(res<=0)break;
		ans+=res;
		for(int i=1;i<bel[x];i++)sum[i]+=a[x];
		for(int i=bel[x]+1;i<=tot;i++)cnt[i]++;
		for(int i=L[bel[x]];i<x;i++)s[i]+=a[x];
		for(int i=x+1;i<=R[bel[x]];i++)num[i]++;
		for(int i=0;i<(int)vec[bel[x]].size();i++)
			if(vec[bel[x]][i]==x){vec[bel[x]].erase(vec[bel[x]].begin()+i);break;}
		build(bel[x]);
	}
	printf("%lld\n",ans);
	return 0;
}