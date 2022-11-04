#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
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

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int N=5005;
int Mn(int &x,int y){
	x>y?x=y:233;
}
int n,a[N],ans[N];
int f[2][N][2][2];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	memset(f,60,sizeof(f));
	f[0][0][0][0]=0; int c=0;
	f[0][0][0][1]=0;
	For(i,1,n){
		c^=1; CLR(f[c],60);
		For(j,0,i/2)
			For(las,0,1) For(now,0,1-las){
				int val=f[c^1][j][las][now];
				For(pre,0,1-now){
					int v=a[i];
					if (pre) v=min(v,a[i+1]-1);
					if (las) v=min(v,a[i-1]-1);
					Mn(f[c][j+now][now][pre],val+a[i]-v);
				}
			}
	}
	memset(ans,60,sizeof(ans));
	For(i,1,(n+1)/2) For(now,0,1)
		Mn(ans[i],f[c][i][now][0]);
	Rep(i,(n+1)/2,1) ans[i]=min(ans[i],ans[i+1]);
	For(i,1,(n+1)/2) printf("%d ",ans[i]);
}
//tr[