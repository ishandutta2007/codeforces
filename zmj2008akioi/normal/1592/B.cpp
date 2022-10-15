#include <cstdio>
#include <algorithm>
int t,n,x,a[100010],b[100010];
int main(){
	scanf("%d",&t);
	do{
		scanf("%d %d",&n,&x);
		for(register int i=1;i<=n;++i)scanf("%d",&a[i]),b[i]=a[i];
		std::sort(b+1,b+1+n);
		bool tag=true;
		for(register int i=n-x+1;i<=x;++i)if(a[i]!=b[i])tag=false;
		puts(tag?"Yes":"No");
	}while(--t);
	return 0;
}