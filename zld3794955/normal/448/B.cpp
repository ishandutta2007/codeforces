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
char s[110]={},t[110]={};
int ls,lt;
bool automaton_only()
{
	int pos=1;
	for(int i=1;i<=lt;++i)
	{
		while(pos<=ls && s[pos]!=t[i])
			++pos;
		if(pos>ls)
			return false;
		++pos;
	}
	return true;
}
bool array_only()
{
	int sv[150]={},tv[150]={};
	for(int i=1;i<=ls;++i)
		++sv[(int)s[i]];
	for(int i=1;i<=lt;++i)
		++tv[(int)t[i]];
	for(int i=0;i<=128;++i)
		if(sv[i]!=tv[i])
			return false;
	return true;
}
bool both()
{
	int sv[150]={},tv[150]={};
	for(int i=1;i<=ls;++i)
		++sv[(int)s[i]];
	for(int i=1;i<=lt;++i)
		++tv[(int)t[i]];
	for(int i=0;i<=128;++i)
		if(sv[i]<tv[i])
			return false;
	return true;
}
int main()
{	
	gets(s+1);
	gets(t+1);
	ls=strlen(s+1);
	lt=strlen(t+1);
	if(automaton_only())
		puts("automaton");
	else
		if(array_only())
			puts("array");
		else
			if(both())
				puts("both");
			else
				puts("need tree");
	return 0;
}