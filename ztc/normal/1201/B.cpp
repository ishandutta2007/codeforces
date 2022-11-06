#include<stdio.h>
long long cnt=0,a,b=0,n;
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);
		if(a>b)b=a;
		cnt+=a;
	}printf("%s",(cnt&1)||b<<1>cnt?"NO":"YES");
}