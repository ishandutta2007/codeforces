#include<stdio.h>
long long p,q;
int main(){
	scanf("%lld%lld",&p,&q);
	if(p>q||((p^q)&1)==1)return puts("-1")&0;q-=p;
	long long a=0,b=0,c=0;
	for(int i=0;i<=60;i++){
		long long P=p&1ll<<i,Q=q>>1&1ll<<i;
		if(P&&Q)a|=P,b|=P,c|=P;
		else if(P)a|=P;
		else if(Q)a|=Q,b|=Q;
	}if(!a)puts("0");
	else if(!b)printf("1\n%lld",a);
	else if(!c)printf("2\n%lld %lld",a,b);
	else printf("3\n%lld %lld %lld",a,b,c);
}