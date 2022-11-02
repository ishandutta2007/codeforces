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
int l(-2000000000),r(2000000000);
int n,x=0;
char ch[10]={},ans='\0';
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>ch>>x>>ans;
		if(ans=='Y')
		{
			if(strlen(ch)==2)
			{
				if(ch[0]=='>')
					l=max(l,x);
				else
					r=min(r,x);
			}
			else
			{
				if(ch[0]=='>')
					l=max(l,x+1);
				else
					r=min(r,x-1);
			}
		}
		else
		{
			if(strlen(ch)==2)
			{
				if(ch[0]=='>')
					r=min(r,x-1);
				else
					l=max(l,x+1);
			}
			else
			{
				if(ch[0]=='>')
					r=min(r,x);
				else
					l=max(l,x);
			}
		}
	}
	if(l>r)
		cout<<"Impossible"<<endl;
	else
		cout<<l<<endl;
	return 0;
}