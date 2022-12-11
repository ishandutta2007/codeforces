#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,dep[100005],d[100005],x,y,cnt=0,tot=0;
bool ok[2];
vector<int>s[100005];
void dfs(int p,int f){
	int v;
	dep[p]=dep[f]+1;
	if(d[p]==1)
	{
		cnt++;
		ok[dep[p]%2]=true;	
		return;
	}
	for(int i=0;i<s[p].size();i++)
	{
		v=s[p][i];
		if(v==f)continue;
		dfs(v,p);
	}
	for(int i=0;i<s[p].size();i++)
	{
		v=s[p][i];
		if(d[v]==1)
		{
			tot++;
			return;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		s[x].push_back(y);
		s[y].push_back(x);
		d[x]++;d[y]++;
	}
	ok[0]=false;ok[1]=false;
	for(int i=1;i<=n;i++)
	{
		if(d[i]>1)
		{
			dfs(i,0);
			break;
		}
	}
	if(ok[0]&&ok[1])printf("3 ");
	else printf("1 ");
	printf("%d\n",n-1-cnt+tot);
	return 0;
}