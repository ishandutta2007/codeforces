#include<stdio.h>
#include<algorithm>
int n,k,a[400002],t,s[400002],tot=0,ans=0;
int main(){
	scanf("%d%d",&n,&t);t<<=3;
	if(t/n<=30)k=1<<t/n;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);a[0]=-1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1])tot++,s[tot]=s[tot-1];
		s[tot]++;
	}if(tot<=k||k<=0)return printf("0")&0;
	for(int i=0;i<=tot-k;i++)if(s[i+k]-s[i]>ans)ans=s[i+k]-s[i];
	printf("%d",n-ans);
}