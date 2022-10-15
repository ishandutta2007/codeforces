#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7,M=2e5+7,mod=1e9+7;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int m,v[N],pr[N];
inline void init(int n){
	m=0;
	for(int i=2;i<=n;i++){
		if(!v[i])v[i]=i,pr[++m]=i;
		for(int j=1;j<=m && 1ll*pr[j]*i<=n;j++){
			v[pr[j]*i]=pr[j];
			if(i%pr[j]==0)break;
		}
	}
}
int n,Q,a[N],lg[N],rt[N<<1],pos[N<<1];
char st[88][N][17];
inline int query(int l,int r){
	int res=1,k=lg[r-l+1];
	for(int i=1;i<=m;i++)
		res=1ll*res*qpow(pr[i],(int)max(st[i][l][k],st[i][r-(1<<k)+1][k]))%mod;
	return res;
}
struct Segment_Tree{
	int tot,ls[N<<6],rs[N<<6],t[N<<6];
	int build(int l,int r){
		int x=++tot;t[x]=1;
		if(l==r)return x;int mid=(l+r)>>1;
		ls[x]=build(l,mid),rs[x]=build(mid+1,r);
		return x;
	}
	void modify(int &p,int q,int l,int r,int x,int y){
		p=++tot,t[p]=1ll*t[q]*y%mod,ls[p]=ls[q],rs[p]=rs[q];
		if(l==r)return;int mid=(l+r)>>1;
		if(x<=mid)modify(ls[p],ls[q],l,mid,x,y);
		else modify(rs[p],rs[q],mid+1,r,x,y);
	}
	int query(int p,int l,int r,int x,int y){
		if(x<=l && r<=y)return t[p];
		int mid=(l+r)>>1,res=1;
		if(x<=mid)res=query(ls[p],l,mid,x,y);
		if(y>mid)res=1ll*res*query(rs[p],mid+1,r,x,y)%mod;
		return res;	
	}
}T;
int main(){
	n=read(),init(sqrt(2e5));
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			while(a[i]%pr[j]==0)st[j][i][0]++,a[i]/=pr[j];
	for(int k=1;k<=m;k++)
		for(int j=1;j<=lg[n];j++)
			for(int i=1;i+(1<<j)-1<=n;i++)
				st[k][i][j]=max(st[k][i][j-1],st[k][i+(1<<j-1)][j-1]);
	rt[0]=T.build(1,n);
	for(int i=1;i<=n;i++){
		T.modify(rt[i],rt[i==1?0:i-1+n],1,n,i,a[i]);
		if(pos[a[i]])T.modify(rt[i+n],rt[i],1,n,pos[a[i]],qpow(a[i],mod-2));
		else rt[i+n]=rt[i];
		pos[a[i]]=i;
	}
	Q=read();int ans=0;
	while(Q--){
		int l=(read()+ans)%n+1,r=(read()+ans)%n+1;
		if(l>r)swap(l,r);
		printf("%d\n",ans=1ll*query(l,r)*T.query(rt[r+n],1,n,l,r)%mod);
	}
	return 0;
}