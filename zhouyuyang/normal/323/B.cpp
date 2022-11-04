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
using namespace std;

const int N=1005;
int a[N][N],n;

int main(){
	scanf("%d",&n); int nn=n-1+(n&1);
	if (n==4) return puts("-1"),0;
	For(i,1,nn) For(j,1,nn/2) a[i][(i+j-1)%nn+1]=1;
	if (nn!=n) For(i,1,n-1) a[n][i]=i&1,a[i][n]=a[n][i]^1;
	For(i,1,n){For(j,1,n) printf("%d ",a[i][j]); puts("");}
}