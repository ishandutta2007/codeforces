#include <bits/stdc++.h>
using namespace std;
const int N=2005;
int dx[4]={ 0, 0, 1,-1};
int dy[4]={-1, 1, 0, 0};
int n,m;
char g[N][N];
int head=0,tail=0,x[N*N],y[N*N];
bool flag=1;
void ckadd(int i,int j){
	if (g[i][j]!='.')
		return;
	int cnt=0;
	for (int k=0;k<4;k++)
		if (g[i+dx[k]][j+dy[k]]=='.')
			cnt++;
	if (cnt==1)
		tail++,x[tail]=i,y[tail]=j;
	if (cnt==0)
		flag=0;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%s",g[i]+1);
	for (int i=1;i<=n;i++)
		g[i][0]=g[i][m+1]='*';
	for (int i=1;i<=m;i++)
		g[0][i]=g[n+1][i]='*';
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			ckadd(i,j);
	while (head<tail&&flag){
		head++;
		int i=x[head],j=y[head];
		if (g[i][j]!='.')
			continue;
		int cnt=0;
		for (int k=0;k<4;k++)
			if (g[i+dx[k]][j+dy[k]]=='.'){
				cnt++;
				if (k==0)
					g[i][j]='>',g[i+dx[k]][j+dy[k]]='<';
				if (k==1)
					g[i][j]='<',g[i+dx[k]][j+dy[k]]='>';
				if (k==2)
					g[i][j]='^',g[i+dx[k]][j+dy[k]]='v';
				if (k==3)
					g[i][j]='v',g[i+dx[k]][j+dy[k]]='^';
				for (int t=0;t<4;t++)
					ckadd(i+dx[k]+dx[t],j+dy[k]+dy[t]);
			}
		if (cnt==0)
			flag=0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (g[i][j]=='.')
				flag=0;
	if (!flag)
		puts("Not unique");
	else {
		for (int i=1;i<=n;i++,puts(""))
			for (int j=1;j<=m;j++)
				putchar(g[i][j]);
	}
	return 0;
}