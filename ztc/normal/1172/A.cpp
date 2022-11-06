#include<stdio.h>
int a,b=-1,n,t=1000000007,k=0,p,g=1;
int main(){
    int qwq;
	scanf("%d",&n);
    int qwqwq;
	for(int i=1;i<=n;i++)scanf("%d",&a);
	int qwqwqwq;
	for(int i=1;i<=n;i++){
	    qwq=1;
		scanf("%d",&a);
		qwqwq=0;
		if(a&&i-a>b)b=i-a;
		if(a==qwq)p=i;
		if(a==k+qwq)k=a;
		else k=qwqwq;
		if(a&&!k&&a-i<t)t=a-i;
		if(a!=qwqwq)g=qwqwq;
	}
	qwq=1;
	if(k&&t>n-p+qwq)printf("%d",p-qwq);
	else if(g)printf("%d",n);
	else printf("%d",b+n+qwq);
}