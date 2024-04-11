#include<cstdio>
#include<cstring>
using namespace std;
int p[410000],a[410000];
bool b[410000];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			int x;scanf("%d",&x);
			p[a[i]]=x;
			b[i]=false;
		}
		int ss=1;
		for(int i=1;i<=n;i++)
		{
			if(b[i]==false)
			{
				while(b[i]==false)
				{
					b[i]=true;
					i=p[i];
				}
				ss=ss*2%1000000007;
			}
		}
		printf("%d\n",ss);
	}
	return 0;
}