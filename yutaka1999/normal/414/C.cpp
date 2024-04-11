#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE (1024*1024+5)
#define MX 25

using namespace std;
typedef long long int ll;

struct BIT
{
	int bit[SIZE];
	int n;
	
	void init()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int k)
	{
		while(k<SIZE)
		{
			bit[k]++;
			k+=k&-k;
		}
	}
	void rem(int k)
	{
		while(k<SIZE)
		{
			bit[k]--;
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
	int gk(int k)
	{
		return sum(SIZE-1)-sum(k);
	}
};
BIT bit;
ll rev[MX],sm[MX];
int in[SIZE],cnt[SIZE];
vector <int> vx;

int main()
{
	int n;
	scanf("%d",&n);
	int sz=1<<n;
	for(int i=0;i<sz;i++)
	{
		scanf("%d",&in[i]);
		vx.push_back(in[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<sz;i++) in[i]=lower_bound(vx.begin(),vx.end(),in[i])-vx.begin();
	bit.init();
	for(int i=0;i<=n;i++)
	{
		int bt=1<<i;
		rev[i]=0;
		for(int j=0;j<sz;j+=bt)
		{
			for(int k=j;k<j+bt;k++)
			{
				rev[i]+=bit.gk(in[k]+1);
				bit.add(in[k]+1);
				sm[i]+=cnt[in[k]]++;
			}
			for(int k=j;k<j+bt;k++)
			{
				bit.rem(in[k]+1);
				cnt[in[k]]--;
			}
		}
	}
	ll all=rev[n];
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int q;
		scanf("%d",&q);
		ll pr=(ll) sz*(ll) ((1<<q)-1)/2;
		ll el=pr-sm[q]-rev[q];
		all+=el-rev[q];
		for(int j=n;j>q;j--) rev[j]-=rev[j-1];
		rev[q]=el;
		for(int j=q+1;j<=n;j++) rev[j]+=rev[j-1];
		for(int j=0;j<q;j++)
		{
			pr=(ll) sz*(ll) ((1<<j)-1)/2;
			rev[j]=pr-sm[j]-rev[j];
		}
		printf("%llld\n",all);/*
		for(int j=0;j<=n;j++)
		{
			printf("%llld ",rev[j]);
		}puts("");*/
	}
	return 0;
}