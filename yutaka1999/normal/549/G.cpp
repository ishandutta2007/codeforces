#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <stack>
#include <queue>
#define SIZE 200005
#define BT 256*1024*2

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct BIT
{
	int bit[SIZE];
	
	void init()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int k,int x)
	{
		while(k<SIZE)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int get(int k)
	{
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
BIT bit;
int A[SIZE],ord[SIZE];
P pos[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		pos[i]=P(A[i]+i,i);
	}
	sort(pos,pos+n);
	for(int i=0;i+1<n;i++)
	{
		if(pos[i].first==pos[i+1].first)
		{
			puts(":(");//)
			return 0;
		}
	}
	for(int i=0;i<n;i++) ord[pos[i].second]=i;
	bit.init();
	for(int i=n-1;i>=0;i--)
	{
		int f=bit.get(1,ord[i]+1);
		A[i]-=f;
		A[i]+=(n-ord[i]-1)-((n-i-1)-f);
		bit.add(ord[i]+1,1);
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",A[pos[i].second]);
	}puts("");
	return 0;
}