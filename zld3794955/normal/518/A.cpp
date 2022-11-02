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
const int L=110;
char c1[L]={},c2[L]={};
int main()
{	
	gets(c1+1);
	gets(c2+1);
	int l=strlen(c1+1);
	for(int i=l;i>=1;--i)
	{
		if(c1[i]=='z')
			c1[i]='a';
		else
		{
			++c1[i];
			break;
		}
	}
	if(lexicographical_compare(c1+1,c1+l+1,c2+1,c2+l+1))
		puts(c1+1);
	else
		puts("No such string");
	return 0;
}