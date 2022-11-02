#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
const int N=400010;
int n,m,hs=0;
LL a[N],Ha[N];
int Lrt[N],Rrt[N];
namespace Seg{
	static const int S=N*45;
	int ls[S],rs[S],Max[S],tot=0;
	void build(int &rt,int L,int R){
		Max[rt]=0;
		if (L==R)
			return;
		int mid=(L+R)>>1;
		build(ls[rt],L,mid);
		build(rs[rt],mid+1,R);
	}
	void update(int &rt,int prt,int L,int R,int x,int v){
		if (!rt||rt==prt)
			rt=++tot,Max[rt]=Max[prt];
		Max[rt]=max(Max[rt],v);
		if (L==R)
			return;
		int mid=(L+R)>>1;
		if (!ls[rt])
			ls[rt]=ls[prt];
		if (!rs[rt])
			rs[rt]=rs[prt];
		if (x<=mid)
			update(ls[rt],ls[prt],L,mid,x,v);
		else
			update(rs[rt],rs[prt],mid+1,R,x,v);
	}
	int query(int rt,int L,int R,int xL,int xR){
		if (R<xL||L>xR)
			return 0;
		if (xL<=L&&R<=xR)
			return Max[rt];
		int mid=(L+R)>>1;
		return max(query(ls[rt],L,mid,xL,xR),query(rs[rt],mid+1,R,xL,xR));
	}
}
int res[N];
int c[N],x[N];
int pre[N],nxt[N],cnt[N];
bool cmp(int i,int j){
	return x[i]!=x[j]?x[i]<x[j]:i<j;
}
void add(int x,int d){
	for (;x<=hs;x+=x&-x)
		c[x]=cmp(c[x],d)?d:c[x];
}
int ask(int x){
	int ans=0;
	for (;x;x-=x&-x)	
		ans=cmp(ans,c[x])?c[x]:ans;
	return ans;
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		a[i]=Ha[i]=read();
	hs=n;
	Ha[++hs]=-1e10,Ha[++hs]=1e10;
	sort(Ha+1,Ha+hs+1);
	hs=unique(Ha+1,Ha+hs+1)-Ha-1;
	Seg :: build(Lrt[0],1,hs);
	Rrt[n+1]=Lrt[0];
	for (int i=1;i<=n;i++){
		a[i]=lower_bound(Ha+1,Ha+hs+1,a[i])-Ha;
		int v=Seg :: query(Lrt[i-1],1,hs,1,a[i]-1)+1;
		Seg :: update(Lrt[i],Lrt[i-1],1,hs,a[i],v);
	}
	int Max=0;
	for (int i=n;i>=1;i--){
		int v=Seg :: query(Rrt[i+1],1,hs,a[i]+1,hs)+1;
		Max=max(Max,v);
		Seg :: update(Rrt[i],Rrt[i+1],1,hs,a[i],v);
	}
	memset(c,0,sizeof c);
	memset(x,0,sizeof x);
	memset(cnt,0,sizeof cnt);
	for (int i=1;i<=n;i++){
		pre[i]=ask(a[i]-1);
		x[i]=x[pre[i]]+1;
		add(a[i],i);
	}
	for (int i=ask(hs);i;i=pre[i])
		cnt[i]++;//,printf("%d ",i);puts("");
	memset(c,0,sizeof c);
	memset(x,0,sizeof x);
	for (int i=1;i<=n;i++){
		nxt[i]=ask(hs-a[n-i+1]);
		x[i]=x[nxt[i]]+1;
		add(hs-a[n-i+1]+1,i);
	}
	for (int i=ask(hs);i;i=nxt[i])
		cnt[n-i+1]++;//,printf("%d ",n-i+1);puts("");
	for (int i=1;i<=n;i++)
		if (cnt[i]==2)
			res[i]=Max-1;
		else
			res[i]=Max;
	while (m--){
		int x=read(),y=read();
		int ly=lower_bound(Ha+1,Ha+hs+1,y)-Ha-1;
		int uy=upper_bound(Ha+1,Ha+hs+1,y)-Ha;
		int ans=max(res[x],Seg :: query(Lrt[x-1],1,hs,1,ly)
						+1+Seg :: query(Rrt[x+1],1,hs,uy,hs));
		printf("%d\n",ans);
	}
	return 0;
}
/*
Sample
3 3
2 2 3
1 3
1 1
3 2
ans = 
2
3
1

Test
10 3
1 3 5 7 9 2 4 6 8 10
9 11
2 1
1 10
ans = 
6
6
5


*/