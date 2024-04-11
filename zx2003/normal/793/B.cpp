#include<bits/stdc++.h>
const int N=1e3+5,f1[4]={1,0,-1,0},f2[4]={0,1,0,-1};
int n,m,i,j,dd[N][N][4],x,y,xx,yy;
char c[N][N];
struct state{int x,y,d,s;};
std::queue<state>q;
inline void tryins(int x,int y,int d,int s){
	if(x<1 || x>n || y<1 || y>m || s>=dd[x][y][d] || c[x][y]=='*')return;
	dd[x][y][d]=s;q.push((state){x,y,d,s});
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)for(scanf("%s",c[i]+1),j=1;j<=m;++j){
		if(c[i][j]=='S')x=i,y=j;
		if(c[i][j]=='T')xx=i,yy=j;
	}
	memset(dd,10,sizeof dd);
	for(i=0;i<4;++i)tryins(x,y,i,0);
	for(;!q.empty();){
		state u=q.front();q.pop();
		tryins(u.x+f1[u.d],u.y+f2[u.d],u.d,u.s);
		tryins(u.x,u.y,(u.d+1)&3,u.s+1);
		tryins(u.x,u.y,(u.d+3)&3,u.s+1);
	}
	for(i=0;i<4;++i)if(dd[xx][yy][i]<=2)break;
	puts(i<4?"YES":"NO");
	return 0;
}