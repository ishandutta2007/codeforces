#include<cstdio>
int s,v1,v2,t1,t2,a,b;
int main(){
	scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
	a=v1*s+t1*2;
	b=v2*s+t2*2;
	if(a<b)puts("First");
		else if(a==b)puts("Friendship");
				else puts("Second");
	return 0;
}