#include <bits/stdc++.h>
using namespace std;
const int N=500005*2;
int q,n,fa[N][20],d[N];
int LCA(int x,int y){
	if (d[x]<d[y])
		swap(x,y);
	for (int i=19;i>=0;i--)
		if (d[x]-(1<<i)>=d[y])
			x=fa[x][i];
	if (x==y)
		return x;
	for (int i=19;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int ask(int x,int y){
	return d[x]+d[y]-d[LCA(x,y)]*2;
}
int main(){
	scanf("%d",&q);
	n=4;
	d[1]=0,d[2]=d[3]=d[4]=1;
	fa[2][0]=fa[3][0]=fa[4][0]=1;
	int x=2,y=3,len=2;
	while (q--){
		int a;
		scanf("%d",&a);
		d[n+1]=d[n+2]=d[a]+1;
		fa[n+1][0]=fa[n+2][0]=a;
		for (int i=1;i<20;i++){
			fa[n+1][i]=fa[fa[n+1][i-1]][i-1];
			fa[n+2][i]=fa[fa[n+2][i-1]][i-1];
		}
		n+=2;
		int len1=ask(n,x);
		int len2=ask(n,y);
		if (len1<len2)
			swap(len1,len2),swap(x,y);
		if (len1>len)
			y=n,len=len1;
		printf("%d\n",len);
	}
	return 0;
}