#include <cstdio>
const int N=1e6+10;
int T,n,a[N],h[N];
long long ans,pre[N],suf[N];
inline int max(int x,int y){return x>y?x:y;}
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)h[i]=max(0,max(a[i-1],a[i+1])+1-a[i]);
		if(n&1){
			ans=0;
			for(int i=2;i<=n;i+=2)ans+=h[i];
			printf("%lld\n",ans);
		}
		else{
			pre[0]=suf[n+1]=0,ans=1e18;
			for(int i=2;i<n;i+=2)pre[i]=pre[i-2]+h[i];
			for(int i=n-1;i>1;i-=2)suf[i]=suf[i+2]+h[i];
			for(int i=0;i<n;i+=2)cmin(ans,pre[i]+suf[i+3]);
			printf("%lld\n",ans);
		}
	}
	return 0;
}