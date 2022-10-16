#include<cstdio>
#include<vector>

using namespace std;

vector<int> ed[2000000],R[2000000];

bool in[2000000];

int main()
{
	int n=0,m=0;scanf("%d%d",&n,&m);
	for(int i=1,u=0,v=0;i<=m;i++)
	{
		scanf("%d%d",&u,&v);ed[u].push_back(v),R[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		bool fl=1;
		for(int j=0;j<R[i].size();j++)if(in[R[i][j]]){fl=0;break;}
		in[i]=fl;
	}
	for(int i=n;i>=1;i--)
	{
		if(!in[i])continue;
		bool fl=1;
		for(int j=0;j<R[i].size();j++)if(in[R[i][j]]){fl=0;break;}
		in[i]=fl;
	}
	int cnt=0;for(int i=1;i<=n;i++)if(in[i])cnt++;printf("%d\n",cnt);
	for(int i=1;i<=n;i++)if(in[i])printf("%d ",i);
}