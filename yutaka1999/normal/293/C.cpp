#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

vector <P> vec;
ll dfs(int pos=0,ll a=1,ll b=1,ll c=1)
{
	if(pos==vec.size())
	{
		if((a+b+c)%2==0)
		{
			ll t=(a+b+c)/2;
			if(t>a&&t>b&&t>c) return 1;
		}
		return 0;
	}
	ll ret=0;
	ll all=1;
	for(int i=0;i<vec[pos].second;i++) all*=vec[pos].first;
	ll pa=1;
	for(int i=0;i<=vec[pos].second;i++)
	{
		ll pb=1;
		for(int j=0;i+j<=vec[pos].second;j++)
		{
			ll pc=all;pc/=pa;pc/=pb;
			ret+=dfs(pos+1,a*pa,b*pb,c*pc);
			pb*=vec[pos].first;
		}
		pa*=vec[pos].first;
	}
	return ret;
}
int main()
{
	ll n;
	scanf("%I64d",&n);
	if(n%3!=0)
	{
		printf("%d\n",0);
		return 0;
	}
	n/=3;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ll time=0;
			while(n%i==0)
			{
				n/=i;
				time++;
			}
			vec.push_back(P(i,time));
		}
	}
	if(n!=1) vec.push_back(P(n,1));
	printf("%I64d\n",dfs());
	return 0;
}