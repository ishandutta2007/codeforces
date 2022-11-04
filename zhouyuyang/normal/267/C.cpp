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

#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;

const int N=105,M=5005;
int n,m,x[M],y[M],w[M];
double f[N],a[N][N];
void gauss(){
	For(i,1,n){
		int j;
		for (j=i;j<=n&&!a[j][i];j++);
		if (j>n) continue;
		if (j!=i) For(k,i,n+1) swap(a[i][k],a[j][k]);
		For(j,i+1,n){
			double t=a[j][i]/a[i][i];
			For(k,i,n+1) a[j][k]-=t*a[i][k];
		}
	}
	Rep(i,n,1){
		For(j,i+1,n) a[i][n+1]-=f[j]*a[i][j];
		if (a[i][i]) f[i]=a[i][n+1]/a[i][i];
	}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		scanf("%d%d%d",&x[i],&y[i],&w[i]);
		if (x[i]!=1&&x[i]!=n) a[x[i]][y[i]]--,a[x[i]][x[i]]++;
		if (y[i]!=1&&y[i]!=n) a[y[i]][x[i]]--,a[y[i]][y[i]]++;
	}
	a[1][1]=a[n][n]=a[n][n+1]=1;
	gauss();
	double mn=1e16,ans;
	For(i,1,m){
		double tmp=f[y[i]]-f[x[i]];
		mn=min(mn,abs(w[i]/tmp));
	}
	if (mn>1e7) mn=0;
	For(i,1,m) if (x[i]==1||y[i]==1)
		ans+=f[y[i]*x[i]]*mn;
	printf("%.7lf\n",ans);
	For(i,1,m)
		printf("%.7lf\n",(f[y[i]]-f[x[i]])*mn);
}