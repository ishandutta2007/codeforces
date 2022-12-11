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
int main()
{
	int n,a,b,c;
	scanf("%d%d%d%d",&n,&a,&b,&c);
	int s=0;
	int now=1;
	int i;
	for(i=2;i<=n;i++)
		if(now==1)
		{
			if(a<b)
			{
				now=2;
				s+=a;
			}
			else
			{
				now=3;
				s+=b;
			}
		}
		else if(now==2)
		{
			if(a<c)
			{
				now=1;
				s+=a;
			}
			else
			{
				now=3;
				s+=c;
			}
		}
		else
		{
			if(b<c)
			{
				now=1;
				s+=b;
			}
			else
			{
				now=2;
				s+=c;
			}
		}
	printf("%d\n",s);
	return 0;
}