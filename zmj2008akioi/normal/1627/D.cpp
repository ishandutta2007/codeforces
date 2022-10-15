#include <cstdio>
int n,nw,ans,bkt[1000010];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	scanf("%d",&n);
	for(register int i=1;i<=n;++i)scanf("%d",&nw),++bkt[nw];
	for(register int i=1000000;i;--i){
		if(bkt[i])continue;
		int g=0;
		for(register int j=2*i;j<=1000000;j+=i)if(bkt[j])g=gcd(g,j/i);
		if(g==1)bkt[i]=1,++ans;
	}
	printf("%d",ans);
	return 0;
}