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
const char ch1[]="qwertyuiop";
const char ch2[]="asdfghjkl;";
const char ch3[]="zxcvbnm,./";
const int L=110;
char dir,ch[L]={};
int main()
{	
	cin>>dir;
	cin>>(ch+1);
	int l=strlen(ch+1);
	for(int i=1;i<=l;++i)
	{
		if(count(ch1,ch1+10,ch[i]))
		{
			int t=find(ch1,ch1+10,ch[i])-ch1;
			if(dir=='L')
				++t;
			else
				--t;
			ch[i]=ch1[t];
		}
		if(count(ch2,ch2+10,ch[i]))
		{
			int t=find(ch2,ch2+10,ch[i])-ch2;
			if(dir=='L')
				++t;
			else
				--t;
			ch[i]=ch2[t];
		}
		if(count(ch3,ch3+10,ch[i]))
		{
			int t=find(ch3,ch3+10,ch[i])-ch3;
			if(dir=='L')
				++t;
			else
				--t;
			ch[i]=ch3[t];
		}
	}
	cout<<(ch+1)<<endl;
	return 0;
}