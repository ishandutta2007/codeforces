#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#define SIZE 100005

using namespace std;
typedef long long int ll;

int imos[SIZE];
int ans[SIZE];
int left[SIZE],right[SIZE];
int ad[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&left[i],&right[i],&ad[i]);
		left[i]--;right[i]--;
	}
	memset(ans,0,sizeof(ans));
	for(int i=0;i<30;i++)
	{
		memset(imos,0,sizeof(imos));
		for(int j=0;j<m;j++)
		{
			if(ad[j]>>i&1)
			{
				imos[left[j]]++;
				imos[right[j]+1]--;
			}
		}
		for(int j=1;j<n;j++) imos[j]+=imos[j-1];
		for(int j=0;j<n;j++)
		{
			imos[j]=min(imos[j],1);
			if(imos[j]==1)
			{
				ans[j]|=1<<i;
			}
		}
		for(int j=1;j<n;j++) imos[j]+=imos[j-1];
		for(int j=0;j<m;j++)
		{
			if(!(ad[j]>>i&1))
			{
				int vl=imos[right[j]]-(left[j]==0?0:imos[left[j]-1]);
				if(vl==right[j]-left[j]+1)
				{
					puts("NO");
					return 0;
				}
			}
		}
	}
	puts("YES");
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]);
	}puts("");
	return 0;
}