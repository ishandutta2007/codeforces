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
const int N=12;
int calc(ll x){
	int ans=0;
	for (;x;x/=10)
		ans+=(x%10==4||x%10==7);
	return ans;
}
void Mn(ll &x,ll y){
	(x==-1||x>y)?x=y:0;
}
ll n,k,P[N];
ll f[N][N][2],a[N];
int ans[N];
ll get(ll x,int d){
	memset(f,-1,sizeof(f));
	int t=calc(x)+d;
	memset(a,0,sizeof(a)); int cnt=0;
	for (;x;x/=10) a[cnt++]=x%10;
	f[N-1][0][0]=0;
	Rep(i,N-2,0) For(j,0,t) For(k,0,1){
		ll val=f[i+1][j][k];
		if (val==-1) continue;
		For(s,k?0:a[i],9){
			int y=j+(s==4||s==7);
			if (y<=t) Mn(f[i][y][k||(s>a[i])],val+s*P[i]);
		}
	}
	return f[0][t][1];
}
int main(){
	For(i,P[0]=1,N-1) P[i]=P[i-1]*10;
	scanf("%lld%lld",&n,&k);
	ll m=n+k-1,t=0,b=0;
	for (;k>=10;++b) t+=n%10*P[b],n/=10,m/=10,k/=10;
	For(i,0,m-n) ans[i]=calc(n+i);
	int times=0; 
	for (ll i=get(n,0);;){
		bool fl=0;
		For(j,0,m-n){
			int x=calc(i+j);
			if (x!=ans[j]){
				i=get(i+j,ans[j]-x)-j;
				fl=1; break;
			}
		}
		if (!fl){
			printf("%lld\n",i*P[b]+t);
			break;
		}
	}
}