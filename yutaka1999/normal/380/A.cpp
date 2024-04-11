#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 300005
#define LIM 100000

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

P let[SIZE];
ll sum[SIZE];

int main()
{
	int m;
	scanf("%d",&m);
	ll now=0;
	int id=0;
	for(int i=0;i<m;i++)
	{
		int tp;
		scanf("%d",&tp);
		if(tp==1)
		{
			int a;
			scanf("%d",&a);
			let[id]=P(a,0);
			sum[id++]=++now;
		}
		else
		{
			int a,b;
			scanf("%d %d",&a,&b);
			while(b>0&&id<LIM)
			{
				b--;
				for(int j=0;j<a;j++)
				{
					let[id]=let[j];
					sum[id++]=++now;
				}
			}
			if(b>0)
			{
				let[id]=P(a,1);
				sum[id++]=(now+=(ll) b*(ll) a);
			}
		}
	}
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		ll a;
		scanf("%I64d",&a);
		int pos=lower_bound(sum,sum+id,a)-sum;
		if(let[pos].second==0) printf("%d",let[pos].first);
		else
		{
			a-=sum[pos-1]+1;
			a%=let[pos].first;
			printf("%d",let[a].first);
		}
	}puts("");
	return 0;
}