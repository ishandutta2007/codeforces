#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5,M=N<<2;
int n,p[N],q[N],i,j,ip[N],iq[N],a[N],b[N],ans[N];
struct info{
	int x,y;
	int getv(int a){return max(x,a+y);}
}t[M];
int lb[M],rb[M],md[M];
info uni(info a,info b){
	return (info){max(b.x,a.x+b.y),a.y+b.y};
}
void build(int i,int l,int r){
	lb[i]=l;rb[i]=r;md[i]=l+r>>1;
	if(l==r){t[i]=(info){0,a[l]-b[l]};return;}
	build(i<<1,l,md[i]);build(i<<1|1,md[i]+1,r);
	t[i]=uni(t[i<<1],t[i<<1|1]);
}
void mdy(int i,int k){
	if(lb[i]==rb[i]){t[i]=(info){0,a[lb[i]]-b[lb[i]]};return;}
	mdy(i<<1|(k>md[i]),k);
	t[i]=uni(t[i<<1],t[i<<1|1]);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",p+i),ip[p[i]]=i;
	for(i=1;i<=n;++i)scanf("%d",q+i),iq[q[i]]=i;
	for(i=1;i<n;++i)b[q[i]]=1;for(i=1;i<=n;++i)a[i]=1;
	build(1,1,n);
	for(i=n,j=1;i;--i){
		for(;j<=n && t[1].getv(0)>0;++j)a[ip[j]]=0,mdy(1,ip[j]);
		if(i>1)b[q[i-1]]=0,mdy(1,q[i-1]);
		ans[i]=j-1;
	}
	for(i=1;i<=n;++i)printf("%d%c",ans[i],i==n?'\n':' ');
}