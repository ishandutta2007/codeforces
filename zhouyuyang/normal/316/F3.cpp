#include<cstdio>
#include<algorithm>
#define rep(i,l,r) for (int i=l; i<=r; ++i)
#define dep(i,r,l) for (int i=r; i>=l; --i)
using namespace std;

const int N=2020;
const int vx[4]={1,-1,0,0};
const int vy[4]={0,0,1,-1};

int n,m,a[N][N],s[N][N],id[N][N],cnt,ans[N*N/100];
bool ry[N][N];

int area(int x1,int y1,int x2,int y2){
	return s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
}
int see(int x,int y){
	return area(x-3,y-3,x+3,y+3);
}
void dfs(int i,int j,int w){
	if (i<1 || i>n || j<1 || j>m || !a[i][j] || id[i][j]) return;
	id[i][j]=w;
	rep(l,0,3) dfs(i+vx[l],j+vy[l],w);
}
void getRay(int i,int j){
	if (i<1 || i>n || j<1 || j>m || !ry[i][j]) return;
	ry[i][j]=0;
	rep(l,0,3) getRay(i+vx[l],j+vy[l]);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n) rep(j,1,m){
		char c=getchar();
		while (c!='1' && c!='0') c=getchar();
		a[i+10][j+10]=c-'0';
	}
	n+=20,m+=20;
	rep(i,1,n) rep(j,1,m){
		s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	}

	rep(i,1,n) rep(j,1,m)
		if (a[i][j] && !id[i][j]){
			dfs(i,j,++cnt);
		}
	rep(i,1,n) rep(j,1,m){
		ry[i][j]=(a[i][j] && see(i,j)<=15);
	}
	rep(i,1,n) rep(j,1,m)
		if (ry[i][j]){
			getRay(i,j);
			ans[id[i][j]]++;
		}

	printf("%d\n",cnt);
	sort(ans+1,ans+cnt+1);
	rep(i,1,cnt) printf("%d ", ans[i]);
}