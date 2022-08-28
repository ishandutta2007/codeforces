#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#define SIZE 1005
#define INF 1000000000

using namespace std;

struct P
{
	int f,s,t;
	P(int f=0,int s=0,int t=0):f(f),s(s),t(t){}
};
vector <P> vec;
int deg[SIZE],to[SIZE],len[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	memset(to,-1,sizeof(to));
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		to[a]=b;
		len[a]=c;
		deg[b]++;
	}
	for(int i=0;i<n;i++)
	{
		if(deg[i]==0&&to[i]!=-1)
		{
			int v=i;
			int ret=INF;
			for(;to[v]!=-1;v=to[v]) ret=min(ret,len[v]);
			vec.push_back(P(i+1,v+1,ret));
		}
	}
	printf("%d\n",vec.size());
	for(int i=0;i<vec.size();i++) printf("%d %d %d\n",vec[i].f,vec[i].s,vec[i].t);
	return 0;
}