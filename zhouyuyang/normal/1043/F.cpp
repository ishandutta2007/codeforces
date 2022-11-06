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
#define INF (1<<29)
using namespace std;

int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
const int N=300005;
int a[N],b[N],c[N],n;
ll d[N];
int main(){
	int G=0,m=0;
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d",&a[i]);
		G=gcd(G,a[i]);
		m=max(m,a[i]);
		b[a[i]]=c[a[i]]=1;
	}
	if (G!=1)
		return puts("-1"),0;
	int ans=1;
	for (;;ans++){
		if (b[1]) return printf("%d\n",ans),0;
		For(i,1,m){
			int sb=0,sc=0;
			For(j,1,m/i) sb+=b[i*j],sc+=c[i*j];
			d[i]=1ll*sb*sc;
		}
		Rep(i,m,1) For(j,2,m/i) d[i]-=d[i*j];
		For(i,1,m) b[i]=(d[i]>0);
	}
}