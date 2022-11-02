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
int n,m,a[110]={},ans=0;
int u,v,l;
int main()
{	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&l);
		a[u]-=l;
		a[v]+=l;
	}
	for(int i=1;i<=n;++i)
		ans+=max(a[i],0);
	printf("%d\n",ans);
	return 0;
}