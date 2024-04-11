#include<bits/stdc++.h>
typedef long long ll;
const int N=519;
int K,n,i,j,k,T,x[99],y[99],ans;
ll a[N][N],b[N][N];
int main(){
	scanf("%d",&K);n=1<<K;for(i=0;i<n;++i)for(j=0;j<n;++j)scanf("%lld",a[i]+j);
	scanf("%d",&T);for(i=0;i<T;++i)scanf("%d%d",x+i,y+i),--x[i],--y[i];
	for(;K--;){
		for(i=0;i<n;++i)memset(b[i],0,n<<3);
		for(i=0;i<n;++i)for(j=0;j<n;++j)for(k=0;k<T;++k)b[(i+x[k])&n-1][(j+y[k])&n-1]^=a[i][j];
		for(i=0;i<n;++i)memcpy(a[i],b[i],n<<3);for(i=0;i<T;++i)x[i]=x[i]<<1&(n-1),y[i]=y[i]<<1&n-1;
	}
	for(i=0;i<n;++i)for(j=0;j<n;++j)ans+=a[i][j]>0;printf("%d\n",ans);
	return 0;
}