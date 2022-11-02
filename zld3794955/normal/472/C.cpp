#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100010,L=55;
int n,p[N]={},c[N]={};
char ch[2][N][L]={};
void init()
{
	scanf("%d\n",&n);
	for(int i=1;i<=n;++i)
		scanf("%s %s\n",ch[0][i]+1,ch[1][i]+1);
	for(int i=1;i<=n;++i)
		scanf("%d",&p[i]);
}
void work()
{
	c[p[1]]=strcmp(ch[0][p[1]]+1,ch[1][p[1]]+1)>0;
	for(int i=2;i<=n;++i)
	{
		if(strcmp(ch[0][p[i]]+1,ch[c[p[i-1]]][p[i-1]]+1)<0)
		{
			if(strcmp(ch[1][p[i]]+1,ch[c[p[i-1]]][p[i-1]]+1)<0)
			{
				puts("NO");
				return;
			}
			else
				c[p[i]]=1;
		}
		else
			if(strcmp(ch[1][p[i]]+1,ch[c[p[i-1]]][p[i-1]]+1)<0)
				c[p[i]]=0;
			else
				c[p[i]]=strcmp(ch[0][p[i]]+1,ch[1][p[i]]+1)>0;
	}
	puts("YES");
}
int main()
{	
	init();
	work();
	return 0;
}