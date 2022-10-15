#include <cstdio>
const int N=110;
int T,n,c,a[N];
template<typename T>T min(T x,T y){return x<y?x:y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&c);int ans=0;
		for(int i=1;i<=100;++i)a[i]=0;
		for(int w,i=1;i<=n;++i)scanf("%d",&w),++a[w];
		for(int i=1;i<=100;++i)ans+=min(a[i],c);
		printf("%d\n",ans);
	}
	return 0;
}