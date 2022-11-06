#include<stdio.h>
int a[1000002],n,m,k,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&k);
		if(k>=m)k=m-1;
		int len=n-m,p=m-k,ans=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)a[i]=a[i]>a[i+len]?a[i]:a[i+len];
		for(int i=1;i<=m-p+1;i++){
			int minn=2e9;
			for(int j=0;j<p;j++)minn=minn>a[i+j]?a[i+j]:minn;
			ans=ans>minn?ans:minn;
		}printf("%d\n",ans);
	}
}