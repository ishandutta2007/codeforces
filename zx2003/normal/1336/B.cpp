#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n[3],a[3][N],i,j,k,l;
int main(){
	for(scanf("%d",&T);T--;){
		for(i=0;i<3;++i)scanf("%d",n+i);
		for(i=0;i<3;++i){for(j=0;j<n[i];++j)scanf("%d",a[i]+j);sort(a[i],a[i]+n[i]);}
		long long ans=8e18;
		for(i=0;i<3;++i)for(j=0;j<n[i];++j){
			int x=(i+1)%3,y=(i+2)%3;
			auto doo=[&](int x,int y){
				if(a[x][0]<=a[i][j] && a[i][j]<=a[y][n[y]-1]){
					k=upper_bound(a[x],a[x]+n[x],a[i][j])-a[x]-1;
					l=lower_bound(a[y],a[y]+n[y],a[i][j])-a[y];
					int v1=a[i][j],v2=a[x][k],v3=a[y][l];
					ans=min(ans,1ll*(v1-v2)*(v1-v2)+1ll*(v2-v3)*(v2-v3)+1ll*(v3-v1)*(v3-v1));
				}
			};
			doo(x,y);doo(y,x);
		}
		printf("%lld\n",ans);
	}
}