#include<bits/stdc++.h>
using namespace std;

int n,m,k,d[1010][1010],inf,sx,sy,tx,ty,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
char s[1010][1010];
struct P{
	int x,y;
}u,v; int tmp;
queue<P>q;

int main(){
	memset(d,33,sizeof d); inf=d[0][0];
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	d[sx][sy]=0;
	for (q.push((P){sx,sy});!q.empty();q.pop()){
		u=q.front();
		if (u.x==tx&&u.y==ty) return 0*printf("%d",d[tx][ty]);
		for (int di=0;di<4;di++){
			for (int i=1;i<=k;i++){
				v=(P){u.x+dx[di]*i,u.y+dy[di]*i};
				if (s[v.x][v.y]!='.'||d[v.x][v.y]<=d[u.x][u.y]) break;
				if (d[v.x][v.y]>d[u.x][u.y]+1){
					d[v.x][v.y]=d[u.x][u.y]+1;
					q.push(v);
				}
			}
		}
	}
	puts("-1");
}