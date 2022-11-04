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

#define INF (1ll<<30)
#define sqr(x) ((x)*(x))
using namespace std;
const int N=500005;
int n,m,l;
int b[N],h[N];
struct edge{
	int to,next;
}e[N*2];
int head[N],tot;
pii a[N];
int G[N];
bool cmp1(pii a,pii b){
	if (h[a.fi]!=h[b.fi]) return h[a.fi]>h[b.fi];
	if (a.fi!=b.fi) return a.fi<b.fi;
	return h[a.se]>h[b.se];
}
bool cmp2(int x,int y){
	return x>y;
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa,int fi,int se){
	if (h[x]<h[fi]) se=fi,fi=x;
	else if (h[x]<h[se]) se=x;
	a[x]=pii(fi,se);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa) dfs(e[i].to,x,fi,se);
}
void work(int l,int r,int k){
	int ans=0;
	For(i,1,r-l+1){
		int t=0;
		if (i<=*G) t=G[i];
		else if (k+i-*G-1<=m) t=b[k+i-*G-1];
		ans=max(ans,t-h[a[l+i-1].fi]);
		if (t>h[a[l+i-1].se]) return;
	}
	printf("%d\n",ans);
	exit(0);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&h[i]);
	For(i,2,n){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x); 
	}
	scanf("%d",&m);
	For(i,1,m) scanf("%d",&b[i]);
	h[0]=INF;
	dfs(1,0,0,0);
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+m+1,cmp2);
	For(i,1,m) if (h[a[i].fi]<b[i]) l=i;
	for (int i=1,j=1,k=1;i<=n;i=j+1){
		for(j=i;j<n&&a[j+1].fi==a[i].fi;j++);
		if (*G<=j-i+1&&j>=l) work(i,j,k);
		For(t,i,j){
			for (;k<=m&&b[k]>h[a[t].fi];k++) G[++*G]=b[k];
			k++;
		}
	}
	puts("-1");
}