#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;

vector <int> vec[SIZE];
bool use[SIZE];
int col[SIZE];

int main()
{
	int n,m;
	int ret=0,pos=SIZE;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&col[i]);
		pos=min(pos,col[i]--);
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		a=col[a],b=col[b];
		if(a==b) continue;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for(int i=0;i<SIZE;i++)
	{
		if(vec[i].size()>0)
		{
			int sum=0;
			memset(use,false,sizeof(use));
			for(int j=0;j<vec[i].size();j++)
			{
				if(!use[vec[i][j]])
				{
					sum++;
					use[vec[i][j]]=true;
				}
			}
			if(ret<sum)
			{
				ret=sum;
				pos=i+1;
			}
		}
	}
	printf("%d\n",pos);
	return 0;
}