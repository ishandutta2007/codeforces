#include<bits/stdc++.h>
using namespace std;
const int N=3505;
int T,n,m,k,a[N],f[N][N],i,j,l;
int main(){
	scanf("%d",&T);
	for(;T--;){
		scanf("%d%d%d",&n,&m,&k);k=min(k,m-1);
		for(i=1;i<=n;++i)scanf("%d",a+i);
		int ans=0;
		for(i=0;i<=k;++i){
			int mn=1<<30;
			for(j=0;j<=m-1-k;++j)
				mn=min(mn,max(a[j+i+1],a[n-(m-1-j-i)]));
			ans=max(ans,mn);
		}
		printf("%d\n",ans);
	}
	return 0;
}