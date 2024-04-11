#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005

using namespace std;

struct BIT
{
	int bit[SIZE];
	
	void init()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int k,int x)
	{
		k++;
		while(k<SIZE)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int get(int k)
	{
		k++;
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
	int get(int s,int t)
	{
		return get(t)-get(s-1);
	}
};
BIT bit1,bit2;
int cnt[SIZE];
int A,B;

int main()
{
	int n,k,q;
	scanf("%d %d %d %d %d",&n,&k,&A,&B,&q);
	bit1.init();
	bit2.init();
	for(int i=0;i<q;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			int a,b;
			scanf("%d %d",&a,&b);a--;
			bit1.add(a,-min(B,cnt[a]));
			bit2.add(a,-min(A,cnt[a]));
			cnt[a]+=b;
			//printf("%d : %d %d\n",a,min(B,cnt[a]),min(A,cnt[a]));
			bit1.add(a,min(B,cnt[a]));
			bit2.add(a,min(A,cnt[a]));
		}
		else
		{
			int v;
			scanf("%d",&v);v--;
			//printf("%d %d: %d %d\n",v,v+k,bit1.get(0,v-1),bit2.get(v+k,n-1));
			printf("%d\n",bit1.get(0,v-1)+bit2.get(v+k,n-1));
		}
	}
	return 0;
}