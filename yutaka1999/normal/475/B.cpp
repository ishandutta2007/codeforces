#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define SIZE 25

using namespace std;
typedef pair <int,int> P;

char str[SIZE];
char str2[SIZE];
bool ok[SIZE][SIZE];
queue <P> que;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",&str);
	scanf("%s",&str2);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			memset(ok,false,sizeof(ok));
			que.push(P(i,j));
			ok[i][j]=true;
			int cnt=0;
			while(!que.empty())
			{
				P p=que.front();que.pop();
				cnt++;
				int x=p.first,y=p.second;
				if(str2[y]=='^')
				{
					if(x>0&&!ok[x-1][y])
					{
						ok[x-1][y]=true;
						que.push(P(x-1,y));
					}
				}
				else
				{
					if(x<n-1&&!ok[x+1][y])
					{
						ok[x+1][y]=true;
						que.push(P(x+1,y));
					}
				}
				if(str[x]=='<')
				{
					if(y>0&&!ok[x][y-1])
					{
						ok[x][y-1]=true;
						que.push(P(x,y-1));
					}
				}
				else
				{
					if(y<m-1&&!ok[x][y+1])
					{
						ok[x][y+1]=true;
						que.push(P(x,y+1));
					}
				}
			}
			if(cnt!=n*m)
			{
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	return 0;
}