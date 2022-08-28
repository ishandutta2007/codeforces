#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 305

using namespace std;

char A[SIZE][SIZE];
int vl[SIZE],pos[SIZE],add[SIZE];
bool use[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&vl[i]);
	for(int i=0;i<n;i++) scanf("%s",&A[i]);
	for(int i=0;i<n;i++)
	{
		if(!use[i])
		{
			use[i]=true;
			queue <int> que;
			que.push(i);
			int sz=0;
			while(!que.empty())
			{
				int v=que.front();que.pop();
				pos[sz]=v;
				add[sz++]=vl[v];
				for(int j=0;j<n;j++)
				{
					if(!use[j]&&A[v][j]=='1')
					{
						use[j]=true;
						que.push(j);
					}
				}
			}
			sort(pos,pos+sz);
			sort(add,add+sz);
			for(int j=0;j<sz;j++) vl[pos[j]]=add[j];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",vl[i]);
	}puts("");
	return 0;
}