#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;
typedef long long int ll;

int h[SIZE];
int L[SIZE];
int mx[SIZE];
int last[SIZE],pos[SIZE];

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&h[i]);
	for(int i=0;i+1<n;i++) L[i]=abs(h[i+1]-h[i]);
	for(int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);l--;r--;
		int sz=0;
		ll ret=0,sum=0;
		for(int j=r-1;j>=l;j--)
		{
			int nxt=j;
			while(sz>0&&mx[sz-1]<=L[j])
			{
				sum-=(ll) mx[sz-1]*(ll) (last[sz-1]-pos[sz-1]+1);
				nxt=last[sz-1];
				sz--;
			}
			mx[sz]=L[j];
			last[sz]=nxt;
			pos[sz]=j;
			sz++;
			sum+=(ll) L[j]*(ll) (nxt-j+1);
			ret+=sum;
		}
		printf("%I64d\n",ret);
	}
	return 0;
}