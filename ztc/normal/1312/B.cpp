#include<stdio.h>
#include<algorithm>
int a[100002],n;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		std::sort(a+1,a+n+1);
		for(int i=n;i>=1;i--)printf("%d ",a[i]);puts("");
	}
}