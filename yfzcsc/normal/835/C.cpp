#include<bits/stdc++.h>
using namespace std;
int n,q,c,a[110][110][11];
int main(){
	scanf("%d%d%d",&n,&q,&c);
	for(int i=1;i<=n;++i){
		int x,y,s;scanf("%d%d%d",&x,&y,&s);
		if(x<=100&&y<=100&&x>=1&&y>=1)a[x][y][s]++;
	}
	for(int i=0;i<=c;++i)
		for(int j=1;j<=100;++j)
			for(int k=1;k<=100;++k)
				a[j][k][i]+=a[j-1][k][i]+a[j][k-1][i]-a[j-1][k-1][i];
	for(int i=1;i<=q;++i){
		int t,x1,y1,x2,y2;
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		int ans=0;
		if(x1>x2)swap(x1,x2);
		if(y1>y2)swap(y1,y2);
		for(int i=0;i<=c;++i){
			int p=a[x2][y2][i]-a[x1-1][y2][i]-a[x2][y1-1][i]+a[x1-1][y1-1][i];
		//	printf("<%d,%d>",p,(i+t)%(c+1));
			ans+=p*((i+t)%(c+1));
		}
		printf("%d\n",ans);
	}
}