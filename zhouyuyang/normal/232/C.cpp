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
int n,nn,T,g[80][4][4];
ll f[80],p[80][4];
int work(int a,int b,int n){
	if (n==-1||p[n][a]==p[n][b]) return 0;
	if (g[n][a][b]) return g[n][a][b];
	int ans;
	if (p[n][a]>f[n-1]) ans=work(a,b,n-2);
	else if (p[n][a]<=f[n-1]&&p[n][b]>f[n-1])
		ans=min(work(0,a,n-1),work(a,3,n-1))+1+work(0,b,n-2);
	else ans=min(work(a,b,n-1),min(work(0,a,n-1)+work(b,3,n-1),work(0,b,n-1)+work(a,3,n-1))+2);
	return g[n][a][b]=ans;
}
int main(){
	scanf("%d%d",&T,&nn);
	f[0]=1; f[1]=2;
	for (n=2;;++n){
		f[n]=f[n-1]+f[n-2];
		if (f[n]>1e16) break;
	}
	n=min(n,nn);
	while (T--){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		if (x>y) swap(x,y);
		Rep(j,n,0){
			p[j][0]=1; p[j][3]=f[j];
			p[j][1]=x; p[j][2]=y;
			if (j&&x>f[j-1]) x-=f[j-1];
			if (j&&y>f[j-1]) y-=f[j-1];
			For(k,0,2) For(l,1,3) g[j][k][l]=0;
			g[j][0][3]=(j+1)/2;
		}
		printf("%d\n",work(1,2,n));
	}
}