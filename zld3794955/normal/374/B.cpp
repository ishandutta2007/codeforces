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
const char nine='0'+'0'+9;
char ch[101000]={};
long long ans=1;
int l=0,t=1;
int main()
{	
	gets(ch+1);
	l=strlen(ch+1);
	for(int i=1;i<=l;++i)
		if(ch[i]+ch[i+1]==nine)
			++t;
		else
		{
			if(t&1)
				ans*=t/2+1;
			t=1;
		}
	cout<<ans<<endl;
	return 0;
}