#include <bits/stdc++.h>
using namespace std;
const int N=55;
int n,m,vis[N];
char g[N][N];
void NO(){
	puts("No");
	exit(0);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%s",g[i]+1);
	for (int i=1;i<=n;i++){
		vector <int> r,c;
		r.clear(),c.clear();
		for (int j=1;j<=m;j++)
			if (g[i][j]=='#')
				c.push_back(j);
		if (c.size()<1)
			continue;
		int col=c[0];
		for (int j=i;j<=n;j++)
			if (g[j][col]=='#')
				r.push_back(j);
		int rv=r.size(),cv=c.size();
		for (int a=0;a<rv;a++)
			for (int b=0;b<cv;b++)
				if (g[r[a]][c[b]]!='#')
					NO();
				else
					g[r[a]][c[b]]='.';
		for (int a=0;a<rv;a++)
			for (int b=1;b<=m;b++)
				if (g[r[a]][b]=='#')
					NO();
		for (int a=1;a<=n;a++)
			for (int b=0;b<cv;b++)
				if (g[a][c[b]]=='#')
					NO();
	}
	puts("Yes");
	return 0;
}