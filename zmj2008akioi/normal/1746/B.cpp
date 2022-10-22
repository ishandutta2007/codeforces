#include <cstdio>
const int N=1e5+10;
int T,n,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);int s=0,ans=0;
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),s+=a[i]^1;
		for(int i=1;i<=s;++i)ans+=a[i];
		printf("%d\n",ans);
	}
	return 0;
}