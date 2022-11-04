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
#define SUB(i,j) for (int all=(int)(j+2147483648ll),i=(int)(j);i>=0;i=(i-1)&j) 
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1<<30)
using namespace std;
const int N=500005;
int n,m,a[N],b[N];
priority_queue<pll,vector<pll>,greater<pll> > q;
ll ans;
int solve(int x){
	ans=0; int num=0;
	For(i,1,n){
		q.push(pll(a[i],0));
		ll t=q.top().fi,now=b[i]-x;
		if (now+t<0){
			ans+=now+t; q.pop();
			q.push(pll(-now,1));
		}
	}
	for (;!q.empty();num+=q.top().se,q.pop());
	return num;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	int l=0,r=2e9;
	while (l<=r){
		int mid=(1ll*l+r)/2;
		int num=solve(mid);
		if (num==m) return printf("%lld\n",ans+1ll*m*mid),0;
		num<m?l=mid+1:r=mid-1;
	}
}