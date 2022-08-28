#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 500005

using namespace std;
typedef pair <int,int> P;
typedef long long int ll;

P pos[SIZE];
int in[SIZE];
int nxt[SIZE],back[SIZE];
bool use[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	int sz=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		nxt[i]=i+1;
		back[i]=i-1;
		pos[sz++]=P(in[i],i);
	}
	sort(pos,pos+sz);
	ll ret=0;
	for(int i=0;i<n-2;i++)
	{
		P p=pos[i];
		int v=p.second;
		if(back[v]!=-1&&nxt[v]!=n)
		{
			ret+=min(in[back[v]],in[nxt[v]]);
		}
		else
		{
			ret+=in[v];
		}
		nxt[back[v]]=nxt[v];
		back[nxt[v]]=back[v];
	}
	printf("%I64d\n",ret);
	return 0;
}