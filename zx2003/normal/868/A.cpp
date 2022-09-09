#include<cstdio>
const int N=1005;
char c[5],d[5];
int n;
bool a[N],b[N],f;
int main(){
	scanf("%s%d",c+1,&n);
	while(n--)scanf("%s",d+1),a[d[1]]=1,b[d[2]]=1,f=f || (c[1]==d[1] && c[2]==d[2]);
	f|=b[c[1]] && a[c[2]];
	return puts(f?"YES":"NO"),0;
}