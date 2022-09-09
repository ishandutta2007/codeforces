#include<cstdio>
int x,a,n,i;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a);
		x+=a&1;
	}
	puts(x?"First":"Second");
	return 0;
}