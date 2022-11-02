#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
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
const int N=400005;
int n,m;
struct Edge{
	int x,y,z;
}e[N];
int fa[N],son[N][2],mx[N],val[N],rev[N],sz[N],sub[N];
int zmax(int a,int b){
	return e[a].z>e[b].z?a:b;
}
int isroot(int x){
	return son[fa[x]][0]!=x&&son[fa[x]][1]!=x;
}
int wson(int x){
	return son[fa[x]][1]==x;
}
void pushup(int x){
	sz[x]=sub[x]+sz[son[x][0]]+sz[son[x][1]];
	mx[x]=zmax(val[x],zmax(mx[son[x][0]],mx[son[x][1]]));
}
void rotate(int x){
	assert(!isroot(x));
	int y=fa[x],z=fa[y],L=wson(x),R=L^1;
	if (!isroot(y))
		son[z][wson(y)]=x;
	fa[y]=x,fa[x]=z,fa[son[x][R]]=y;
	son[y][L]=son[x][R],son[x][R]=y;
	pushup(y),pushup(x);
}
void pushdown(int x){
	if (rev[x]){
		swap(son[x][0],son[x][1]);
		rev[son[x][0]]^=1;
		rev[son[x][1]]^=1;
		rev[x]=0;
	}
}
void pushadd(int x){
	if (!isroot(x))
		pushadd(fa[x]);
	pushdown(x);
}
void splay(int x){
	pushadd(x);
	for (int y=fa[x];!isroot(x);rotate(x),y=fa[x])
		if (!isroot(y))
			rotate(wson(x)==wson(y)?y:x);
}
void access(int x){
	int t=0;
	while (x){
		splay(x);
		sub[x]+=sz[son[x][1]];
		son[x][1]=t;
		sub[x]-=sz[son[x][1]];
		pushup(x);
		t=x;
		x=fa[x];
	}
}
void rever(int x){
	access(x);
	splay(x);
	rev[x]^=1;
}
void link(int x,int y){
	rever(x);
	rever(y);
	fa[x]=y;
	sub[y]+=sz[x];
	pushup(y);
}
void split(int x,int y){
	rever(x);
	access(y);
	splay(y);
}
void cut(int x,int y){
	split(x,y);
	fa[x]=son[y][0]=0;
	pushup(y);
}
struct cmp{
	bool operator () (int a,int b){
		if (e[a].z!=e[b].z)
			return e[a].z>e[b].z;
		return a<b;
	}
};
set <int,cmp> S;
int main(){
	n=read(),m=read();
	For(i,1,m)
		e[i].x=read(),e[i].y=read(),e[i].z=read();
	if (n&1){
		For(i,1,m)
			puts("-1");
		return 0;
	}
	For(i,1,n)
		sz[i]=sub[i]=1;
	int rem=n;
	For(i,1,m){
		int x=e[i].x,y=e[i].y,z=e[i].z;
		rever(x);
		rever(y);
		val[n+i]=mx[n+i]=i;
		if (!fa[x]){
			if ((sz[x]&1)&&(sz[y]&1))
				rem-=2;
			link(x,n+i);
			link(n+i,y);
			S.insert(i);
		}
		else {
			split(x,y);
			int j=mx[y];
			if (e[j].z>z){
				cut(e[j].x,n+j);
				cut(n+j,e[j].y);
				link(x,n+i);
				link(n+i,y);
				S.erase(j);
				S.insert(i);
			}
		}
		if (rem==0){
			while (1){
				int j=*S.begin();
				split(e[j].x,e[j].y);
				splay(n+j);
				if ((~sz[e[j].x]&1)&&(~sz[e[j].y]&1)){
					S.erase(j);
					cut(e[j].x,n+j);
					cut(n+j,e[j].y);
				}
				else 
					break;
			}
		}
		if (rem==0)
			printf("%d\n",e[*S.begin()].z);
		else
			puts("-1");
	}
	return 0;
}