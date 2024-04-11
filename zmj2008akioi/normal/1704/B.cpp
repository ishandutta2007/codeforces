#include <cstdio>
const int inf=1e9,N=2e5+10;
int T,n,x,ans,a[N];
void cmin(int &x,int y){if(x>y)x=y;}
void cmax(int &x,int y){if(x<y)x=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&x);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		int ans=0,mn=inf,mx=-inf;
		for(int i=1;i<=n;++i){
			cmin(mn,a[i]),cmax(mx,a[i]);
			if(mx-mn>(x<<1))++ans,mn=mx=a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}