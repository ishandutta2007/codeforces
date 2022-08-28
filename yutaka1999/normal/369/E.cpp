#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 1000005

using namespace std;
typedef pair <int,int> P;

struct BIT
{
	int bit[SIZE+5];
	
	void add(int k,int x)
	{
		while(k<=SIZE)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int sum(int k)
	{
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
};
BIT bit;
vector <int> l1[SIZE];
vector <P> l2[SIZE];
int ans[SIZE];


int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		l1[a].push_back(b);
	}
	for(int i=0;i<m;i++)
	{
		ans[i]=n;
		int a;
		scanf("%d",&a);a--;
		int now;
		scanf("%d",&now);
		l2[0].push_back(P(now-1,i));
		for(int j=0;j<a;j++)
		{
			int nxt;
			scanf("%d",&nxt);
			l2[now+1].push_back(P(nxt-1,i));
			now=nxt;
		}
		l2[now+1].push_back(P(SIZE-2,i));
	}
	for(int i=SIZE-1;i>=0;i--)
	{
		for(int j=0;j<l1[i].size();j++) bit.add(l1[i][j],1);
		for(int j=0;j<l2[i].size();j++)
		{
			P p=l2[i][j];
			ans[p.second]-=bit.sum(p.first);
		}
	}
	for(int i=0;i<m;i++) printf("%d\n",ans[i]);
	return 0;
}