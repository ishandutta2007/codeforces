#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
#include<string>
#include <unordered_map>
#include<vector>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<numeric>
using namespace std;
#define ll long long
#define sz(v)               ((int)((v).size()))
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define read(f) freopen (f,"r",stdin)
#define write(f) freopen (f,"w",stdout)
typedef pair<int,int> ii;

struct event
{
	int x,y;
	bool type;

	event(int x_,int y_,bool type_)
	{
		x = x_, y = y_,type = type_;
	}

	bool operator <(const event &a) const
	{
		// least x first
		if(x != a.x) return x < a.x;

		// if same x, get opening first
		if(type != a.type) return type < a.type;
		// get larger y second
		return y < a.y;
	}


};
int main()
{
	read("input.txt"); write("output.txt");
	int n;
	scanf("%d",&n);
	multiset<int> window;
	vector<event> events;
	for(int i = 0 ; i < n ; ++i)
	{
		int h,l,r;
		scanf("%d %d %d",&h,&l,&r);
		events.push_back(event(l,h,0));
		events.push_back(event(r,h,1));
	}
	sort(events.begin(),events.end());
	window.insert(0);
	vector<ii> ans;
	int i = 0;
	int sz = sz(events);

	while(i < sz)
	{
		int sweepx = events[i].x;
		// process all same x at once
		while(i < sz && sweepx == events[i].x )
		{
			if(!events[i].type)
				window.insert(events[i].y);
			else window.erase(window.find(events[i].y));
			++i;
		}
		// put max y
		ans.push_back(ii(sweepx,*window.rbegin()));
	}
	int curry = 0;
	vector<ii> res;
	REP(i,ans)
	{
		// merge
		if(ans[i].second == curry)
			continue;
		res.push_back(ii(ans[i].first,curry));
		res.push_back(ii(ans[i].first,ans[i].second));

		curry = ans[i].second;


	}
	printf("%d\n",sz(res));
	REP(i,res)
	{
		printf("%d %d\n",res[i].first,res[i].second);


	}
}