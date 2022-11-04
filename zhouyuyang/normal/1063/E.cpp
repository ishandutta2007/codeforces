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
const int N=1005;
char ans[N][N];
int n,a[N];
int main(){
	scanf("%d",&n);
	For(i,1,n) For(j,1,n) ans[i][j]='.';
	bool fl=1;
	For(i,1,n){
		int x;
		scanf("%d",&x);
		if (x!=i) fl=0;
		a[x]=i;
	}
	if (fl){
		printf("%d\n",n);
		For(i,1,n){
			For(j,1,n) putchar('.');
			puts("");
		}
		return 0;
	}
	a[1]=-1;
	printf("%d\n",n-1);
	For(h,1,n){
		int dl=-1,dr=-1;
		For(i,1,n) if (a[i]!=i){dl=i; break;}
		Rep(i,n,1) if (a[i]!=i){dr=i; break;}
		if (dl==dr){}
		else if (a[dl]==-1){
			int t=a[dr];
			ans[h][dl]=ans[h][dr]=ans[h][t]='/';
			a[dl]=a[t]; a[t]=a[dr]; a[dr]=-1;
		}
		else{
			int t=a[dl];
			ans[h][dr]=ans[h][dl]=ans[h][t]='\\';
			a[dr]=a[t]; a[t]=a[dl]; a[dl]=-1;
		}
		printf("%s\n",ans[h]+1);
	}
}