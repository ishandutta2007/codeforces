#include<cstdio>
#include<cstring>
using namespace std;
int a[110000],n,k;
int pand(int x)
{
	int s=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=x)i=i+k-1,s++;
	}
	return s;
}
inline int mymin(int x,int y){return x<y?x:y;}
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ss=0x3f3f3f3f;
		for(int i=1;i<=100;i++)
		{
			ss=mymin(ss,pand(i));
		}
		printf("%d\n",ss);
	}
	return 0;
}