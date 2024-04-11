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
int n,a[1010][1010]={},q,ans=0,tot=0;
char ch[1010000]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;++i)
		ans+=a[i][i];
	ans%=2;
}
void work()
{
	scanf("%d",&q);
	int k,x;
	for(int i=1;i<=q;++i)
	{
		scanf("%d",&k);
		if(k==1 || k==2)
		{
			scanf("%d",&x);
			ans=1-ans;
		}
		if(k==3)
			ch[++tot]=ans+'0';
	}
	puts(ch+1);
}
int main()
{	
	init();
	work();
	return 0;
}