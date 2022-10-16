#include<cstdio>
#include<vector>

using namespace std;

int fib[1000000];

vector<int> ed[1000000];

int sss[1000000],sz[1000000],dfn[1000000],fa[1000000];
void dfs(int u,int f=0)
{
	dfn[u]=++dfn[0];
	fa[u]=f,sz[u]=1;for(int i=0;i<ed[u].size();i++)if(ed[u][i]!=f){dfs(ed[u][i],u);sz[u]+=sz[ed[u][i]];}
	sss[u]=sz[u];
}

bool check(vector<int> P,int rt,int p)
{
	if(P.size()==1)return 1;
	int pos=0;for(int i=0;i<P.size();i++)if(sz[P[i]]==fib[p-1]||sz[P[i]]==fib[p-2]){pos=P[i];break;}
	if(!pos)return 0;
	int x=pos;while(x!=rt){x=fa[x];sz[x]-=sz[pos];}
	vector<int> Q,R;
	for(int i=0;i<P.size();i++)
		if(dfn[P[i]]>=dfn[pos]&&dfn[P[i]]<dfn[pos]+sss[pos])Q.push_back(P[i]);else R.push_back(P[i]);
	if(sz[pos]==fib[p-1])return check(Q,pos,p-1)&&check(R,rt,p-2);
	return check(Q,pos,p-2)&&check(R,rt,p-1);
}

int main()
{
	int n=0;scanf("%d",&n);for(int i=1,x=0,y=0;i<n;i++){scanf("%d%d",&x,&y);ed[x].push_back(y),ed[y].push_back(x);}
	bool fl=0;
	fib[0]=fib[1]=1;for(int i=2;i<=35;i++)fib[i]=fib[i-1]+fib[i-2];
	int x=0;for(int i=1;i<=35;i++)if(fib[i]==n)fl=1,x=i;if(!fl){puts("NO");return 0;}
	dfs(1);vector<int> P;for(int i=1;i<=n;i++)P.push_back(i);puts(check(P,1,x)?"YES":"NO");
}