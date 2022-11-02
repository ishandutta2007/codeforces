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
const int N=1010;
int n,p;
char u[N+N]={},*ch=&u[N];
bool one=false,flag=false,v[N]={};
void tryy(int t)
{	
	if(t>n)
	{
		if(one)
			flag=true;
		else
			one=true;
		return;
	}
	int start=v[t] ? 'a' : ch[t];
	for(int i=start;i<'a'+p;++i)
	{
		ch[t]=i;
		if(ch[t]==ch[t-2] || ch[t]==ch[t-1])
			continue;
		tryy(t+1);
		if(flag)
			return;
	}
	v[t]=true;
}
int main()
{	
	scanf("%d%d\n",&n,&p);
	scanf("%s\n",ch+1);
	tryy(1);
	if(flag)
		printf("%s\n",ch+1);
	else
		printf("NO\n");
	return 0;
}