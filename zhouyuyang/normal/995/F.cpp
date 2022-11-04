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

const int mo=1000000007;
const int N=3005;
int f[N][N];
int n,D;
vi e[N];

void DP(int x){
	For(i,1,n+3) f[x][i]=1;
	For(i,0,e[x].size()-1){
		int to=e[x][i]; DP(to);
		For(j,1,n+3) f[x][j]=1ll*f[x][j]*f[to][j]%mo;
	}
	For(i,1,n+3) UPD(f[x][i],f[x][i-1]);
}
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int inv[N];
void lag(){
	int ans=0;
	inv[1]=1;
	For(i,2,n+3) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,n+3){
		int tmp=1;
		For(j,1,n+3) if (j!=i)
			tmp=1ll*tmp*(mo+D-j)%mo*(i>j?inv[i-j]:mo-inv[j-i])%mo;
		UPD(ans,1ll*tmp*f[1][i]%mo);
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d%d",&n,&D);
	For(i,2,n){
		int x;
		scanf("%d",&x);
		e[x].PB(i);
	}
	DP(1);
	lag();
}