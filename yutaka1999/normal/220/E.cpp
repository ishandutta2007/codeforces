#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005

using namespace std;
typedef long long int ll;

struct BIT
{
	int bit[SIZE];
	int n;
	
	void add(int k,int x)
	{
		while(k<=n)
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
	int sum(int a,int b)
	{
		return sum(b)-sum(a-1);
	}
};
BIT left,right;
int in[SIZE];
vector <int> vx;

int main()
{
	int n;
	ll k;
	scanf("%d %lld",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		vx.push_back(in[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<n;i++) in[i]=lower_bound(vx.begin(),vx.end(),in[i])-vx.begin();
	left.n=n+2;right.n=n+2;
	int e=n-1;
	ll sum=0;
	while(e>=0)
	{
		int v=in[e];
		int gt=right.sum(1,v);
		if(sum+gt>k) break;
		sum+=gt;
		right.add(v+1,1);
		e--;
	}
	if(e<0)
	{
		printf("%llld\n",(ll) n*(ll) (n-1)/2);
		return 0;
	}
	e++;
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		int v=in[i];
		int gt=left.sum(v+2,n)+right.sum(1,v);
		sum+=gt;
		left.add(v+1,1);
		while(e<n&&sum>k)
		{
			v=in[e++];
			gt=left.sum(v+2,n)+right.sum(1,v);
			sum-=gt;
			right.add(v+1,-1);
		}
		ret+=e-i-1;
	}
	printf("%llld\n",(ll) n*(ll) (n-1)/2-ret);
	return 0;
}