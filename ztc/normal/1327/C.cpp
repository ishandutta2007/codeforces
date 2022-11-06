#include<stdio.h>
int n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	printf("%d\n",(n+1)*(m+1)-4);
	for(int i=1;i<n;i++)putchar('U');
	for(int i=1;i<m;i++)putchar('L');
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++)putchar(i&1?'R':'L');
		if(i!=n)putchar('D');
	}
}