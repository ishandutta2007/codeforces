#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
bitset<4096>bs[maxn];
int n,m,q,tp,a[15][maxn];
int main(){
	scanf("%d%d%d",&n,&m,&q);
	tp=m;
	for(int i=1;i<=m;++i)
		for(int j=0;j<(1<<m);++j)
			bs[i][j]=j>>i-1&1;
	for(int i=1;i<=m;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	for(int i=1,op,x,y;i<=q;++i){
		scanf("%d%d%d",&op,&x,&y);
		int ans=-1000000007;
		if(op==1)bs[++tp]=bs[x]|bs[y];
		else if(op==2)bs[++tp]=bs[x]&bs[y];
		else for(int i=1;i<=m;++i){
			int s=0;
			for(int j=1;j<=m;++j)s|=(a[j][y]>=a[i][y])<<j-1;
			if(bs[x][s])ans=max(ans,a[i][y]);
		}
		if(op==3)printf("%d\n",ans);
	}
}