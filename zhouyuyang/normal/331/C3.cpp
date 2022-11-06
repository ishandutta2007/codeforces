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

#define INF (1ll<<61)
#define sqr(x) (1ll*(x)*(x))
using namespace std;

map<pll,pll > mp;
ll n;
pll dfs(pll t){
	if (t.se<10) return pll(t.fi||t.se,t.se-max(t.se,t.fi));
	if (mp.find(t)!=mp.end()) return mp[t];
	ll t1,t2; pll res;
	for (t2=1;t2<=t.se/10;t2*=10);
	res=dfs(pll(max(t.fi,t.se/t2),t.se%t2)),t1=res.fi;
	res=dfs(pll(t.fi,t.se/t2*t2+res.se));
	return mp[t]=pll(t1+res.fi,res.se);
}
int main(){
	scanf("%lld",&n);
	printf("%lld\n",dfs(pll(0,n)).fi);
}