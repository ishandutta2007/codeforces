#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int a[300000],b[300000];
bool vis[300000];int pre[300000];
int p[300000];

map<int,vector<int> > pos;map<int,int> F;

struct BCJ
{
	int fa[300000];
	void init(int n){for(int i=1;i<=n;i++)fa[i]=i;}
	int fnd(int x){return x==fa[x]?x:fa[x]=fnd(fa[x]);}
	void conn(int x,int y){fa[fnd(x)]=fnd(y);}
}B;

vector<int> C[300000];int rt[300000];

int main()
{
	int n=0,s=0;scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		pre[i]=F[a[i]];F[a[i]]=i;
		if(a[i]==b[i])p[i]=i,vis[i]=1;
		else pos[b[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			p[i]=pos[a[i]].back();pos[a[i]].pop_back();
		}
	}
	B.init(n);for(int i=1;i<=n;i++)B.conn(i,p[i]);
	for(int i=n;i>=1;i--)
	{
		if(vis[i])continue;vis[i]=1;
		for(int j=pre[i];j;j=pre[j])
		{
			if(vis[j])continue;vis[j]=1;
			if(B.fnd(i)!=B.fnd(j))
			{
				swap(p[i],p[j]);B.conn(i,j);
			}
		}
	}
	int ele=0,cyc=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]!=i)
		{
			ele++;
			if(B.fnd(i)==i)
			{
				cyc++;rt[cyc]=i;C[i].push_back(i);int u=p[i];
				while(u!=i){C[i].push_back(u);u=p[u];}
			}
		}
	}
	if(s<ele){puts("-1");return 0;}
	if(cyc==0){puts("0");return 0;}
	if(cyc==1)
	{
		puts("1");int k=rt[1];printf("%d\n",C[k].size());for(int i=0;i<C[k].size();i++)printf("%d ",C[k][i]);
		return 0;
	}
	s=min(s,ele+cyc);
	if(s<=ele+2)
	{
		printf("%d\n",cyc);
		for(int i=1;i<=cyc;i++)
		{
			int k=rt[i];printf("%d\n",C[k].size());for(int i=0;i<C[k].size();i++)printf("%d ",C[k][i]);puts("");
		}
		return 0;
	}
	int cnt=s-ele;
	printf("%d\n",cyc-cnt+2);
	int sum=0;for(int i=1;i<=cnt;i++)sum+=C[rt[i]].size();printf("%d\n",sum);
	for(int i=1;i<=cnt;i++){int k=rt[i];for(int i=0;i<C[k].size();i++)printf("%d ",C[k][i]);}puts("");
	printf("%d\n",cnt);
	for(int i=cnt;i>=1;i--)printf("%d ",rt[i]);puts("");
	for(int i=cnt+1;i<=cyc;i++){int k=rt[i];printf("%d\n",C[k].size());for(int i=0;i<C[k].size();i++)printf("%d ",C[k][i]);puts("");}
}