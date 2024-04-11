#include<stdio.h>
#include<cstring>
using namespace std;
char c[100005];
int i,j,k,l,s,m,n;
int gt[100005],gtw[100005],ans,st,en;
int main()
{
	scanf("%s",&c);
	l=strlen(c);
	for (i=0;i<l;i++)
	gt[i]=gt[i-1]+(c[i]=='[');
	for (i=l-1;i>=0;i--)
	{
		if (c[i]==']'||c[i]==')')
		continue;
		int next=i+1+gtw[i+1];
		if (c[i]=='('&&c[next]==')')
		gtw[i]=gtw[i+1]+2+gtw[next+1];
		if (c[i]=='['&&c[next]==']')
		gtw[i]=gtw[i+1]+2+gtw[next+1];
	}
	for (i=0;i<l;i++)
	if (gt[gtw[i]+i-1]-gt[i-1]>ans)
	ans=gt[en=gtw[i]+i-1]-gt[st=i-1];
	printf("%d\n",ans);
	for (i=st+1;i<=en;i++)
	putchar(c[i]);
}