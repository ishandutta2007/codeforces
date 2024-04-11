#include<cstdio>
#include<cstring>
using namespace std;
int a[110000],c[110000];
inline int mymin(int x,int y){return x<y?x:y;}
int main()
{
	int n;scanf("%d",&n);
	c[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i>2&&a[i-2]>(a[i-1]^a[i]))
		{
			puts("1");
			return 0;
		}
		c[i]=c[i-1]^a[i];
	}
	int ss=0x3f3f3f3f;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i;j<=n-1;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				int l=c[j]^c[i-1],r=c[k]^c[j];
				if(l>r)ss=k-i-1;
			}
		}
	}
	if(ss!=0x3f3f3f3f)printf("%d\n",ss);
	else printf("-1\n");
	return 0;
}