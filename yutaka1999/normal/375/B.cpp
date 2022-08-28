#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 5005

using namespace std;

int last[SIZE][SIZE];
char str[SIZE];
int calc[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		int pos=-1;
		for(int j=m-1;j>=0;j--)
		{
			if(str[j]=='1')
			{
				if(pos==-1) pos=j;
			}
			else pos=-1;
			last[i][j]=pos;
		}
	}
	int ret=0;
	for(int i=0;i<m;i++)
	{
		memset(calc,0,sizeof(calc));
		for(int j=0;j<n;j++) if(last[j][i]!=-1) calc[last[j][i]]++;
		int now=0;
		for(int j=m-1;j>=i;j--)
		{
			now+=calc[j];
			ret=max(ret,now*(j-i+1));
		}
	}
	printf("%d\n",ret);
	return 0;
}