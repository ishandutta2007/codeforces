#include<stdio.h>
int a,b=-1,n,t=1000000007,k=0,p,g=1;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		if(a&&i-a>b)b=i-a;
		if(a==1)p=i;
		if(a==k+1)k=a;
		else k=0;
		if(a&&!k&&a-i<t)t=a-i;
		if(a!=0)g=0;
	}
	if(k&&t>n-p+1)printf("%d",p-1);
	else if(g)printf("%d",n);
	else printf("%d",b+n+1);
}