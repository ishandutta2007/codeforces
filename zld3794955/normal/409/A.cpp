#include<iostream>
#include<cstdio>
#include<algorithm>
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
char c1[30]={},c2[30]={};
int t1=0,t2=0;
int main()
{	
	gets(c1);
	gets(c2);
	int l=strlen(c1);
	for(int i=0;i!=l;i+=2)
	{
		int x1=0,x2=0;
		if(c1[i]=='(' && c1[i+1]==')')
			x1=0;
		else
			if(c1[i]=='[' && c1[i+1]==']')
				x1=1;
			else
				x1=2;
		if(c2[i]=='(' && c2[i+1]==')')
			x2=0;
		else
			if(c2[i]=='[' && c2[i+1]==']')
				x2=1;
			else
				x2=2;
		if(((x1-x2)+3)%3==1)
			++t1;
		if(((x1-x2)+3)%3==2)
			++t2;
	}
	if(t1<t2)
		puts("TEAM 2 WINS");
	else
		if(t1>t2)
			puts("TEAM 1 WINS");
		else
			puts("TIE");
	return 0;
}