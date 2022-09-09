#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,T,a[N],t[N],v[N],xb,i,l,r,m,x;
pair<int,int>vv[N];
int main(){
	scanf("%d%d",&n,&T);
	for(i=1;i<=n;++i)scanf("%d%d",a+i,t+i);l=0,r=n;
	for(;l<r;){
		m=(l+r+1)>>1;
		for(i=1,xb=0;i<=n;++i)if(a[i]>=m)v[++xb]=t[i];
		sort(v+1,v+xb+1);x=T;
		for(i=1;i<=xb && x>=v[i];++i)x-=v[i];--i;
		if(i>=m)l=m;
			else r=m-1;
	}
	printf("%d\n",l);
	for(i=1,xb=0;i<=n;++i)if(a[i]>=l)vv[++xb]=make_pair(t[i],i);
	sort(vv+1,vv+xb+1);x=T;
	for(i=1;i<=xb && i<=l && x>=vv[i].first;++i)x-=vv[i].first;printf("%d\n",--i);
	for(;i;--i)printf("%d ",vv[i].second);
	return 0;
}