#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;

int p[SIZE];
bool use[SIZE],ex[SIZE];
vector < vector <int> > vec[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	int cnt=0;
	vector <int> tp;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&p[i]);p[i]--;
		if(p[i]==i)
		{
			cnt++;
			tp.push_back(i);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(p[i]!=i&&!use[i])
		{
			int now=i,len=0;
			vector <int> nd;
			do
			{
				use[now]=true;
				nd.push_back(now);
				len++;
				now=p[now];
			}while(now!=i);
			ex[len]=true;
			vec[len].push_back(nd);
		}
	}
	int nm=0;
	for(int i=2;i<=n;i++) nm+=ex[i];
	if(cnt>=1)
	{
		puts("YES");
		for(int i=0;i+1<tp.size();i++)
		{
			printf("%d %d\n",tp[i]+1,tp[i+1]+1);
		}
		for(int i=2;i<=n;i++)
		{
			if(ex[i])
			{
				for(int j=1;j<vec[i].size();j++)
				{
					for(int k=0;k<i;k++)
					{
						printf("%d %d\n",vec[i][0][k]+1,vec[i][j][k]+1);
					}
				}
				for(int j=0;j<i;j++)
				{
					printf("%d %d\n",vec[i][0][j]+1,tp[0]+1);
				}
			}
		}
	}
	else if(ex[2])
	{
		for(int i=2;i<=n;i++)
		{
			if(i%2==1&&ex[i])
			{
				puts("NO");
				return 0;
			}
		}
		puts("YES");
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<vec[i].size();j++)
			{
				if(i==2&&j==0) continue;
				for(int k=0;k<vec[i][j].size();k++)
				{
					printf("%d %d\n",vec[2][0][k%2]+1,vec[i][j][k]+1);
				}
			}
		}
		printf("%d %d\n",vec[2][0][0]+1,vec[2][0][1]+1);
	}
	else
	{
		puts("NO");
	}
	return 0;
}