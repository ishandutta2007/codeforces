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
char ch[2020]={};
int n; 
int main()
{	
	scanf("%d\n",&n);
	scanf("%s\n",ch+1);
	int t1=0,t2=0;
	for(int i=1;i<=n;++i)
		((ch[i]=='x') ? t1 : t2)+=1;
	if(t1<t2)
	{
		int t=n/2-t1;
		printf("%d\n",t);
		for(int i=1;i<=n && t;++i)
			if(ch[i]=='X')
			{
				ch[i]='x';
				--t;
			}
		printf("%s\n",ch+1);
	}
	else
	{
		int t=n/2-t2;
		printf("%d\n",t);
		for(int i=1;i<=n && t;++i)
			if(ch[i]=='x')
			{
				ch[i]='X';
				--t;
			}
		printf("%s\n",ch+1);
	}
	return 0;
}