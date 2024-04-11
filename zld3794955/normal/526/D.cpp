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
const int L=1000100,K=1000100;
int n,t[L]={};
long long k,next[L]={};
char ch[L]={},ans[L]={};
void init()
{
	cin>>n>>k>>(ch+1);
	next[1]=0;
	for(int i=2,k=0;i<=n;++i)
	{
		while(k && ch[i]!=ch[k+1])
			k=next[k];
		if(ch[i]==ch[k+1])
			++k;
		next[i]=k;
	}
	//for(int i=1;i<=n;++i)
	//	cout<<next[i]<<' ';
	//cout<<endl;
}
void work()
{
	for(int i=1;i<=n;++i)
		t[i]=i;
	for(int i=n;i>=1;--i)
	{
		int p=t[i];
		while((i-p)*(k+1)<i)
			p=next[p];
		if((i-p)*k<=i)
			ch[i]='1';
		else
			ch[i]='0';
		t[next[i]]=min(p,t[next[i]]);
	}
	puts(ch+1);
}
int main()
{	
	init();
	work();
	return 0;
}