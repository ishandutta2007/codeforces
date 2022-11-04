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

#define INF (1ll<<60)
#define sqr(x) ((x)*(x))
using namespace std;
const int N=200005;
pii a[N];
int n,k;
vi w;
ll calc(int v){
	int l=LB(a+1,a+n+1,pii(v-1,0))-a;
	int r=LB(a+1,a+n+1,pii(v+1,0))-a-1;
	int must=k-l+1;
	if (must>r-l+1||v>n||v<must) return INF;
	ll ans=0; w.clear();
	For(i,l,r) w.PB(a[i].se);
	sort(w.begin(),w.end(),greater<int>());
	For(i,1,must){
		ans+=w.back();
		w.pop_back(); --v;
	}
	For(i,1,l-1) w.PB(a[i].se);
	For(i,r+1,n) w.PB(a[i].se);
	sort(w.begin(),w.end(),greater<int>());
	For(i,1,v){
		ans+=w.back();
		w.pop_back();
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&k); k=n-k+1;
	For(i,1,n) scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a+1,a+n+1);
	if (!k) return puts("0"),0;
	int s=a[k].fi; ll ans=INF;
	For(i,s-1,s+3) ans=min(ans,calc(i));
	printf("%lld\n",ans==INF?-1:ans); 
}