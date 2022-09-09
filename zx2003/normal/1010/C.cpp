#include<cstdio> 
int n,k,a,i,d;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	scanf("%d%d",&n,&k);
	d=k;
	for(i=1;i<=n;++i){
		scanf("%d",&a);
		d=gcd(d,gcd(a,k));
	}
	printf("%d\n",k/d);
	for(i=0;i<k;i+=d)printf("%d ",i);
	return 0;
}