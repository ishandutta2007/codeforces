#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <set>
#include <queue>
#include <stack>
#define SIZE 1005

using namespace std;
typedef pair <int,int> P;

char mp[SIZE][SIZE];
int tg[SIZE],nt[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",&mp[i]);
	memset(tg,0,sizeof(tg));
	int cnt=0;
	for(int i=0;i<m;i++)
	{
		bool up=true;
		P bef=P(-1,-1);
		int now=-1;
		for(int j=0;j<n;j++)
		{
			P p=P(tg[j],mp[j][i]-'a');
			if(p<bef)
			{
				up=false;
				break;
			}
			if(bef<p)
			{
				now++;
				bef=p;
			}
			nt[j]=now;
		}
		if(!up) cnt++;
		else
		{
			for(int j=0;j<n;j++) tg[j]=nt[j];
		}
	}
	printf("%d\n",cnt);
	return 0;
}