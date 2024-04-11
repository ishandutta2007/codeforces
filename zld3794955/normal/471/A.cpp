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
int a[6]={};
int main()
{	
	for(int i=0;i<=5;++i)
		cin>>a[i];
	for(int l=0;l<=9;++l)
	{
		int t=0,x=0;
		for(int i=0;i<=5;++i)
			t+=a[i]==l;
		if(t==6)
		{
			puts("Elephant");
			return 0;
		}
		if(t==5)
		{
			puts("Bear");
			return 0;
		}
		if(t==4)
		{
			for(int i=0;i<=5;++i)
				if(a[i]!=l)
				{
					if(x)
					{
						puts(x==a[i] ? "Elephant" : "Bear");
						return 0;
					}
					else
						x=a[i];
				}
		}
	}
	puts("Alien");
	return 0;
}