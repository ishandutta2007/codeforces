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
inline int getint()
{
	char ch;
	while(!isdigit(ch=getchar())) ;
	int x=ch-'0';
	while(isdigit(ch=getchar())) x=x*10+ch-'0';
	return x;
}
const int N=500050;
int n,a[N]={},last[N]={},next[N]={},minr[N]={};
map<int,int> t;
vector<int> ans;
set<int> s;
int main()
{	
	n=getint();
	for(int i=1;i<=n;++i)
	{
		a[i]=getint();
		last[i]=t[a[i]];
		next[last[i]]=i;
		t[a[i]]=i;
	}
	t.clear();
	s.insert(n+1);
	int l=0;
	for(int i=1;i<=n;++i)
	{
		if(++t[a[i]]==4)
		{
			ans.push_back(a[i]),ans.push_back(a[i]);
			ans.push_back(a[i]),ans.push_back(a[i]);
			t.clear();
			s.clear();
			s.insert(n+1);
			l=i;
		}
		else
			if(last[i]>l && minr[last[i]]<i)
			{
				ans.push_back(a[minr[last[i]]]),ans.push_back(a[i]);
				ans.push_back(a[minr[last[i]]]),ans.push_back(a[i]);
				t.clear();
				s.clear();
				s.insert(n+1);
				l=i;
			}
			else
			{
				minr[i]=*s.upper_bound(i);
				s.insert(next[i]);
			}
	}
	cout<<ans.size()<<endl;
	for(vector<int>::iterator it=ans.begin();it!=ans.end();++it)
		cout<<*it<<' ';
	cout<<endl;
	return 0;
}