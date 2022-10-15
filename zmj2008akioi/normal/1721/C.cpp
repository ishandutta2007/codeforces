#include <cstdio>
const int N=2e5+10;
int T,n,a[N],b[N],ans[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)scanf("%d",&b[i]);
		for(int p=1,i=1;i<=n;++i){
			while(b[p]<a[i])++p;
			printf("%d ",b[p]-a[i]);
		}
		putchar('\n'),ans[n]=b[n]-a[n];
		for(int p=n,i=n-1;i;--i){
			if(a[i+1]>b[i])p=i;
			ans[i]=b[p]-a[i];
		}
		for(int i=1;i<=n;++i)printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}