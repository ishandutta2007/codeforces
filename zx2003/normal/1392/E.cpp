#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=30;
int n,i,j,k,x,y,q;
ll a[N][N],K;
int main(){
	scanf("%d",&n);
	for(i=3;i<=n*2-1;++i,x++)for(j=1;j<=n;++j)for(k=1;k<=n;++k)
		if(j+k==i)a[j][k]=ll(j&1)<<x;
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)printf("%lld%c",a[i][j],j==n?'\n':' ');fflush(stdout);
	for(scanf("%d",&q);q--;){
		scanf("%lld",&K);
		puts("1 1");x=y=1;
		auto solve=[&](){
			int t=K&1;
			for(j=1;j<=n;++j)for(k=1;k<=n;++k){
				if(j+k==i && j==x && (t==(j&1)))
					{printf("%d %d\n",x=j,y=k);return;}
				if(j+k==i && k==y && (t==(j&1)))
					{printf("%d %d\n",x=j,y=k);return;}
			}
		};
		for(i=3;i<=n*2-1;++i,K>>=1)solve();printf("%d %d\n",n,n);fflush(stdout);
	}
}