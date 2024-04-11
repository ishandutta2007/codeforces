#include<stdio.h>
int n,a[600002],minn,cntt=0,cnttt=0,l,r,lp,ans=0;
char c[300002];
int main(){
	scanf("%d%s",&n,c+1);
	for(int i=1;i<=n;i++)a[i]=a[i-1]+(c[i]=='('?1:-1),minn>a[i]?minn=a[i]:0;
	if(a[n]!=0)return printf("0\n1 1")&0;
	for(int i=1;i<=n;i++)cntt+=(a[i+n]=a[i])==minn;
	for(lp=n;lp>=1;lp--)if(a[lp]==minn)break;l=r=lp;ans=cntt;
	for(int i=1;i<=n||a[i-1]!=minn;i++)a[i]==minn+1?cnttt++:(a[i]!=minn?0:(cnttt<=ans?0:(l=lp+1,r=i,ans=cnttt),cnttt=0,lp=i));
	for(lp=n;lp>=1;lp--)if(a[lp]==minn+1)break;cnttt=0;
	if(lp)for(int i=1;i<=n||a[i-1]>minn+1;i++)a[i]==minn?cnttt=0:(a[i]==minn+2?cnttt++:(a[i]!=minn+1?0:(cnttt+cntt<=ans?0:(ans=cnttt+cntt,l=lp+1,r=i),lp=i,cnttt=0)));
	printf("%d\n%d %d",ans,(l-1)%n+1,(r-1)%n+1);
}