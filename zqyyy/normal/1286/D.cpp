#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e5+7,mod=998244353,inv=828542813;
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)res=1ll*res*a%mod;
	return res;
}
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int n,tot,x[N],v[N],P[N][2];
struct Mat{
	int a[2][2];
	int* operator [](int i){return a[i];}
	Mat(){a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;}
	Mat operator *(Mat q){
		Mat r;
		for(int i=0;i<2;i++)
			for(int k=0;k<2;k++)
				for(int j=0;j<2;j++)
					add(r[i][j],1ll*a[i][k]*q[k][j]%mod);
		return r;
	}
};
struct node{
	int t,i,l,r;
	double T;
	inline void init(int _i,int s,int v,int _l,int _r){
		l=_l,r=_r,i=_i,t=1ll*s*qpow(v,mod-2)%mod,T=1.*s/v;
	}
	bool operator <(const node &q) const {return T<q.T;}
}a[N<<1];
struct Segment_Tree{
	Mat t[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
	inline void upd(int p){t[p]=t[ls]*t[rs];}
	void build(int p,int l,int r){
		if(l==r){t[p][0][0]=t[p][1][0]=P[l][0],t[p][1][1]=t[p][0][1]=P[l][1];return;}
		int mid=(l+r)>>1;build(ls,l,mid),build(rs,mid+1,r),upd(p);
	}
	void modify(int p,int l,int r,int x,int _l,int _r){
		if(l==r){t[p][_l][_r]=0;return;}int mid=(l+r)>>1;
		x<=mid?modify(ls,l,mid,x,_l,_r):modify(rs,mid+1,r,x,_l,_r);upd(p);
	}
	Mat query(int p,int l,int r,int x,int y){
		if(x<=l && r<=y)return t[p];int mid=(l+r)>>1;
		return y<=mid?query(ls,l,mid,x,y):(x>mid?query(rs,mid+1,r,x,y):query(ls,l,mid,x,y)*query(rs,mid+1,r,x,y));
	}
}T;
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read();if(n==1)puts("0"),exit(0);
	for(int i=1;i<=n;i++)x[i]=read(),v[i]=read(),P[i][1]=1ll*read()*inv%mod,P[i][0]=(mod+1-P[i][1])%mod;
	for(int i=2;i<=n;i++){
		a[++tot].init(i,x[i]-x[i-1],v[i-1]+v[i],1,0);
		if(v[i-1]<v[i])a[++tot].init(i,x[i]-x[i-1],v[i]-v[i-1],0,0);
		else if(v[i-1]>v[i])a[++tot].init(i,x[i]-x[i-1],v[i-1]-v[i],1,1);
	}
	sort(a+1,a+tot+1),T.build(1,1,n);int ans=0;
	for(int i=1;i<=tot;i++){
		Mat L=T.query(1,1,n,1,a[i].i-1),R;
		if(a[i].i<n)R=T.query(1,1,n,a[i].i+1,n);
		else R[a[i].r][a[i].r]=1;
		add(ans,1ll*L[0][a[i].l]*P[a[i].i][a[i].r]%mod*(R[a[i].r][0]+R[a[i].r][1])%mod*a[i].t%mod);
		T.modify(1,1,n,a[i].i,a[i].l,a[i].r);
	}
	printf("%d\n",ans);
	return 0;
}