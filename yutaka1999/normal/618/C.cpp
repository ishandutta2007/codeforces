#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

PP pos[SIZE];

bool online(P p,P q,P r)
{
	ll a=q.first-p.first,b=q.second-p.second;
	ll c=r.first-p.first,d=r.second-p.second;//cd!=0
	//ab==0||a/b!=c/d
	if(a*b==0||a*d!=b*c) return true;
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		pos[i]=PP(P(x,y),i);
	}
	sort(pos,pos+n);
	int s=0,t=1;
	P q=pos[s].first,r=pos[t].first;
	for(int i=2;i<n;i++)
	{
		P p=pos[i].first;
		if(q.first==r.first)
		{
			if(q.first!=p.first)
			{
				printf("%d %d %d\n",pos[s].second+1,pos[t].second+1,pos[i].second+1);
				break;
			}
		}
		else if(q.second==r.second)
		{
			if(q.second!=p.second)
			{
				printf("%d %d %d\n",pos[s].second+1,pos[t].second+1,pos[i].second+1);
				break;
			}
		}
		else if(online(q,p,r))
		{
			printf("%d %d %d\n",pos[s].second+1,pos[t].second+1,pos[i].second+1);
			break;
		}
	}
	return 0;
}