#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
int t,a[10][10]={},x[3],y[3],tot=0;
void init()
{
	char ch[10]={};
	tot=0;
	for(int i=1;i<=8;++i)
	{	
		gets(ch);
		for(int j=0;j<8;++j)
		{
			if(ch[j]=='K')
			{
				++tot;
				x[tot]=i;
				y[tot]=j+1;
				a[i][j+1]=0;
			}
			if(ch[j]=='.')
				a[i][j+1]=0;
			if(ch[j]=='#')
				a[i][j+1]=1;
		}
	}
	gets(ch);
}
inline bool check()
{
	if((x[1]-x[2])%4)
		return false;
	if((y[1]-y[2])%4)
		return false;
	int dx=(x[1]-1)%2,dy=(y[1]-1)%2;
	for(int i=1;i<=8;i+=2)
		for(int j=1;j<=8;j+=2)
			if(a[i+dx][j+dy]==0)
				return true;
	return false;
}
int main()
{	
	scanf("%d\n",&t);
	while(t--)
	{
		init();
		if(check())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}