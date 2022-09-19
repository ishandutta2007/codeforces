int n,m,a;main(){
	scanf("%d%d%d",&n,&m,&a);
	printf("%lld",(m+a-1ll)/a*((n+a-1)/a));
}