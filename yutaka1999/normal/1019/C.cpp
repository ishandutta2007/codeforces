#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1000005

using namespace std;

bool use[SIZE],ng[SIZE];
vector <int> vec[SIZE];
vector <int> rvec[SIZE];
int n,m;

void solve(int pos=0)
{
	if(pos==n) return;
	if(ng[pos])
	{
		solve(pos+1);
		return;
	}
	ng[pos]=true;
	for(int i=0;i<vec[pos].size();i++)
	{
		int to=vec[pos][i];
		ng[to]=true;
	}
	solve(pos+1);
	bool up=false;
	for(int i=0;i<rvec[pos].size();i++)
	{
		int to=rvec[pos][i];
		up|=use[to];
	}
	use[pos]=!up;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		vec[a].push_back(b);
		rvec[b].push_back(a);
	}
	solve();
	vector <int> ans;
	for(int i=0;i<n;i++) if(use[i]) ans.push_back(i);
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]+1);
	}puts("");
	return 0;
}