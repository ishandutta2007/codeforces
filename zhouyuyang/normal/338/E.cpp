#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define PQ priority_queue
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

#define For(i,j,k) for (int i=(j);i<=(int)k;i++)
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i++)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1ll<<61)
#define sqr(x) (1ll*(x)*(x))
using namespace std;

const int N=525000;
int tg[N],mn[N],ans;
int a[N],b[N],n,m,h;
void add(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		tg[k]+=v,mn[k]+=v;
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) add(k*2,l,mid,x,y,v);
	else if (x>mid) add(k*2+1,mid+1,r,x,y,v);
	else add(k*2,l,mid,x,mid,v),add(k*2+1,mid+1,r,mid+1,y,v);
	mn[k]=min(mn[k*2],mn[k*2+1])+tg[k];
}
int main(){
	scanf("%d%d%d",&n,&m,&h);
	For(i,1,m) scanf("%d",&b[i]),b[i]=h-b[i];
	sort(b+1,b+m+1);
	For(i,1,n){
		scanf("%d",&a[i]);
		a[i]=lower_bound(b+1,b+m+1,a[i]+1)-b-1;
	}
	For(i,1,m) add(1,1,m,i,i,-m-1+i);
	For(i,1,n){
		if (i>m&&a[i-m]!=0) add(1,1,m,1,a[i-m],-1);
		if (a[i]) add(1,1,m,1,a[i],1);
		if (i>=m) ans+=(mn[1]>=0);
	}
	printf("%d\n",ans);
}