#include<bits/stdc++.h>
char c[99];
int i,x;
#define F fflush(stdout);
int main(){
	for(;;){
		scanf("%s",c);F;
		if(*c=='e')break;
		for(i=2;i<=1<<30;i<<=1){
			printf("? %d %d\n",i,i>>1);F;
			scanf("%s",c);F;
			if(*c=='y' || i==1<<30)break;
		}
		if(*c=='x'){puts("! 1");F;continue;}
		int l=i>>1,r=i,m;
		for(;l+1<r;){
			m=(l+r)>>1;
			printf("? %d %d\n",l,m);F;
			scanf("%s",c);F;
			if(*c=='y')l=m;else r=m;
		}
		printf("! %d\n",r);F;
	}
	return 0;
}