#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=100005;
int n,mod,phi;
int a[N];
vector <int> fenjie(int n){
	static vector <int> ans;
	ans.clear();
	for (int i=2;i*i<=n;i++)
		while (n%i==0)
			n/=i,ans.push_back(i);
	if (n>1)
		ans.push_back(n);
	return ans;
}
void Unique(vector <int> &v){
	sort(v.begin(),v.end());
	int u=unique(v.begin(),v.end())-v.begin();
	while (v.size()>u)
		v.pop_back();
}
int Phi(int n){
	int ans=n;
	for (int i=2;i*i<=n;i++)
		if (n%i==0){
			ans=ans/i*(i-1);
			while (n%i==0)
				n/=i;
		}
	if (n>1)
		ans=ans/n*(n-1);
	return ans;
}
int Pow(int x,int y,int mod=::mod){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
int Inv(int x){
	return Pow(x,phi-1);
}
vector <int> pm;
const int S=40;
int pcnt;
int ti[N<<2][S],val[N<<2],add[N<<2],nad[N<<2];
void pushdown(int rt){
	int ls=rt<<1,rs=ls|1;	
	for (int i=1;i<=pcnt;i++){
		ti[ls][i]+=ti[rt][i];
		ti[rs][i]+=ti[rt][i];
		ti[rt][i]=0;
	}
	val[ls]=(LL)val[ls]*add[rt]%mod;
	val[rs]=(LL)val[rs]*add[rt]%mod;
	add[ls]=(LL)add[ls]*add[rt]%mod;
	add[rs]=(LL)add[rs]*add[rt]%mod;
	add[rt]=1;
	nad[ls]=(LL)nad[ls]*nad[rt]%mod;
	nad[rs]=(LL)nad[rs]*nad[rt]%mod;
	nad[rt]=1;
}
void pushup(int rt){
	val[rt]=(val[rt<<1]+val[rt<<1|1])%mod;
}
void Get(int v,int &ans,int *c){
	for (int i=1;i<=pcnt;i++)
		while (v%pm[i-1]==0)
			v/=pm[i-1],c[i]++;
	ans=v%mod;
}
void build(int rt,int L,int R){
	add[rt]=nad[rt]=1,clr(ti[rt]);
	if (L==R){
		val[rt]=a[L]%mod;
		Get(a[L],nad[rt],ti[rt]);
		return;
	}
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	build(ls,L,mid);
	build(rs,mid+1,R);
	pushup(rt);
}
void update1(int rt,int L,int R,int xL,int xR,int v,int *d,int nv){
	if (R<xL||L>xR)
		return;
	if (xL<=L&&R<=xR){
		for (int i=1;i<=pcnt;i++)
			ti[rt][i]+=d[i];
		val[rt]=(LL)val[rt]*v%mod;
		add[rt]=(LL)add[rt]*v%mod;
		nad[rt]=(LL)nad[rt]*nv%mod;
		return;
	}
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	update1(ls,L,mid,xL,xR,v,d,nv);
	update1(rs,mid+1,R,xL,xR,v,d,nv);
	pushup(rt);
}
int Calc(int v,int *c){
	for (int i=1;i<=pcnt;i++)
		v=(LL)v*Pow(pm[i-1],c[i])%mod;
	return v;
}
void update2(int rt,int L,int R,int x,int v,int *d,int nv){
	if (L==R){
		nad[rt]=(LL)nad[rt]*Inv(nv)%mod;
		for (int i=1;i<=pcnt;i++)
			ti[rt][i]-=d[i];
		val[rt]=Calc(nad[rt],ti[rt]);
		return;
	}
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	if (x<=mid)
		update2(ls,L,mid,x,v,d,nv);
	else
		update2(rs,mid+1,R,x,v,d,nv);
	pushup(rt);
}
int Query(int rt,int L,int R,int xL,int xR){
	if (R<xL||L>xR)
		return 0;
	if (xL<=L&&R<=xR)
		return val[rt];
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	return (Query(ls,L,mid,xL,xR)+Query(rs,mid+1,R,xL,xR))%mod;
}
int main(){
	n=read(),mod=read(),phi=Phi(mod);
	for (int i=1;i<=n;i++)
		a[i]=read();
	pm=fenjie(mod);
	Unique(pm);
	pcnt=pm.size();
	build(1,1,n);
	int q=read();
	while (q--){
		static int cc[S];
		int type=read(),a=read(),b=read();
		clr(cc);
		if (type==1){
			int x=read(),v;
			Get(x,v,cc);
			update1(1,1,n,a,b,x,cc,v);
		}
		else if (type==2){
			int v;
			Get(b,v,cc);
			update2(1,1,n,a,b,cc,v);
		}
		else {
			printf("%d\n",Query(1,1,n,a,b));
		}
	}
	return 0;
}