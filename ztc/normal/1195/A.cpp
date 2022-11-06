#include<stdio.h>
int a[1002],n,k,t,cnt=0;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&t);a[t]++;
	}
	for(int i=1;i<=k;i++)cnt+=a[i]/2;
	printf("%d\n",((n+1)/2-cnt)+cnt*2);
}