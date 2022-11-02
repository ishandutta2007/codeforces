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
const int N=110;
char ch[N]={};
int k,l;
void init()
{
	cin>>(ch+1)>>k;
	l=strlen(ch+1);
}
void work()
{
	for(int i=1;i<=l && k;++i)
	{
		int r=min(k,l-i),pos=i;
		for(int j=i;j<=i+r;++j)
			if(ch[j]>ch[pos])
				pos=j;
		for(int j=pos;j>i;--j)
		{
			swap(ch[j],ch[j-1]);
			--k;
		}
	}
	cout<<(ch+1)<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}