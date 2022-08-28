#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005

using namespace std;

vector <int> vec[SIZE];
int pr[SIZE],nxt[SIZE];
int A[SIZE],memo[SIZE];
int ans[SIZE],vt[SIZE];
int n,m,q;

void dfs(int v,int d=0)
{
	vt[d++]=v;
	//for(int i=0;i<d;i++) printf("%d ",vt[i]);puts("");
	if(d>=n) ans[v]=vt[d-n];
	else ans[v]=SIZE;
	for(int i=0;i<vec[v].size();i++) dfs(vec[v][i],d);
}
int main()
{
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&pr[i]);
		pr[i]--;
	}
	for(int i=0;i<n;i++) nxt[pr[i]]=pr[(i+1)%n];
	for(int i=0;i<m;i++)
	{
		scanf("%d",&A[i]);
		A[i]--;
	}
	memset(memo,-1,sizeof(memo));
	vector <int> rt;
	for(int i=m-1;i>=0;i--)
	{
		int t=nxt[A[i]];
		if(memo[t]!=-1) vec[memo[t]].push_back(i);
		else rt.push_back(i);
		memo[A[i]]=i;
	}
	for(int i=0;i<rt.size();i++) dfs(rt[i]);
	for(int i=m-2;i>=0;i--) ans[i]=min(ans[i],ans[i+1]);
	//for(int i=0;i<m;i++) printf("%d ",ans[i]);puts("");
	for(int i=0;i<q;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		l--,r--;
		if(ans[l]<=r) printf("1");
		else printf("0");
	}puts("");
	return 0;
}