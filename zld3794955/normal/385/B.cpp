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
char ch[5050]={};
int l,t=0,ans=0;
int main()
{	
	gets(ch+1);
	l=strlen(ch+1);
	for(int i=1;i<=l;++i)
		for(int j=i;j<=l;++j)
		{
			if(t==3 && ch[j]=='r')
				++t;
			else if(t==2 && ch[j]=='a')
				++t;
			else if(t==1 && ch[j]=='e')
				++t;
			else t=0;
			if(t==0 && ch[j]=='b')
				++t;
			if(t==4)
			{
				ans+=l-j+1;
				break;
			}
		}
	cout<<ans<<endl;
	return 0;
}