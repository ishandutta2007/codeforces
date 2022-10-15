#include <cstdio>
#include <cctype>
#include <queue>
#include <iostream>
#define re register
#define mp make_pair
#define fi first
#define se second
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int dx[8]={-2,-2,-1,-1,1,1,2,2};
const int dy[8]={-1,1,-2,2,-2,2,-1,1};
int n,m,ans,a[1001][1001];
queue<pair<int,int> >q;
inline void solve(int xx,int yy){
	q.push(mp(xx,yy));a[xx][yy]=1;
	while(!q.empty()){
		int x=q.front().fi,y=q.front().se;q.pop();
		for(re int i=0;i<8;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if(nx<1 || ny<1 || nx>n || ny>m || a[nx][ny]!=-1)continue;
			a[nx][ny]=3-a[x][y],q.push(mp(nx,ny));
		}
	}
	int sum1=0,sum2=0;
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=m;j++)
			if(a[i][j]>0){
				if(a[i][j]==1)sum1++;
				else sum2++;
				a[i][j]=0;
			}
	ans+=max(sum1,sum2);
}
int main(){
	n=read(),m=read();
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=m;j++)
			a[i][j]=-1;
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=m;j++)
			if(a[i][j]==-1)solve(i,j);
	printf("%d\n",ans);
	return 0;
}