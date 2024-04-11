#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <functional>
#include <string>
#include <set>
#include <map>
#define SIZE 100005
#define MX 25

using namespace std;
typedef long long int ll;
typedef pair <int,ll> P;

vector <P> compress(vector <P> vec)//\[g
{
	vector <P> ans;
	for(int i=0;i<vec.size();i++)
	{
		P p=vec[i];
		if(p.first==0||(p.first==-1&&p.second==1)) continue;
		bool up=true;
		if(!ans.empty())
		{
			P q=ans[ans.size()-1];
			if(q==p) up=false;
			else if(q.second==0)
			{
				if(q.first==p.first) up=false;
			}
			else
			{
				if(q.first+1==p.first&&p.second==0) ans.pop_back();
			}
		}
		if(up) ans.push_back(p);
	}
	return ans;
}
vector <P> now[MX];
map < vector <P> , P> dp;
int mn;
int cnt;

P solve(int d=0)
{
	if(mn<=cnt)
	{
		now[d].clear();
		return P(SIZE,0);
	}
	now[d]=compress(now[d]);
	if(dp.count(now[d])!=0)
	{
		P ans=dp[now[d]];
		now[d].clear();
		return ans;
	}
	if(now[d].empty())
	{
		mn=min(mn,cnt);
		return P(0,0);
	}
	/*
	printf("%d\n",d);
	for(int i=0;i<now[d].size();i++)
	{
		P p=now[d][i];
		printf("[%d %lld] ",p.first,p.second);
	}puts("");*/
	bool up=true;
	for(int i=0;i<now[d].size();i++)
	{
		if(now[d][i].second==0&&abs(now[d][i].first)%2==1)
		{
			up=false;
		}
	}
	if(up)
	{
		for(int i=0;i<now[d].size();i++)
		{
			P p=now[d][i];
			if(abs(p.first)%2==0) now[d+1].push_back(P(p.first/2,0));
			else now[d+1].push_back(P((p.first+1)/2,0));
		}
		P ans=solve(d+1);
		ans.second<<=2;
		dp[now[d]]=ans;
		now[d].clear();
		return ans;
	}
	else
	{
		up=true;
		for(int i=0;i<now[d].size();i++)
		{
			P p=now[d][i];
			if(p.second==1||abs(p.first)!=1) up=false;
		}
		if(up)
		{
			int a=0,b=0;
			for(int i=0;i<now[d].size();i++)
			{
				P p=now[d][i];
				if(p.first==1)
				{
					a++;
					b|=1;
				}
				else
				{
					a++;
					b|=2;
				}
			}
			now[d].clear();
			return P(a,b);
		}
		//+ 2^k  add  -> goal  - 
		for(int i=0;i<now[d].size();i++)
		{
			P p=now[d][i];
			if(p.second==0)
			{
				if(abs(p.first)%2==0) now[d+1].push_back(P(p.first/2,0));
				else now[d+1].push_back(P((p.first-1)/2,0));
			}
			else
			{
				if(abs(p.first)%2==0) now[d+1].push_back(P(p.first/2,0));
				else now[d+1].push_back(P((p.first-1)/2,1));
			}
		}
		cnt++;
		P ans=solve(d+1);
		cnt--;
		ans.first++;
		ans.second<<=2;
		ans.second|=1;
		//- 2^k  add  -> goal  + 
		for(int i=0;i<now[d].size();i++)
		{
			P p=now[d][i];
			if(p.second==0)
			{
				if(abs(p.first)%2==0) now[d+1].push_back(P(p.first/2,0));
				else now[d+1].push_back(P((p.first+1)/2,0));
			}
			else
			{
				if(abs(p.first)%2==0) now[d+1].push_back(P(p.first/2,1));
				else now[d+1].push_back(P((p.first+1)/2,0));
			}
		}
		cnt++;
		P ans2=solve(d+1);
		cnt--;
		ans2.first++;
		ans2.second<<=2;
		ans2.second|=2;
		ans=min(ans,ans2);
		//+- 2^k  add  -> goal  +- 
		for(int i=0;i<now[d].size();i++)
		{
			P p=now[d][i];
			if(p.second==0)
			{
				if(abs(p.first)%2==0) now[d+1].push_back(P(p.first/2,0));
				else now[d+1].push_back(P((p.first-1)/2,1));
			}
			else
			{
				if(abs(p.first)%2==0) now[d+1].push_back(P(p.first/2,1));
				else now[d+1].push_back(P((p.first-1)/2,1));
			}
		}
		cnt+=2;
		P ans3=solve(d+1);
		cnt-=2;
		ans3.first+=2;
		ans3.second<<=2;
		ans3.second|=3;
		ans=min(ans,ans3);
		dp[now[d]]=ans;
		now[d].clear();
		return ans;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	vector <P> vec,cur;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		vec.push_back(P(x,0));
	}
	sort(vec.begin(),vec.end());
	vec=compress(vec);
	now[0]=vec;
	mn=SIZE;
	P ans=solve();
	printf("%d\n",ans.first);
	vector <int> vt;
	for(int t=1;ans.second>0;t*=2)
	{
		if(ans.second>>0&1)
		{
			vt.push_back(t);
		}
		if(ans.second>>1&1)
		{
			vt.push_back(-t);
		}
		ans.second/=4;
	}
	for(int i=0;i<vt.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",vt[i]);
	}puts("");
	return 0;
}