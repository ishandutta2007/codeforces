#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 5005

using namespace std;;

vector <int> vs;
bool go[SIZE][SIZE];
bool rgo[SIZE][SIZE];
bool use[SIZE];
char str[SIZE];
int nod[SIZE];
int n;
void dfs(int v)
{
	use[v]=true;
	for(int i=0;i<n;i++) if(go[v][i]&&!use[i]) dfs(i);
	vs.push_back(v);
}
void rdfs(int v,int k)
{
	use[v]=true;
	nod[k]++;
	for(int i=0;i<n;i++) if(rgo[v][i]&&!use[i]) rdfs(i,k);
}
int scc()
{
	memset(use,false,sizeof(use));
	for(int i=0;i<n;i++) if(!use[i]) dfs(i);
	memset(use,false,sizeof(use));
	int k=0;
	for(int i=vs.size()-1;i>=0;i--)
	{
		if(!use[vs[i]])
		{
			rdfs(vs[i],k);
			if(nod[k]>1) return vs[i];
			k++;
		}
	}
	return -1;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		for(int j=0;j<n;j++)
		{
			go[i][j]=str[j]=='1';
			rgo[j][i]=str[j]=='1';
		}
	}
	int v=scc();
	if(v==-1) puts("-1");
	else
	{
		for(int i=0;i<n;i++)
		{
			if(i==v) continue;
			for(int j=0;j<n;j++)
			{
				if(j==i||j==v) continue;
				if(go[v][i]&&go[i][j]&&go[j][v])
				{
					printf("%d %d %d\n",v+1,i+1,j+1);
					return 0;
				}
			}
		}
	}
	return 0;
}