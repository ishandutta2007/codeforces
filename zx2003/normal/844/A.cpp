#include<cstdio>
#include<cstring>
char c[1005];
int n,k,i,s[150];
int main(){
	scanf("%s%d",c+1,&k);
	n=strlen(c+1);
	if(n<k)return puts("impossible"),0;
	for(i=1;i<=n;++i)++s[c[i]];
	for(i='a';i<='z';++i)if(s[i])--k;
	printf("%d\n",k>0?k:0);
	return 0;
}