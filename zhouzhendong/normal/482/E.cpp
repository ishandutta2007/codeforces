#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=50005;
int n,q;
int p[N];
int fa[N],son[N][2];
LL a[N],vsz[N],vsz2[N],vans[N],ans[N],sz[N],csum[N];
int isroot(int x){
	return son[fa[x]][0]!=x&&son[fa[x]][1]!=x;
}
int wson(int x){
	return son[fa[x]][1]==x;
}
void pushup(int x){
	int ls=son[x][0],rs=son[x][1];
	sz[x]=vsz[x]+sz[ls]+sz[rs];
	csum[x]=vsz[x]*a[x]+csum[ls]+csum[rs];
	ans[x]=ans[ls]+ans[rs]+vans[x]
		+(vsz[x]*vsz[x]-vsz2[x])*a[x]//between different light sons
		+2LL*vsz[x]*sz[rs]*a[x]//between light sons and right sons
		+2LL*csum[ls]*(sz[rs]+vsz[x]);//between left sons and right/light sons
}
void rotate(int x){
	int y=fa[x],z=fa[y],L=wson(x),R=L^1;
	assert(!isroot(x));
	if (!isroot(y))
		son[z][wson(y)]=x;
	fa[x]=z,fa[y]=x,fa[son[x][R]]=y;
	son[y][L]=son[x][R],son[x][R]=y;
	pushup(y),pushup(x);
}
void splay(int x){
	for (int y=fa[x];!isroot(x);rotate(x),y=fa[x])
		if (!isroot(y))
			rotate(wson(x)==wson(y)?y:x);
}
void access(int x){
	int t=0;
	while (x){
		splay(x);
		vsz[x]+=sz[son[x][1]];
		vsz2[x]+=sz[son[x][1]]*sz[son[x][1]];
		vans[x]+=ans[son[x][1]];
		son[x][1]=t;
		vsz[x]-=sz[son[x][1]];
		vsz2[x]-=sz[son[x][1]]*sz[son[x][1]];
		vans[x]-=ans[son[x][1]];
		pushup(x),t=x,x=fa[x];
	}
}
void setfather(int x,int f){
	access(x),access(f),splay(f);
	vsz[f]+=sz[x];
	vsz2[f]+=sz[x]*sz[x];
	vans[f]+=ans[x];
	fa[x]=p[x]=f;
	pushup(f);
}
void cut(int x){
	int f=p[x];
	access(x),access(f),splay(x);
	assert(fa[x]==f&&isroot(x));
	vsz[f]-=sz[x];
	vsz2[f]-=sz[x]*sz[x];
	vans[f]-=ans[x];
	fa[x]=p[x]=0;
	pushup(f);
}
int insubtree(int x,int f){
	access(x),splay(x);
	int y=f;
	while (!isroot(y))
		y=fa[y];
	splay(f);
	return y==x;
}
int main(){
	n=read();
	For(i,2,n)
		p[i]=read();
	For(i,1,n)
		a[i]=read();
	For(i,1,n)
		vsz[i]=sz[i]=1,vsz2[i]=vans[i]=0,ans[i]=csum[i]=a[i];
	For(i,2,n)
		setfather(i,p[i]);
	q=read();
	splay(1);
	printf("%.10lf\n",(double)ans[1]/n/n);
	while (q--){
		char s[5];
		scanf("%s",s);
		if (s[0]=='P'){
			int x=read(),f=read();
			if (insubtree(f,x))
				swap(x,f);
			cut(x);
			setfather(x,f);
		}
		else if (s[0]=='V'){
			int x=read(),v=read();
			access(x),splay(x);
			a[x]=v;
			pushup(x);
		}
		splay(1);
		printf("%.10lf\n",(double)ans[1]/n/n);
	}
	return 0;
}