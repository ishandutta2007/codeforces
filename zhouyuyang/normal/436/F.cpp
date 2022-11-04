#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
#define INF (1ll<<60)
using namespace std;
const int N=200005,BLK=300;
ll ans,F[N];
int n,w,cntblk,at;
int g[N],t[N],now[N],cnt[N];
struct node{
	int x,y;
}a[N];
bool cmp(node a,node b){
	return a.y<b.y;
}
bool chk(int x,int y,int z){
	return 1ll*(z-x)*(F[y]-F[x])<=1ll*(y-x)*(F[z]-F[x]); 
}
ll f(int x,int y){
	return 1ll*x*y+F[x];
}
void upd(int x){
	for (;now[x]+1<=cnt[x]&&f(g[now[x]],t[x])<f(g[now[x]+1],t[x]);now[x]++);
}
void init(int x){
	int l=(x-1)*BLK+1,r=x*BLK; cnt[x]=l-1;
	For(i,l,r){
		for (;cnt[x]>l&&chk(g[cnt[x]-1],g[cnt[x]],i);cnt[x]--);
		g[++cnt[x]]=i;
	}
	now[x]=l; upd(x);
}
void change(int pos){
	int x=1;
	for (;x<cntblk&&x*BLK<=pos;x++) t[x]++,upd(x);
	For(i,(x-1)*BLK+1,pos) F[i]+=i;
	init(x);
}
int main(){
	scanf("%d%d",&n,&w);
	For(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	cntblk=100000/BLK+1;
	For(i,1,cntblk) init(i);
	for (int c=0,i=1;i<=n;c++){
		printf("%lld %d\n",1ll*(n-i+1)*c*w+ans,at);
		for (;i<=n&&a[i].y==c;i++) change(a[i].x);
		ans=at=0;
		For(j,1,cntblk){
			ll res=f(g[now[j]],t[j]);
			if (res>ans) ans=res,at=g[now[j]];
		} 
	}
	printf("%lld %d\n",ans,at);
}