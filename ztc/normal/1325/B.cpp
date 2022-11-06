#include<stdio.h>
#include<algorithm>
int a[100002],n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		std::sort(a+1,a+n+1);printf("%d\n",std::unique(a+1,a+n+1)-a-1);
	}
}