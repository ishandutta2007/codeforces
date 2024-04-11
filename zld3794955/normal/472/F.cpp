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
const int N=10010,B=30;
int n,x[N]={},y[N]={};
vector<pair<int,int> > ans1,ans2;
void get_base_y()
{
	for(int d=B,pos=1;d>=0 && pos<=n;--d)
	{
		if((y[pos]&(1<<d))==0)
			for(int i=pos+1;i<=n;++i)
				if(y[i]&(1<<d))
				{
					y[pos]^=y[i];
					ans1.push_back({pos,i});
					break;
				}
		if((y[pos]&(1<<d))==0)
			continue;
		for(int i=1;i<=n;++i)
			if(i!=pos && (y[i]&(1<<d)))
			{
				y[i]^=y[pos];
				ans1.push_back({i,pos});
			}
		++pos;
	}
}
void get_base_x()
{
	for(int d=B,pos=1;d>=0 && pos<=n;--d)
	{
		if((x[pos]&(1<<d))==0)
			for(int i=pos+1;i<=n;++i)
				if(x[i]&(1<<d))
				{
					x[pos]^=x[i];
					ans2.push_back({pos,i});
					break;
				}
		if((x[pos]&(1<<d))==0)
			continue;
		for(int i=1;i<=n;++i)
			if(i!=pos && ((x[i]^y[i])&(1<<d)))
			{
				x[i]^=x[pos];
				ans2.push_back({i,pos});
			}
		if((y[pos]&(1<<d))==0)
		{
			ans2.push_back({pos,pos});
			x[pos]=0;
			continue;
		}
		++pos;
	}
}
bool check()
{
	for(int i=1;i<=n;++i)
		if(x[i]!=y[i])
			return false;
	return true;
}
//Learn from zhj's code. OrzOrz
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&x[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&y[i]);
	get_base_y();
	get_base_x();
	if(check())
	{
		reverse(ans1.begin(),ans1.end());
		cout<<ans1.size()+ans2.size()<<endl;
		for(auto p:ans2)
			printf("%d %d\n",p.first,p.second);
		for(auto p:ans1)
			printf("%d %d\n",p.first,p.second);
	}
	else
		puts("-1");
	return 0;
}