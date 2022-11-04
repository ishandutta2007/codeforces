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
#define INF (1ll<<60)
using namespace std;
int n,m,s;
ll vis[100005];
ll t;
int main(){
	scanf("%d%d%d%lld",&n,&m,&s,&t);
	--s;
	for (;t%n;t--)
		if (s<m) s=(s+t)%n;
		else s=(s-t%n+n)%n;
	memset(vis,-1,sizeof(vis));
	vis[s]=(t/=n);
	while (t--){
		for (int i=n-1;i>=0;i--)
			if (s<m) s=(s+i)%n;
			else s=(s+n-i)%n;
		if (vis[s]!=-1) t%=vis[s]-t;
		vis[s]=t;
	}
	printf("%d\n",s+1); 
}
/*
g(x)=x^p
h(x)=g(x)*mu
*/