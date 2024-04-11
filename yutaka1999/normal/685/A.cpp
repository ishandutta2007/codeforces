#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 7

using namespace std;

int getD(int x)//x>0
{
	if(x==0) return 1;
	int ret=0;
	while(x>0)
	{
		ret++;
		x/=7;
	}
	return ret;
}
int ord[7];
int cnt[10];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int L=getD(n-1),R=getD(m-1);
	if(L+R>7)
	{
		puts("0");
		return 0;
	}
	int ret=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			memset(cnt,0,sizeof(cnt));
			int now=i;
			for(int k=0;k<L;k++)
			{
				cnt[now%7]++;
				now/=7;
			}now=j;
			for(int k=0;k<R;k++)
			{
				cnt[now%7]++;
				now/=7;
			}
			bool up=true;
			for(int k=0;k<7;k++) if(cnt[k]>=2) up=false;
			ret+=up;
		}
	}
	printf("%d\n",ret);
	return 0;
}