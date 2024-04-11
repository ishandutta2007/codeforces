#include <cstdio>
int n,m,a;
int main(){
	scanf("%d %d %d",&n,&m,&a);
	printf("%lld",((long long)(n-1)/a+1)*((long long)(m-1)/a+1));
	return 0;
}