#include <cstdio>
#include <algorithm>
int t,n,a[110],b[110];
bool tag;
int main(){
	scanf("%d",&t);
	do{
		scanf("%d",&n),tag=true;
		for(register int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(register int i=1;i<=n;++i)scanf("%d",&b[i]);
		std::sort(a+1,a+1+n),std::sort(b+1,b+1+n);
		for(register int i=1;i<=n;++i)if(b[i]!=a[i]&&b[i]!=a[i]+1)tag=false;
		puts(tag?"Yes":"No");
	}while(--t);
	return 0;
}