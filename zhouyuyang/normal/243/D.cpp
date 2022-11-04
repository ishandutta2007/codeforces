#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
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
#define fi first
#define se second
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (100000000)
#define sqr(x) ((x)*(x))
using namespace std;
const int N=1000005;
const int M=N*10;
struct line{
	int k,x,y,v;
}a[N];
bool cmp(line a,line b){
	return a.k<b.k;
}
int n,m,vx,vy,tot;
int x,y,v,rt,sz;
int ls[M],rs[M];
int mx[M],tg[M];
void add(int x,int y){
	int v; scanf("%d",&v);
	if (!v) return;
	int k=INF,l=INF,r=-INF;
	For(i,x-1,x) For(j,y-1,y){
		k=min(k,vx*i+vy*j);
		l=min(l,vy*i-vx*j);
		r=max(r,vy*i-vx*j); 
	}
	a[++tot]=(line){k,l+INF,r-1+INF,v};
}
void change(int &k,int l,int r){
	if (!k) k=++sz;
	if (x<=l&&r<=y){
		tg[k]=max(tg[k],v);
		mx[k]=max(mx[k],v);
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(ls[k],l,mid);
	if (y>mid) change(rs[k],mid+1,r);
	mx[k]=max(tg[k],min(mx[ls[k]],mx[rs[k]]));
}
int ask(int k,int l,int r){
	if (!k||(x<=l&&r<=y)) return mx[k];
	int mid=(l+r)/2,ans=(1<<30);
	if (x<=mid) ans=min(ans,ask(ls[k],l,mid));
	if (y>mid) ans=min(ans,ask(rs[k],mid+1,r));
	return max(ans,tg[k]);
}
ll ans;
int main(){
	scanf("%d%d%d",&n,&vx,&vy);
	For(i,1,n) For(j,1,n) add(i,j);
	sort(a+1,a+tot+1,cmp); sz=rt=1;
	For(i,1,tot){
		x=a[i].x,y=a[i].y,v=a[i].v;
		int k=ask(rt,1,2*INF);
		if (v>k) ans+=v-k;
		change(rt,1,2*INF);
	}
	printf("%lld\n",ans);
}