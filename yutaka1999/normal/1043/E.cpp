#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <cassert>
#define SIZE 300005

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

ll X[SIZE],Y[SIZE];
vector <int> vec[SIZE];
ll ans[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector <P> vx;
	for(int i=0;i<n;i++)
	{
		scanf("%lld %lld",&X[i],&Y[i]);
		vx.push_back(P(Y[i]-X[i],i));
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	sort(vx.begin(),vx.end());
	ll sum=0,sx=0;
	for(int i=0;i<n;i++) sx+=X[i];
	for(int i=0;i<n;i++)
	{
		int v=vx[i].second;
		ans[v]=(sx-X[v])+vx[i].first*(ll) (n-i-1)+sum+X[v]*(ll) (n-1);
		sum+=vx[i].first;
		for(int j=0;j<vec[v].size();j++)
		{
			int to=vec[v][j];
			ans[v]-=X[v]+X[to]+min(Y[v]-X[v],Y[to]-X[to]);
		}
	}
	for(int i=0;i<n;i++) printf("%lld ",ans[i]);
	puts("");
	return 0;
}