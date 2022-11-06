#include<stdio.h>
int n,m,t,k;
char a[102][102],b[102][102];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%s",&a[i][0]);
	for(int i=0;i<m;i++)scanf("%s",&b[i][0]);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);k--;
		printf("%s%s\n",&a[k%n][0],&b[k%m][0]);
	}
}