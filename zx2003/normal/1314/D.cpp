#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=85;
int n,k,a[N][N],i,j,l,b[N];
ll d[12][N],ans=1ll<<60;
int main(){
	scanf("%d%d",&n,&k);for(i=1;i<=n;++i)for(j=1;j<=n;++j)scanf("%d",a[i]+j);
	mt19937 R(114514^time(0)^((unsigned long long)new char));
	for(;clock()*1.0/CLOCKS_PER_SEC<2.5;){
		for(i=2;i<=n;++i)b[i]=R()&1;
		for(i=1;i<=n;++i)d[0][i]=i==1?0:1ll<<60;
		for(i=1;i<=k;++i){
			for(j=1;j<=n;++j)d[i][j]=1ll<<60;
			for(j=1;j<=n;++j)for(l=1;l<=n;++l)if(j!=l && b[l]==(i&1))d[i][l]=min(d[i][l],d[i-1][j]+a[j][l]);
		}
		ans=min(ans,d[k][1]);
	}
	printf("%lld\n",ans);
}