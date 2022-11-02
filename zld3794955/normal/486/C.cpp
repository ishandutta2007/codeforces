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
const int N=100010;
int n,p,f[N]={},l[N]={};
char ch[N]={};
void init()
{
	scanf("%d %d\n",&n,&p);
	scanf("%s",ch+1);
}
inline int delta(int c1,int c2)
{
	//cout<<c1<<' '<<c2<<endl;
	return c1>c2 ? c1-c2 : c2-c1;
}
void work()
{
	int s1=0,l1=0,s2=0,l2=0;
	if(p>n/2)
		p=n+1-p;
	//cout<<"p="<<p<<endl;
	for(int i=p;i>=1;--i)
	{
		if(ch[i]!=ch[n+1-i])
			l1=p-i;
		int d=delta(ch[i],ch[n+1-i]);
		//cout<<"d="<<d<<endl;
		s1+=min(d,26-d);
		//cout<<"s1="<<s1<<endl;
	}
	//cout<<"s1="<<s1<<" l1="<<l1<<endl;
	for(int i=p+1;i<=n/2;++i)
	{
		if(ch[i]!=ch[n+1-i])
			l2=i-p;
		int d=delta(ch[i],ch[n+1-i]);
		s2+=min(d,26-d);
	}
	//cout<<"s2="<<s2<<" l2="<<l2<<endl;
	printf("%d\n",s1+s2+l1+l2+min(l1,l2));
}
int main()
{	
	init();
	work();
	return 0;
}