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

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE];
int L[SIZE],R[SIZE];
vector <P> vec[SIZE];
int n,d,b;

bool solve(int x)
{
	int s=x,t=n-x-1;
	if(s>t) return true;
	priority_queue <P,vector <P>,greater <P> > que;
	for(int i=0;i<=t;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			P p=vec[i][j];
			que.push(p);
		}
		if(i>=s)
		{
			int zan=b;
			while(zan>0&&!que.empty())
			{
				P p=que.top();que.pop();
				if(p.first>=i)
				{
					if(p.second>zan)
					{
						p.second-=zan;
						que.push(p);
						zan=0;
						break;
					}
					else
					{
						zan-=p.second;
					}
				}
			}
			if(zan!=0) return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d %d %d",&n,&d,&b);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&A[i]);
		int f=i/(d+1);
		L[i]=f;
		int x=(n-i-1)/(d+1);
		R[i]=n-x-1;
		vec[L[i]].push_back(P(R[i],A[i]));
	}
	int l=-1,r=n+1;
	while(r-l>1)
	{
		int m=(l+r)/2;
		if(solve(m)) r=m;
		else l=m;
	}
	printf("%d\n",r);
	return 0;
}