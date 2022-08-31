#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <functional>
#include <cmath>
#include <map>
#include <string>
#define SIZE 105

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char mp[3][SIZE];
bool ok[3][SIZE];
int n,k;

bool check(int t,int i,int j)
{
	if(j+2*t<n&&mp[i][j+2*t]!='.'&&mp[i][j+2*t]!='s') return false;
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&k);
		for(int i=0;i<3;i++) scanf("%s",&mp[i]);
		memset(ok,false,sizeof(ok));
		for(int i=0;i<3;i++) if(mp[i][0]=='s') ok[i][0]=true;
		for(int i=0;i+1<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(ok[j][i]&&check(i,j,i)&&check(i,j,i+1))
				{
					for(int t=j-1;t<=j+1;t++)
					{
						if(t>=0&&t<3&&check(i,t,i+1)) ok[t][i+1]=true;
					}
				}
			}
		}
		bool up=false;
		for(int i=0;i<3;i++)
		{
			if(ok[i][n-1]&&check(n,i,n-1))
			{
				puts("YES");
				up=true;
				break;
			}
		}
		if(!up) puts("NO");
	}
	return 0;
}