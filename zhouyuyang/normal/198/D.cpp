#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
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

#define F1 id[++x1][y1][z1]=++id1
#define B1 id[--x1][y1][z1]=++id1
#define U1 id[x1][++y1][z1]=++id1
#define D1 id[x1][--y1][z1]=++id1
#define R1 id[x1][y1][++z1]=++id1
#define L1 id[x1][y1][--z1]=++id1
#define F2 id[++x2][y2][z2]=--id2
#define B2 id[--x2][y2][z2]=--id2
#define U2 id[x2][++y2][z2]=--id2
#define D2 id[x2][--y2][z2]=--id2
#define R2 id[x2][y2][++z2]=--id2
#define L2 id[x2][y2][--z2]=--id2

int n,x1,x2,y1,y2,z1,z2;
int id[55][55][55],id1,id2;
int main(){
	scanf("%d",&n);
	if (n==1) return puts("1"),0;
	id[x1=2][y1=1][z1=1]=id1=1;
	id[x2=1][y2=1][z2=1]=id2=0;
	U2; R2; D2; R1; U1; L1;
	For(c,2,n-1){
		if (c&1){
			F1;
			For(i,1,c-1) L1;
			D1;
			For(i,1,c){
				For(j,2,c-1) (i&1?D1:U1);
				R1;
			}
			For(i,1,c){
				For(j,1,c-1) (i&1?B1:F1);
				U1;
			}
			For(i,1,c){
				For(j,1,c) (i&1?L1:R1);
				if (i^c) F1;
			}
			
			U2;
			For(i,1,c) R2;
			For(i,1,c) D2;
		}
		else{
			F1;
			For(i,1,c){
				For(j,1,c-1) (i&1?D1:U1);
				R1;
			}
			For(i,1,c){
				For(j,1,c-1) (i&1?D1:U1);
				if (i^c) B1;
			}
			U1;
			For(i,1,c){
				For(j,1,c) (i&1?L1:R1);
				if (i^c) F1;
			}
			
			R2;
			For(i,1,c) U2;
			For(i,1,c) L2;
		}
	}
	For(i,1,n){
		For(j,1,n){
			For(k,1,n) printf("%d ",id[i][j][k]-id2+1);
			puts("");
		}
		puts("");
	}
}