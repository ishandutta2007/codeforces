#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#define SIZE 205
#define INF 1000000000

using namespace std;

int in[SIZE];
int mn[SIZE],mx[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	int ret=-INF;
	for(int l=0;l<n;l++)
	{
		multiset <int> nin,inc;
		multiset <int>::iterator it;
		for(int i=0;i<n;i++) nin.insert(in[i]);
		int all=0;
		for(int r=l;r<n;r++)
		{
			all+=in[r];
			inc.insert(in[r]);
			it=nin.lower_bound(in[r]);
			nin.erase(it);
			int si=0;
			for(;!inc.empty()&&si<k;si++)
			{
				it=inc.begin();
				mn[si]=*it;
				inc.erase(it);
			}
			int sn=0;
			for(;!nin.empty()&&sn<k;sn++)
			{
				it=nin.end();it--;
				mx[sn]=*it;
				nin.erase(it);
			}
			int sum=all;
			for(int i=0;i<min(sn,si);i++)
			{
				if(mn[i]<mx[i])
				{
					sum-=mn[i];
					sum+=mx[i];
				}
			}
			ret=max(ret,sum);
			while(si)
			{
				si--;
				inc.insert(mn[si]);
			}
			while(sn)
			{
				sn--;
				nin.insert(mx[sn]);
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}