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
const int x_[4]={0,1,0,-1};
const int y_[4]={1,0,-1,0};
int n,m,G[1010]={},S[1010]={},d[1010]={};
char ch[1010][1010]={};
void init()
{
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s\n",ch[i]+1);
}
bool check()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(ch[i][j]=='G')
				G[i]=j;
			if(ch[i][j]=='S')
				S[i]=j;
		}
	for(int i=1;i<=n;++i)
		if(S[i]<G[i])
			return false;
		else
			d[i]=S[i]-G[i];
	return true;
}
void work()
{
	int ans=0;
	sort(d+1,d+n+1);
	for(int i=1;i<=n;++i)
		if(d[i]!=d[i-1])
			++ans;
	printf("%d\n",ans);
}
int main()
{	
	init();
	if(check())
		work();
	else
		printf("-1\n");
	return 0;
}