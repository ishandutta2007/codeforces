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
const int N=100010;
char s[N]={},t[N]={};
int n;
int main()
{	
	gets(s+1);
	gets(t+1);
	n=strlen(s+1);
	int sum=0;
	for(int i=1;i<=n;++i)
		sum+=s[i]!=t[i];
	if(sum%2)
		puts("impossible");
	else
	{
		int d=sum/2;
		for(int i=1;i<=n;++i)
		{
			if(s[i]==t[i])
				putchar(s[i]);
			else
				if(d)
				{
					--d;
					putchar(s[i]);
				}
				else
					putchar(t[i]);
		}
		putchar('\n');
	}
	return 0;
}