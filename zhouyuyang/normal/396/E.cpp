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

#define INF (1<<29)
#define sqr(x) ((x)*(x))
using namespace std;
const int N=1000005;
int n,p[N],mn[N];
ll a[N];
void down(int x,ll v){
	a[x]-=v;
	for (x--;x!=1;x/=mn[x]) a[mn[x]]+=v;
}
int main(){
	For(i,2,N-1) if (!mn[i])
		For(j,1,(N-1)/i) if (!mn[i*j]) mn[i*j]=i;
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&p[i]);
		scanf("%lld",&a[p[i]]);
	}
	ll T,mn;
	scanf("%lld",&T);
	mn=min(20ll,T); T-=mn;
	For(j,1,mn) For(i,2,N-1)
		if (a[i]) down(i,1);
	Rep(i,N-1,2) if (a[i])
		down(i,min(a[i],T));
	int cnt=0;
	For(i,2,N-1) if (a[i]) cnt++;
	printf("%d\n",cnt);
	For(i,2,N-1) if (a[i]) printf("%d %lld\n",i,a[i]);
}