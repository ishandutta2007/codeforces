#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
char ch[1010000]={};
int l,pos=0;
long long S=0;
int main()
{	
	gets(ch);
	l=strlen(ch);
	for(int i=0;i<l;++i)
		if(ch[i]=='^')
		{
			pos=i;
			break;
		}
	for(int i=0;i<l;++i)
		if(isdigit(ch[i]))
			S+=(i-pos)*(ch[i]-'0');
	if(S<0)
		puts("left");
	if(S==0)
		puts("balance");
	if(S>0)
		puts("right");
	return 0;
}