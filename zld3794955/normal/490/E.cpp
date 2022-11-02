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
const int N=100100,L=15;
int n;
char ch[N][L]={};
void init()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>(ch[i]+1);
}
bool tryy(int i,int t,int l)
{
	if(t>l)
	{
		for(int j=1;j<=l;++j)
			if(ch[i][j]>ch[i-1][j])
				return true;
		return false;
	}
	if(isdigit(ch[i][t]))
	{
		if(ch[i][t]<ch[i-1][t])
			return false;
		if(ch[i][t]>ch[i-1][t])
			return true;
		return tryy(i,t+1,l);
	}
	else
	{
		ch[i][t]=ch[i-1][t];
		if(tryy(i,t+1,l))
			return true;
		else
		{
			ch[i][t]='?';
			if(ch[i-1][t]=='9')
				return false;
			ch[i][t]=ch[i-1][t]+1;
			return true;
		}
	}
}
void work()
{
	int l=0;
	for(int i=1;i<=n;++i)
	{
		int nl=strlen(ch[i]+1);
		if(nl<l)
		{
			puts("NO");
			return;
		}
		if(nl>l)
		{
			for(int j=1;j<=nl;++j)
				if(ch[i][j]=='?')
					ch[i][j]=j==1 ? '1' : '0';
		}
		if(nl==l)
		{
			if(!tryy(i,1,l))
			{
				puts("NO");
				return;
			}
			for(int j=1;j<=l;++j)
				if(ch[i][j]=='?')
					ch[i][j]='0';
		}
		l=nl;
	}
	puts("YES");
	for(int i=1;i<=n;++i)
		puts(ch[i]+1);
}
int main()
{	
	init();
	work();
	return 0;
}