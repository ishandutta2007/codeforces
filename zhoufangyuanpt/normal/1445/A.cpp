#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[110],b[110];
inline bool cmp(int x,int y){return x>y;}
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,m;scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)scanf("%d",&b[i]);
		sort(a+1,a+n+1);sort(b+1,b+n+1,cmp);
		bool bk=true;
		for(int i=1;i<=n;i++)
		{
			if(a[i]+b[i]>m){bk=false;break;}
		}
		puts(bk?"Yes":"No");
	}
	return 0;
}