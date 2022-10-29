#include<cstdio>
#include<cstring>
using namespace std;
int a[110000],p[110000],plen,ty[110000];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	plen=0;
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			p[++plen]=i;
			ty[i]=a[i]<a[i+1];
		}
		else if(i==n)
		{
			p[++plen]=i;
			ty[i]=a[i]<a[i-1];
		}
		else
		{
			if((a[i]<a[i+1])==(a[i]<a[i-1]))
			{
				p[++plen]=i;
				ty[i]=a[i]<a[i+1];
			}
		}
	}
	int len=0,ss=0;
	for(int i=2;i<=plen;i++)
	{
		if(len<p[i]-p[i-1]+1)len=p[i]-p[i-1]+1,ss=1;
		else if(len==p[i]-p[i-1]+1)ss++;
	}
	if(ss==2)
	{
		bool bk=false;
		for(int i=2;i<plen;i++)
		{
			if(ty[p[i]]==0&&p[i]-p[i-1]+1==len&&p[i+1]-p[i]+1==len)
			{
				bk=true;break;
			}
		}
		if(bk==false)puts("0");
		else
		{
			if(len%2==0)puts("0");
			else puts("1");
		}
	}
	else puts("0");
	return 0;
}