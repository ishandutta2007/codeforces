#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
long long ans=0;
int n,k,x,y,d[200005],siz[200005],a[200005];
vector<int>s[200005];
bool cmp(int a,int b){return a>b;}
void dfs(int p,int f)
{
	int v;
	d[p]=d[f]+1;
	siz[p]=1;
	for(int i=0;i<s[p].size();i++)
	{
		v=s[p][i];
		if(v==f)continue;
		dfs(v,p);
		siz[p]+=siz[v];
	}
	a[p]=d[p]-siz[p];
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		s[x].push_back(y);
		s[y].push_back(x);
	}
	dfs(1,0);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=k;i++)ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}