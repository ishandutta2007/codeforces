#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m1,m2;
struct LBC{
	int n,m,nn,sol,c[N];
	bitset<N> e[N];
	void color(int x){
		if (c[x]!=-1) return;
		c[x]=1; c[x^1]=0;
		for (int i=0;i<nn;i++)
			if (e[x][i]) color(i);
	}
	void init(int _n,int _m){
		n=_n; m=_m; nn=n<<1;
		for (int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x=(x>0?(x-1)*2+1:(-x-1)*2);
			y=(y>0?(y-1)*2+1:(-y-1)*2);
			e[x^1][y]=e[y^1][x]=1;
		}
		for (int i=0;i<nn;i++) e[i][i]=1;
		for (int k=0;k<nn;k++)
			for (int i=0;i<nn;i++)
				if (e[i][k]) e[i]|=e[k];
		sol=1;
		for (int i=0;i<nn;i++)
			if (e[i][i^1]&&e[i^1][i])
				sol=0;
		if (sol){
			for (int i=0;i<nn;i++) c[i]=-1;
			for (int i=0;i<nn;i++)
				if (e[i][i^1]) color(i^1);
		}
	}
	void solve(int c1=-1,int c2=-1){
		if (~c1) color(c1);
		if (~c2) color(c2);
		for (int i=0;i<nn;i++)
			if (c[i]==-1) color(i);
		for (int i=0;i<n;i++)
			putchar(1-c[i<<1]+'0'),putchar(' ');
	}
}f,g;
bool solve(LBC &f,LBC &g){
	if (!f.sol) return 0;
	if (!g.sol) return f.solve(),1;
	for (int i=0;i<n*2;i++)
		if (f.c[i]&&!g.c[i])
			return f.solve(i),1;
	for (int i=0;i<n*2;i++)
		if (f.c[i]==-1)
			for (int j=i;j<n*2;j++)
				if (f.c[j]==-1)
					if (!f.e[i][j]&&g.e[i][j])
						return f.solve(i,j^1),1;
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&m1,&m2);
	f.init(n,m1);
	g.init(n,m2);
	if (!solve(f,g)&&!solve(g,f))
		puts("SIMILAR");
}