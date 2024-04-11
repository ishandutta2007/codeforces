#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=2010;
const int inf=1e9;
int n,m,s,t,x,y,d[N][N];
char S[N][N];
queue<pii>Q;
int ins(int x,int y,int dis){
	if(x<1||x>n||y<1||y>m||d[x][y]<=dis)return -1;
	if(S[x][y]=='*')return -1;
	Q.push(pii(x,y)),d[x][y]=dis;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d",&s,&t,&x,&y);
	for(int i=1;i<=n;++i)
		scanf("%s",S[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			d[i][j]=inf;
	Q.push(pii(s,t)),d[s][t]=0;
	while(Q.size()){
		pii p=Q.front();
		Q.pop();
		int x=p.first,y=p.second,dis=d[x][y];
		ins(x-1,y,dis);
		ins(x+1,y,dis);
		ins(x,y-1,dis+1);
		ins(x,y+1,dis+1);
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)if(S[i][j]!='*'&&d[i][j]!=inf){
			int A=t-j;
			if(d[i][j]<=2*y+A&&d[i][j]<=2*x-A)
				ans++;
		}
	printf("%d",ans);
}