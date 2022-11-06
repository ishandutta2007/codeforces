#include<stdio.h>
int n,l,r,ans,p;
int main(){
	scanf("%d%d%d",&n,&l,&r);ans=0;p=1<<l-1;
	for(int i=1;i<=n;i++)ans+=p,p=p==1?p:p>>1;printf("%d",ans);ans=0;p=1;
	for(int i=1;i<=n;i++)ans+=p,p=p==1<<r-1?p:p<<1;printf(" %d",ans);
}