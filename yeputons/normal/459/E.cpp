#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#define tr(c,i) for(typeof(c).begin() i = (c).begin(); i != (c).end(); i++)
using namespace std;
struct edge
{
	int u,v,w;
};
bool sorter(const edge &x,const edge &y)
{
	return x.w<y.w;
};
int main()
{
	int n,m;
	cin>>n>>m;
	vector <edge> A(m);
	for (int i = 0; i < m; ++i)
	{
		cin>>A[i].u>>A[i].v>>A[i].w;
	}
	vector <int> ans(n+1,0);
	int s=0;
	sort(A.begin(), A.end(),sorter);
	for (int i = 0; i < m; ++i)
	{
		if(A[i].w>A[s].w)
		{
			vector < pair <int,int> > upd;
			for (int j = s; j < i; ++j)
			{
				upd.push_back(pair <int,int> (A[j].v,1+ans[A[j].u]));
			}
			for (int j = 0; j < upd.size(); ++j)
			{
				ans[upd[j].first]=max(ans[upd[j].first],upd[j].second);
			}
			s=i;
		}
	}
	vector < pair <int,int> > upd;
	for (int i = s; i < m; ++i)
	{
		upd.push_back(pair <int,int> (A[i].v,1+ans[A[i].u]));
	}
	for (int i = 0; i < upd.size(); ++i)
	{
		ans[upd[i].first]=max(ans[upd[i].first],upd[i].second);
	}
	int fans=0;
	for (int i = 0; i < n+1; ++i)
	{
		fans=max(fans,ans[i]);
	}
	cout<<fans<<"\n";
	return 0;
}