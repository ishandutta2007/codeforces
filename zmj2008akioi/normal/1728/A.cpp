#include <cstdio>
const int N=30;
int T,n,t,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);int t=1;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]>a[t])t=i;
		}
		printf("%d\n",t);
	}
	return 0;
}