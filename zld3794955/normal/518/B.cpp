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
const int V=150,L=200200;
int t1[V]={},t2[V]={};
char c1[L]={},c2[L]={};
void init()
{
	gets(c1+1);
	gets(c2+1);
	for(int i=strlen(c1+1);i>=1;--i)
		++t1[(int)c1[i]];
	for(int i=strlen(c2+1);i>=1;--i)
		++t2[(int)c2[i]];
}
void work()
{
	int ans1=0,ans2=0;
	for(int ch=(int)'A';ch<=(int)'z';++ch)
	{
		int d=min(t1[ch],t2[ch]);
		ans1+=d;
		t1[ch]-=d;
		t2[ch]-=d;
	}
	for(int ch=(int)'A';ch<=(int)'Z';++ch)
	{
		ans2+=min(t1[ch],t2[(int)tolower(ch)]);
		t1[ch]-=min(t1[ch],t2[(int)tolower(ch)]);
	}
	for(int ch=(int)'a';ch<=(int)'z';++ch)
	{
		ans2+=min(t1[ch],t2[(int)toupper(ch)]);
		t1[ch]-=min(t1[ch],t2[(int)toupper(ch)]);
	}
	cout<<ans1<<' '<<ans2<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}