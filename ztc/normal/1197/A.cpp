#include<stdio.h>
#include<algorithm>
int a[100002],n,m;
inline int Min(int a,int b){return a<b?a:b;}
inline int Max(int a,int b){return a>b?a:b;}
int main(){
	scanf("%d",&m);
	while(m--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		std::sort(a+1,a+n+1);
		printf("%d\n",Max(Min(n-2,a[n-1]-1),0));
	}
}