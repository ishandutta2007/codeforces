#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
const int N=400005;
int n,m,q;
vector <int> r[N],c[N];
int fa[N];
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
int vis[N];
int main(){
	n=read(),m=read(),q=read();
	if (q==0){
		printf("%d\n",n+m-1);
		return 0;
	}
	for (int i=1;i<=n;i++)
		r[i].clear();
	for (int i=1;i<=m;i++)
		c[i].clear();
	for (int i=1;i<=q;i++){
		int x=read(),y=read();
		r[x].push_back(y);
		c[y].push_back(x);
	}
	for (int i=1;i<=n+m;i++)
		fa[i]=i;
	for (int i=1;i<=n;i++)
		for (int j=1;j<r[i].size();j++)
			fa[getf(r[i][j]+n)]=getf(r[i][j-1]+n);
	for (int i=1;i<=m;i++)
		for (int j=1;j<c[i].size();j++)
			fa[getf(c[i][j])]=getf(c[i][j-1]);
	memset(vis,0,sizeof vis);
	for (int i=1;i<=n+m;i++)
		vis[getf(i)]++;
	int x=0,y=0,xx=0,yy=0;
	for (int i=1;i<=n;i++){
		if (r[i].size()<1)
			xx++;
		else if (vis[i]>0)
			x++;
	}
	for (int i=n+1;i<=n+m;i++){
		if (c[i-n].size()<1)
			yy++;
		else if (vis[i]>0)
			y++;
	}
	printf("%d",max(x,y)+xx+yy-1);
	return 0;
}