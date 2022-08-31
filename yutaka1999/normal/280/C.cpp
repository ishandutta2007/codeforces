#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

vector <int> vec[100005];
double ret=0;

void ans(int v=0,int p=-1,int dep=1)
{
	ret+=(double) 1/dep;
	for(int i=0;i<vec[v].size();i++)
	{
		if(vec[v][i]!=p)
		{
			ans(vec[v][i],v,dep+1);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	ans();
	printf("%lf\n",ret);
	return 0;
}