#include <cstdio>
const int N=110;
int T,n,ans[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans[n-1]=n-1,ans[n]=n;
		if(n%2==0)for(int i=1;i<n-1;++i)ans[i]=((i-1)^1)+1;
		else{
			ans[1]=1,ans[2]=2,ans[3]=3;
			for(int i=4;i<n-1;++i)ans[i]=i^1;
		}
		for(int i=1;i<=n;++i)printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}