#include<bits/stdc++.h>
#define N 500005
using namespace std;
int a[N],b[N],X[N],Y[N];
int las[N],nxt[N],n,m,k,q;
struct Bestyf{
	int f[N],sz[N],r[N];
	int opx[N],opy[N],l;
	void init(int n){
		for (int i=1;i<=n;i++)
			f[i]=i,sz[i]=1,r[i]=0;
	}
	void merge(int x,int y,int d){
		if (sz[x]>sz[y]) swap(x,y);
		opx[++l]=x; opy[l]=y;
		f[x]=y; sz[y]+=sz[x]; r[x]=d;
	}
	void recall(){
		int x=opx[l],y=opy[l]; l--;
		f[x]=x; sz[y]-=sz[x]; r[x]=0;
	}
	int find(int x,int &r0){
		if (f[x]==x) return x;
		else return (r0^=r[x]),find(f[x],r0);
	}
}s[51];
int co[N];
vector<int> c[1050000];
vector<int> rc[1050000];
void add(int k,int l,int r,int x,int y,int v){
	if (x>y) return;
	if (l==x&&r==y){
		c[k].push_back(v);
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) add(k*2,l,mid,x,y,v);
	else if (x>mid) add(k*2+1,mid+1,r,x,y,v);
	else add(k*2,l,mid,x,mid,v),
		 add(k*2+1,mid+1,r,mid+1,y,v);
}
void work(int x,int l,int r){
	for (int i=0;i<c[x].size();i++){
		int e=c[x][i],ru=0,rv=0;
		int fu=s[co[e]].find(a[e],ru);
		int fv=s[co[e]].find(b[e],rv);
		if (fu!=fv){
			s[co[e]].merge(fu,fv,ru^rv^1);
			rc[x].push_back(co[e]);
		}
	}
	if (l==r){
		int e=X[l],c=Y[l],u=a[e],v=b[e];
		int ru=0,fu=s[c].find(u,ru);
		int rv=0,fv=s[c].find(v,rv);
		if (fu!=fv||ru!=rv){
			co[e]=c; puts("YES");
			add(1,1,q,l+1,nxt[l]-1,e);
		}
		else{
			if (co[e]) add(1,1,q,l+1,nxt[l]-1,e);
			puts("NO");
		}
	}
	else{
		int mid=(l+r)/2;
		work(x*2,l,mid);
		work(x*2+1,mid+1,r);
	}
	for (int i=0;i<rc[x].size();i++)
		s[rc[x][i]].recall();
	c[x].resize(0);
	rc[x].resize(0);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for (int i=1;i<=k;i++)
		s[i].init(n);
	for (int i=1;i<=m;i++)
		scanf("%d%d",&a[i],&b[i]);
	for (int i=1;i<=q;i++){
		scanf("%d%d",&X[i],&Y[i]);
		nxt[las[X[i]]]=i;
		las[X[i]]=i;
	}
	for (int i=1;i<=q;i++)
		if (!nxt[i]) nxt[i]=q+1;
	work(1,1,q);
}