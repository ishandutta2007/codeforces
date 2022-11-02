#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<fstream>
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
#include<stdexcept>
#include<iomanip>
#include<functional>
using namespace std;
const int S=1010000,s=1000000;
int m,a[S]={},w[S]={},tot=0;
bool b[S]={};
void init()
{
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{	
		scanf("%d",&a[i]);
		b[a[i]]=true;
	}
}
void work()
{
	int t=0;
	for(int i=1;i<=s;++i)
	{	
		if(b[i] && !b[s+1-i])
			w[++tot]=s+1-i;
		if(b[i] && b[s+1-i])
			++t;
	}
	for(int i=1;i<=s && t;++i)
	{
		if(!b[i] && !b[s+1-i])
		{	
			w[++tot]=i;
			w[++tot]=s+1-i;
			t-=2;
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;++i)
		printf("%d ",w[i]);
	printf("\n");
}
int main()
{	
	init();
	work();
	return 0;
}