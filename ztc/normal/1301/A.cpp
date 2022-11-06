#include<stdio.h>
#include<memory.h>
char a[1002],b[1002],c[1002];
int t;
int main(){
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		scanf("%s%s%s",a,b,c);
		bool f=1;
		for(int i=0;a[i];i++)if(a[i]!=c[i]&&b[i]!=c[i])f=0;
		printf("%s\n",f?"YES":"NO");
	}
}