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
const int mo=1000000007,N=105;
int c[N][N],f[2][N][N][N];
int n,m,k,ans;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,0,n) c[i][0]=1;
	For(i,1,n) For(j,1,i)
		c[i][j]=min(c[i-1][j-1]+c[i-1][j],k+1);
	For(i,1,n) f[1][i][i][1]=1;
	For(i,2,m){
		CLR(f[i&1],0);
		For(v,1,n) For(re,1,v) For(way,1,k)
			for (int x=re;way*c[x-1][x-re]<=k&&x+v<=n;x++)
				UPD(f[i&1][v+x][x-re][way*c[x-1][x-re]],f[(i&1)^1][v][re][way]);
		For(v,1,n) For(way,1,k)
			UPD(ans,f[i&1][v][0][way]),
			f[i&1][v][0][way]=0;
		For(j,1,n) f[i&1][j][j][1]++;
	}
	printf("%d",ans);
}