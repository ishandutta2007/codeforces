#include<cstdio>
#include<cctype>
#include<vector>
using std::vector;
typedef long long ll;
const ll mo=1000000007;
ll pow(ll x,int y){
	if(!y)return 1;
	ll u=pow(x,y>>1);
	if(y&1)return u*u%mo*x%mo;
		else return u*u%mo;
}
const int N=1000010,M=N,S=N;
ll p[M],x,a[N],xb,n,qq,sz,m,ans[N],mi[S],ji[N],inv[N],pp[M],lst[M];
int i,l,r,j;
unsigned int k;
bool b[S];
struct query{
	int l,id;
};
vector<query> q[N];
struct segtree{
	struct node{
		int l,r,m;
		ll v;
	}a[N<<2];
	void build(int i,int l,int r){
		a[i].l=l;
		a[i].r=r;
		a[i].m=(l+r)>>1;
		a[i].v=1;
		if(l==r)return;
		build(i<<1,l,a[i].m);
		build(i<<1|1,a[i].m+1,r);
	}
	void add(int i,int l,int r,ll x){
		if(a[i].l==l && a[i].r==r){
			a[i].v=a[i].v*x%mo;
			return;
		}
		if(l>a[i].m)add(i<<1|1,l,r,x);
			else if(r<=a[i].m)add(i<<1,l,r,x);
					else{
						add(i<<1,l,a[i].m,x);
						add(i<<1|1,a[i].m+1,r,x);
					}
	}
	inline ll query(int l){
		int i=1;
		ll ans=1;
		for(;a[i].l!=a[i].r;l>a[i].m?i=i<<1|1:i<<=1)
			ans=ans*a[i].v%mo;
		return ans*a[i].v%mo;
	}
}T;
inline int getint(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x;
}
int buf[10];
inline void putint(int x){
	if(!x)putchar('0');
		else{
			int xb=0;
			for(;x;x/=10)buf[++xb]=x%10;
			for(;xb;--xb)putchar(buf[xb]+48);
		}
}
int main(){
	n=getint();
	inv[0]=ji[0]=1;
	for(i=1;i<=n;++i){
		a[i]=getint();
		if(a[i]>m)m=a[i];
		ji[i]=ji[i-1]*a[i]%mo;
		inv[i]=inv[i-1]*pow(a[i],mo-2)%mo;
	}
	qq=getint();
	for(i=1;i<=qq;++i){
		l=getint();
		r=getint();
		q[r].push_back((query){l,i});
	}
	for(i=2;i<=m;++i){
		if(!b[i])p[mi[i]=++xb]=i;
		for(j=1;j<=xb;++j){
			x=p[j]*i;
			if(x>m)break;
			b[x]=1;
			mi[x]=j;
			if(i%p[j]==0)break;
		}
	}
	for(i=1;i<=xb;++i)pp[i]=(p[i]-1)*pow(p[i],mo-2)%mo;
	T.build(1,1,n);
	for(i=1;i<=n;++i){
		x=a[i];
		while(x>1){
			for(j=mi[x];x%p[j]==0;x/=p[j]);
			T.add(1,lst[j]+1,i,pp[j]);
			lst[j]=i;
		}
		for(k=0;k<q[i].size();++k)
			ans[q[i][k].id]=ji[i]*inv[q[i][k].l-1]%mo*T.query(q[i][k].l)%mo;
	}
	for(i=1;i<=qq;++i)putint(ans[i]),putchar('\n');
	return 0;
}