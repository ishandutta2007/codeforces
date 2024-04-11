#include <cstdio>
const int N=110;
int T,n,a[N];
void swp(int &x,int &y){x^=y^=x^=y;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",n);
		for(int i=1;i<=n;++i)printf("%d ",a[i]=i);
		putchar('\n');
		for(int i=2;i<=n;++i){
			swp(a[1],a[i]);
			for(int i=1;i<=n;++i)printf("%d ",a[i]);
			putchar('\n');
		}
	}
	return 0;
}