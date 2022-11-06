#include<stdio.h>
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
using namespace std;
int a[10],b[10],cnt=0,ans=0,cnt1=0,i;char c;
main()
{
	while(getchar()!='\n');
	while((c=getchar())!='\n'&&c!=' ')a[c-'0']++;
	while(c!='\n')c=getchar();
	while((c=getchar())!='\n'&&c!=' '&&c!=EOF)b[c-'0']++;
	for(i=9;i>=0;i--)
	{
		cnt1+=Max(a[i]-b[i],0);
		if(i!=9)ans+=Min(cnt,Max(a[i]-b[i],0));
		cnt=Max(0,cnt-Max(a[i]-b[i],0))+Max(b[i]-a[i],0);
	}printf("%d\n",cnt1-ans);
	cnt=b[9];ans=0;
	for(i=8;i>=0;i--)
	{
		ans+=Min(cnt,a[i]);
		cnt=Max(0,cnt-a[i])+b[i];
	}printf("%d",ans);
}