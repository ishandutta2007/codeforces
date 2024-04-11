#include<cstdio>
int a[300],n,k,i;
char c[300];
int main(){
	scanf("%d%d%s",&n,&k,c+1);
	for(i=1;i<=n;++i)++a[c[i]];
	for(i='a';i<='z';++i)if(a[i]>k)break;
	puts(a[i]>k?"NO":"YES");
	return 0;
}