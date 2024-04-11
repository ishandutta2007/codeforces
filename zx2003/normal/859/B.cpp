#include<cstdio>
int n,i,x,ans;
int main(){
	scanf("%d",&n);ans=1<<30;
	for(i=1;i<=n;++i){
		x=(n-1)/i+1;
		if((x+i)<<1<ans)ans=(x+i)<<1;
	}
	printf("%d\n",ans);
	return 0;
}