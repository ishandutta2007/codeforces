#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 1000005

using namespace std;

int par[SIZE];
int m1[SIZE],m2[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	par[0]=-1;
	memset(m1,0,sizeof(m1));
	memset(m2,0,sizeof(m2));
	for(int i=1;i<=n;i++)
	{
		int p;
		scanf("%d",&p);p--;
		par[i]=p;
		int val=1,bef=-1;
		for(int j=p;j!=-1;j=par[j])
		{
			int g=max(m2[j]+1,m1[j]);
			if(m1[j]==bef) m1[j]=val;
			else
			{
				if(val>m1[j])
				{
					m2[j]=m1[j];
					m1[j]=val;
				}
				else if(val>m2[j])
				{
					m2[j]=val;
				}
			}
			val=max(m2[j]+1,m1[j]);
			if(g==val) break;
			bef=g;
		}
		printf("%d\n",m1[0]);
	}
	//for(int i=0;i<=n;i++) printf("%d %d\n",m1[i],m2[i]);
	return 0;
}