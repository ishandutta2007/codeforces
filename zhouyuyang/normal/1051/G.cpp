#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1<<29)
using namespace std;
const int N=400005,M=5000005;
int rt[N],ls[M],rs[M],sz[M],nd;
ll S[M],t[M];
void pushup(int k){
	S[k]=S[ls[k]]+S[rs[k]];
	sz[k]=sz[ls[k]]+sz[rs[k]];
	t[k]=t[ls[k]]+t[rs[k]]+sz[rs[k]]*S[ls[k]];
}
void insert(int &k,int l,int r,int p,int v){
	if (!k) k=++nd;
	if (l==r){
		t[k]=S[k]=v; sz[k]=1;
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[k],l,mid,p,v);
	else insert(rs[k],mid+1,r,p,v);
	pushup(k); 
}
int merge(int x,int y){
	if (!x||!y) return x|y;
	ls[x]=merge(ls[x],ls[y]);
	rs[x]=merge(rs[x],rs[y]);
	if (ls[x]||rs[x]) pushup(x);
	else{
		t[x]+=t[y]+S[y]*sz[x];
		S[x]+=S[y]; sz[x]+=sz[y];
	}
	return x;
}
ll F(int x){
	return t[rt[x]]+(x-1)*S[rt[x]];
}
int fa[N],a[N],b[N],n;
ll ans[N],res;
bool vis[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void Merge(int x,int y){
	fa[y=get(y)]=x=get(x);
	res-=F(x)+F(y);
	rt[x]=merge(rt[x],rt[y]);
	res+=F(x);
}
int main(){
	scanf("%d",&n);
	For(i,1,N-1) fa[i]=i;
	For(i,1,n){
		scanf("%d%d",&a[i],&b[i]);
		ans[i]=ans[i-1]+1ll*a[i]*b[i];
		a[i]=get(a[i]); fa[a[i]]=a[i]+1;
		insert(rt[a[i]],1,N-1,b[i],b[i]);
	}
	For(i,1,N-1) fa[i]=i;
	For(i,1,n){
		res+=F(a[i]);
		if (vis[a[i]+1]) Merge(a[i],a[i]+1);
		if (vis[a[i]-1]) Merge(a[i]-1,a[i]);
		vis[a[i]]=1;
		printf("%lld\n",res-ans[i]);
	} 
}