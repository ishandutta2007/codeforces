#include<bits/stdc++.h>
using namespace std;
const int N=15,M=2e3+5,S=4099;
int T,n,m,z,i,j,k,l,p,a[N][M],f[N][S],val[S],su[S],g[N],cnt[S];
pair<int,int>b[M];
int main(){
	for(i=1;i<S;++i)cnt[i]=cnt[i>>1]+(i&1);
	for(scanf("%d",&T);T--;){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;++i)for(j=1;j<=m;++j)scanf("%d",a[i]+j);
		for(j=1;j<=m;++j){
			int mx=0;
			for(i=0;i<n;++i)mx=max(mx,a[i][j]);
			b[j]=make_pair(mx,j);
		}
		sort(b+1,b+m+1);
		z=min(m,n);
		for(i=1;i<=z;++i){
			memset(val,0,4<<n);
			for(j=0;j<n;++j){
				for(k=0;k<1<<n;++k){
					int s=0;
					for(l=0,p=j;l<n;++l,++p==n?p=0:0)
						if(k>>l&1)s+=a[p][b[m-i+1].second];
					val[k]=max(val[k],s);
				}
			}
			memcpy(f[i],f[i-1],4<<n);
			for(j=(1<<n)-1;j;--j)for(k=j;k;k=(k-1)&j)f[i][j]=max(f[i][j],f[i-1][j^k]+val[k]);
		}
		int ans=0;
		memset(g,0,sizeof g);
		for(i=1;i<=m-z;++i)g[i]=g[i-1]+b[m-z-i+1].first;
		for(j=0;j<1<<n;++j)ans=max(ans,g[n-cnt[j]]+f[z][j]);
		printf("%d\n",ans);
	}
}