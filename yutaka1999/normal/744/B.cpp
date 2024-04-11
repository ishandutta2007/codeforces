#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 22
#define INF 1000000000

using namespace std;

vector < vector <int> > query;
vector < vector <int> > ans;
int A[1005];

void dfs(int l,int r,int sz)
{
	if(l+1==r) return;
	int m=(l+r)/2;
	for(int i=m;i<r;i++) query[sz].push_back(i);sz++;
	for(int i=l;i<m;i++) query[sz].push_back(i);sz++;
	dfs(l,m,sz);
	dfs(m,r,sz);
}
void dfs2(int l,int r,int sz)
{
	if(l+1==r) return;
	int m=(l+r)/2;
	for(int i=l;i<m;i++) A[i]=min(A[i],ans[sz][i]);sz++;
	for(int i=m;i<r;i++) A[i]=min(A[i],ans[sz][i]);sz++;
	dfs2(l,m,sz);
	dfs2(m,r,sz);
}
int main()
{
	int n;
	scanf("%d",&n);
	query.resize(100);
	dfs(0,n,0);
	ans.resize(100);
	for(int i=0;i<query.size();i++)
	{
		vector <int> vec=query[i];
		if(vec.empty()) break;
		printf("%d\n",vec.size());
		for(int j=0;j<vec.size();j++)
		{
			if(j!=0) printf(" ");
			printf("%d",vec[j]+1);
		}puts("");
		fflush(stdout);
		for(int j=0;j<n;j++)
		{
			int v;
			scanf("%d",&v);
			ans[i].push_back(v);
		}
	}
	puts("-1");
	for(int i=0;i<n;i++) A[i]=INF;
	dfs2(0,n,0);
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",A[i]);
	}puts("");
	return 0;
}