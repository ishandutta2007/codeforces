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

const int M=5555;
const int N=205;
int col[2][M][N];
void dfs(int p,int x,int y,int c0,int c1){
	int t=col[p^1][y][c0];
	col[p][x][c0]=y;
	col[p^1][y][c0]=x;
	if (!t){
		col[p^1][y][c1]=0;
		return;
	}
	dfs(p^1,y,t,c1,c0);
}

int n,m,k,s;
int sz[2][N],id[2][N];
int Id[M][M],ans[M];
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&s);
	if (s==1){
		puts("0");
		For(i,1,k) printf("1 ");
		return 0;
	}
	int nd=0,mx=0;
	For(i,1,n) sz[0][i]=s;
	For(i,1,m) sz[1][i]=s;
	For(i,1,k){
		int x,y;
		scanf("%d%d",&x,&y);
		if (sz[0][x]==s)
			sz[0][x]=0,id[0][x]=++nd;
		sz[0][x]++; x=id[0][x];
		if (sz[1][y]==s)
			sz[1][y]=0,id[1][y]=++nd;
		sz[1][y]++; y=id[1][y];
		
		Id[x][y]=i;
		
		int c0=1,c1=1;
		for (;col[0][x][c0];c0++);
		for (;col[1][y][c1];c1++);
		mx=max(mx,max(c0,c1));
		if (c0==c1){
			col[0][x][c0]=y;
			col[1][y][c0]=x;
		}
		else dfs(0,x,y,c0,c1);
	}
	
	int mn=0;
	For(i,1,n) mn+=(sz[0][i]!=s);
	For(i,1,m) mn+=(sz[1][i]!=s);
	printf("%d\n",mn);
	
	For(i,1,nd) For(j,1,mx)
		if (col[0][i][j])
			ans[Id[i][col[0][i][j]]]=j;
	
	For(i,1,k) printf("%d ",ans[i]);
}