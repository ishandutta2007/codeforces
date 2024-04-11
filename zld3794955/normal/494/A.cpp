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
#include<numeric>
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
const int L=100010;
char ch[L]={};
int n,tot=0,ans=0,s=0,last=0;
int main()
{	
	gets(ch+1);
	n=strlen(ch+1);
	for(int i=1;i<=n;++i)
	{
		if(ch[i]=='(')
			++s;
		if(ch[i]==')')
		{
			if((--s)<0)
			{
				puts("-1");
				return 0;
			}
		}
		if(ch[i]=='#')
		{
			++tot;
			last=i;
			if((--s)<0)
			{
				puts("-1");
				return 0;
			}
		}
	}
	ans=s+1;
	s=0;
	for(int i=1;i<=n;++i)
	{
		if(ch[i]=='(')
			++s;
		if(ch[i]==')')
		{
			if((--s)<0)
			{
				puts("-1");
				return 0;
			}
		}
		if(ch[i]=='#')
		{
			if(last==i)
				s-=ans;
			else
				--s;
			if(s<0)
			{
				puts("-1");
				return 0;
			}
		}
	}
	if(s)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<tot;++i)
		puts("1");
	cout<<ans<<endl;
	return 0;
}