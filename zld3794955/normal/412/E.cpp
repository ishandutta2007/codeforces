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
const int N=1000100;
char ch[N]={}; 
int l=0,d[N]={},tot=0;
int last[N]={},next[N]={},ltot[N]={},rtot[N]={};
long long ans=0;
int main()
{	
	gets(ch+1);
	l=strlen(ch+1);
	for(int i=1,t=0;i<=l;++i)
	{
		if(islower(ch[i]))
			++t;
		if(ch[i]=='@')
			ltot[i]=t;
		if(ch[i]=='@' || ch[i]=='.')
			t=0;
	}
	for(int i=l,t=0;i>=1;--i)
	{
		if(ch[i]=='.')
		{
			d[++tot]=i;
			rtot[i]=t;
		}
		if(islower(ch[i]))
			++t;
		else
			t=0;
	}
	for(int T=1;T<=tot;++T)
	{
		int s=d[T];
		if(!isalnum(ch[s-1]))
			continue;
		for(int i=s-2;i>=1;--i)
		{
			if(ch[i]=='@')
				ans+=(long long)ltot[i]*rtot[s];
			if(!isalnum(ch[i]))
				break;
		}
	}
	cout<<ans<<endl;
	return 0;
}