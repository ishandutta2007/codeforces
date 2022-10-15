#include <cstdio>
const int N=1e6+10;
int T,n,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==1)puts("2");
		else if(n==2)puts("1");
		else if(n==3)puts("1");
		else if(n==4)puts("2");
		else if(n==5)puts("2");
		else if(n%3==0)printf("%d\n",n/3);
		else printf("%d\n",n/3+1);
	}
	return 0;
}