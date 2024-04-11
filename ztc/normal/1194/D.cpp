#include<stdio.h>
long long t,n,k;
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		if(k%3!=0||n<k)printf("%s\n",n%3?"Alice":"Bob");
		else printf("%s\n",(n%((k+1)*3)>=k*3)||(n-(((n%((k+1)*3))/k)%3))%3?"Alice":"Bob");
	}
}