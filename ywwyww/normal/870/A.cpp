#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
int a[110];
int b[110];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j,x;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[x]=1;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d",&x);
		b[x]=1;
	}
	for(i=1;i<=9;i++)
		if(a[i]&&b[i])
		{
			printf("%d\n",i);
			return 0;
		}
	int s1=0,s2=0;
	for(i=1;i<=9;i++)
	{
		if(!s1&&a[i])
			s1=i;
		if(!s2&&b[i])
			s2=i;
	}
	if(s1>s2)
		swap(s1,s2);
	printf("%d%d\n",s1,s2);
	return 0;
}