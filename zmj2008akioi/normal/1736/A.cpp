#include <cstdio>
const int N=110;
int T,n,a[N],b[N];
template<typename T>T rv(T x){return x>T()?x:-x;}
template<typename T>T min(T x,T y){return x<y?x:y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);int sa=0,sb=0,ans1=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),sa+=a[i];
		for(int i=1;i<=n;++i)scanf("%d",&b[i]),sb+=b[i],ans1+=a[i]^b[i];
		printf("%d\n",min(ans1,rv(sa-sb)+1));
	}
	return 0;
}