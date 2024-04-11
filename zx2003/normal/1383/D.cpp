#include<bits/stdc++.h>
using namespace std;
const int N=255;
int n,m,i,j,x,y,a[N][N],b[N][N],rk1[N],rk2[N],mx1[N],mx2[N],p1,p2,px[N*N],py[N*N];
int irk1[N],irk2[N];
priority_queue<pair<int,pair<int,int>>>q;
inline void tryins(int u,int v){
	if(1<=u && u<=x && 1<=v && v<=y && !b[u][v]){
		int d=(bool)b[u-1][v]+(bool)b[u][v+1]+(bool)b[u+1][v]+(bool)b[u][v-1];
		if(d==2)q.push({min(mx1[rk1[u]],mx2[rk2[v]]),{u,v}});
	}
}
inline void ck(int u,int v){
	tryins(u-1,v);tryins(u,v+1);tryins(u+1,v);tryins(u,v-1);
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j){
		scanf("%d",a[i]+j);
		px[a[i][j]]=i;py[a[i][j]]=j;
		mx1[i]=max(mx1[i],a[i][j]);mx2[j]=max(mx2[j],a[i][j]);
	}
	for(i=1;i<=n;++i)rk1[i]=i;sort(rk1+1,rk1+n+1,[&](int x,int y){return mx1[x]>mx1[y];});
	for(i=1;i<=m;++i)rk2[i]=i;sort(rk2+1,rk2+m+1,[&](int x,int y){return mx2[x]>mx2[y];});
	for(i=1;i<=n;++i)irk1[rk1[i]]=i;
	for(i=1;i<=m;++i)irk2[rk2[i]]=i;
	p1=p2=1;
	for(i=n*m;i;--i){
		if(i==mx1[rk1[p1]] && i==mx2[rk2[p2]]){
			b[++x][++y]=i;++p1;++p2;
			ck(x,y);
		}else if(i==mx1[rk1[p1]]){
			b[++x][y]=i;++p1;
			ck(x,y);
		}else if(i==mx2[rk2[p2]]){
			b[x][++y]=i;++p2;
			ck(x,y);
		}else{
			int x,y;tie(x,y)=q.top().second;q.pop();b[x][y]=i;
			ck(x,y);
		}
//printf("%d\n",i);
//for(int i=1;i<=n;++i,puts(""))for(int j=1;j<=m;++j)printf("%d ",b[i][j]);
	}
	for(i=1;i<=n;++i,puts(""))for(j=1;j<=m;++j)printf("%d ",b[i][j]);
}