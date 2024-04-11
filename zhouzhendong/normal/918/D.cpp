#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N=105,M=N*(N-1)/2;
struct gragh{
	int cnt,y[M],z[M],nxt[M],fst[N];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b,int c){
		y[++cnt]=b,z[cnt]=c,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n,m,sg[N][N][26];
int f(int a,int b,int c){
	if (~sg[a][b][c])
		return sg[a][b][c];
	sg[a][b][c]=0;
	for (int i=g.fst[a];i;i=g.nxt[i])
		if (g.z[i]>=c)
			sg[a][b][c]|=f(b,g.y[i],g.z[i])^1;
	return sg[a][b][c];
}
int main(){
	g.clear();
	scanf("%d%d",&n,&m);
	memset(sg,-1,sizeof sg);
	for (int i=1;i<=m;i++){
		int a,b;
		char c[3];
		scanf("%d%d%s",&a,&b,c);
		g.add(a,b,c[0]-'a');
	}
	for (int i=1;i<=n;i++,puts(""))
		for (int j=1;j<=n;j++)
			putchar(f(i,j,0)?'A':'B');
	return 0;
}