#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
const int N=200005;
int n,m,Next[N];
int fa[N],son[N][2],size[N],rev[N],Max[N];
void pushup(int x){
	size[x]=size[son[x][0]]+size[son[x][1]]+1;
	Max[x]=max(x%(n+1),max(Max[son[x][0]],Max[son[x][1]]));
}
bool isroot(int x){
	return son[fa[x]][0]!=x&&son[fa[x]][1]!=x;
}
void pushdown(int x){
	if (rev[x]){
		rev[x]=0;
		rev[son[x][0]]^=1;
		rev[son[x][1]]^=1;
		swap(son[x][0],son[x][1]);
	}
}
void pushadd(int x){
	if (!isroot(x))
		pushadd(fa[x]);
	pushdown(x);
}
int wson(int x){
	return son[fa[x]][1]==x;
}
void rotate(int x){
	if (isroot(x))
		return;
	int y=fa[x],z=fa[y],L=son[y][1]==x,R=L^1;
	if (!isroot(y))
		son[z][wson(y)]=x;
	fa[x]=z,fa[y]=x,fa[son[x][R]]=y;
	son[y][L]=son[x][R],son[x][R]=y;
	pushup(y),pushup(x);
}
void splay(int x){
	pushadd(x);
	for (int y=fa[x];!isroot(x);rotate(x),y=fa[x])
		if (!isroot(y))
			rotate((wson(x)^wson(y))?x:y);
}
void access(int x){
	int t=0;
	while (x){
		splay(x);
		son[x][1]=t;
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
	fa[x]=y;
}
void cut(int x,int y){
	rever(x);
	access(y);
	splay(y);
	fa[x]=son[y][0]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&Next[i]);
		fa[i]=Next[i]=min(i+Next[i],n+1);
		size[i]=1;
	}
	size[n+1]=1;
	for (int i=1;i<=n+1;i++)
		Max[i]=i%(n+1);
	memset(rev,0,sizeof rev);
	while (m--){
		int op,a,b;
		scanf("%d",&op);
		if (op==1){
			scanf("%d",&a);
			rever(n+1);
			access(a);
			splay(a);
			printf("%d %d\n",max(a,Max[son[a][0]]),size[son[a][0]]);
		}
		else {
			scanf("%d%d",&a,&b);
			cut(a,Next[a]);
			link(a,Next[a]=min(a+b,n+1));
		}
	}
	return 0;
}