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
const int N=1000010;
char ch[N]={};
int n,a,b,c1[N]={};
void init()
{
	gets(ch+1);
	n=strlen(ch+1);
	cin>>a>>b;
	for(int i=1;i<=n;++i)
		c1[i]=(c1[i-1]*10+ch[i]-'0')%a;
}
void work()
{
	int s=0,d=1;
	for(int i=n;i>1;--i)
	{
		s=(s+d*(ch[i]-'0'))%b;
		d=d*10%b;
		if(ch[i]!='0' && s==0 && c1[i-1]==0)
		{
			puts("YES");
			for(int j=1;j<i;++j)
				putchar(ch[j]);
			putchar('\n');
			for(int j=i;j<=n;++j)
				putchar(ch[j]);
			putchar('\n');
			return;
		}
	}
	puts("NO");
}
int main()
{	
	init();
	work();
	return 0;
}