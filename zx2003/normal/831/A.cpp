#include<cstdio> 
int n,i,j,a[105];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	j=1;
	while(j<=n && a[j+1]>a[j])++j;
	while(j<=n && a[j+1]==a[j])++j;
	while(j<=n && a[j+1]<a[j])++j;
	if(j>n)puts("YES");
		else puts("NO");
	return 0;
}