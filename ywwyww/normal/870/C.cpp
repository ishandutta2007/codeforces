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
void solve()
{
	int n;
	scanf("%d",&n);
	if(n<=3)
		printf("-1\n");
	else
	{
		int s=n/4;
		n%=4;
		if(n==1)
		{
			if(s>=2)//4+4+1=9
			{
				s--;
				printf("%d\n",s);
			}
			else
				printf("-1\n");
		}
		else if(n==2)
		{
			if(s>=1)//4+2=6
				printf("%d\n",s);
			else
				printf("-1\n");
		}
		else if(n==3)
		{
			if(s>=3)//4+4+1=9 4+2=6
			{
				s--;
				printf("%d\n",s);
			}
			else
				printf("-1\n");
		}
		else
			printf("%d\n",s);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		solve();
	return 0;
}