#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;

vector <int> vec[SIZE];
ll gt[SIZE];
int in[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(m==1)
	{
		puts("0");
		return 0;
	}
	ll sum=0;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&in[i]);
		if(i>0&&in[i]!=in[i-1])
		{
			ll vl=abs(in[i]-in[i-1]);
			sum+=vl;
			gt[in[i]]+=vl;
			gt[in[i-1]]+=vl;
			vec[in[i-1]].push_back(in[i]);
			vec[in[i]].push_back(in[i-1]);
		}
	}
	ll ret=sum;
	for(int i=0;i<SIZE;i++)
	{
		if(vec[i].empty()) continue;
		sort(vec[i].begin(),vec[i].end());
		int sz=vec[i].size();
		ll mn=INF;
		for(int j=max(0,sz/2-1);j<=min(sz/2+1,sz-1);j++)
		{
			int vx=vec[i][j];
			ll num=0;
			for(int k=0;k<sz;k++)
			{
				ll d=abs(vx-vec[i][k]);
				num+=d;
			}
			mn=min(mn,num);
		}
		ret=min(ret,sum-gt[i]+mn);
	}
	printf("%I64d\n",ret);
	return 0;
}