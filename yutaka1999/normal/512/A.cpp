#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <functional>
#define SIZE 105
#define ALP 26

using namespace std;

bool ok[ALP][ALP];
char str[SIZE][SIZE];
int deg[SIZE];
int L[SIZE],ord[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str[i]);
		L[i]=strlen(str[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			bool up=true;
			for(int k=0;k<min(L[i],L[j]);k++)
			{
				if(str[i][k]!=str[j][k])
				{
					ok[str[i][k]-'a'][str[j][k]-'a']=true;
					up=false;
					break;
				}
			}
			if(up)
			{
				if(L[i]>L[j])
				{
					puts("Impossible");
					return 0;
				}
			}
		}
	}
	queue <int> que;
	for(int i=0;i<ALP;i++)
	{
		for(int j=0;j<ALP;j++)
		{
			if(ok[j][i]) deg[i]++;
		}
		if(deg[i]==0) que.push(i);
	}
	int sz=0;
	while(!que.empty())
	{
		int v=que.front();que.pop();
		ord[sz++]=v;
		for(int i=0;i<ALP;i++)
		{
			if(ok[v][i])
			{
				deg[i]--;
				if(deg[i]==0)
				{
					que.push(i);
				}
			}
		}
	}
	if(sz<ALP) puts("Impossible");
	else
	{
		for(int i=0;i<sz;i++) printf("%c",'a'+ord[i]);
		puts("");
	}
	return 0;
}