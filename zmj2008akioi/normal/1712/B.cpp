#include <cstdio>
const int N=1e5+10;
int T,n,ans[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=n;i>1;i-=2)ans[i-1]=i,ans[i]=i-1;
		if(n%2==1)ans[1]=1;
		for(int i=1;i<=n;++i)printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}