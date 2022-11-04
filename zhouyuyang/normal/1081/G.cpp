#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
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
 
#define inf 1<<30
#define sqr(x) ((x)*(x))
using namespace std;
const int N=100005;
int inv[N],n,k,mo,ans;
map<int,int> mp;
void get(int n,int k){
	if (k==1||n==1) mp[n]++;
	else get(n/2,k-1),get(n-n/2,k-1); 
}
int calc(int x,int y){
	int ans=1ll*x*y%mo*(mo+1)/2%mo;
	For(i,1,y) ans=(ans+mo+1ll*inv[i]-inv[i+x])%mo;
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&k,&mo); 
	inv[0]=inv[1]=1;
	For(i,2,n) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,n) inv[i]=(inv[i]+inv[i-1])%mo;
	get(n,k);
	for (auto a:mp){
		ans=(ans+1ll*a.fi*(a.fi-1)/2%mo*(mo+1)/2%mo*a.se)%mo;
		if (a.se>=2) ans=(ans+1ll*a.se*(a.se-1)/2%mo*calc(a.fi,a.fi))%mo;
		for (auto b:mp) if (a.fi<b.fi)
			ans=(ans+1ll*calc(a.fi,b.fi)*a.se%mo*b.se)%mo;
	}
	printf("%d",ans);
}