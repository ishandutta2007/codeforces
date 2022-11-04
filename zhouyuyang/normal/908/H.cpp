#include<bits/stdc++.h>
using namespace std;
int n,f[50],sz[50];
char g[50][50];
int cc[50],p[50],tot;
int id[50],G[50][50];
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=n;i++){
		scanf("%s",g[i]+1);
		for (int j=1;j<=n;j++)
			if (g[i][j]=='A')
				f[get(i)]=get(j);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (g[i][j]=='X'&&get(i)==get(j))
				return puts("-1"),0;
	for (int i=1;i<=n;i++)
		sz[get(i)]++;
	int ret=n-1;
	for (int i=1;i<=n;i++)
		if (get(i)==i&&sz[i]!=1) id[i]=++tot;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (g[i][j]=='X'&&sz[get(i)]!=1&&sz[get(j)]!=1)
				G[id[get(i)]][id[get(j)]]=1;
	for (int i=1;i<=tot;i++) p[i]=i;
	int mcol=tot;
	for (int T=1;T<=1000;T++){
		random_shuffle(p+1,p+tot+1);
		int col=1;
		for (int i=2;i<=tot;i++){
			int S=0;
			for (int j=1;j<i;j++)
				if (G[p[j]][p[i]])
					S|=(1<<cc[j]);
			S^=(1<<col)-1;
			if (S==0) cc[i]=col++;
			else for(;;){
				cc[i]=rand()%(col+1);
				if (S&(1<<cc[i])) break;
			}
			if (col>=mcol) break;
		}
		mcol=min(mcol,col);
	}
	printf("%d\n",ret+mcol);
}