#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#define SIZE 2005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

bool use[SIZE],fn[SIZE];
int A[SIZE];
P pos[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<2*n;i++) scanf("%d",&A[i]);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		pos[i]=P(a,b);
		use[a]=use[b]=true;
		fn[i]=false;
	}
	int t;
	scanf("%d",&t);
	if(t==2)
	{
		while(1)
		{
			int x;
			scanf("%d",&x);x--;
			if(use[x])
			{
				for(int i=0;i<m;i++)
				{
					P p=pos[i];
					if(p.first==x)
					{
						printf("%d\n",p.second+1);
						fflush(stdout);
						fn[i]=true;
						break;
					}
					else if(p.second==x)
					{
						printf("%d\n",p.first+1);
						fflush(stdout);
						fn[i]=true;
						break;
					}
				}
			}
			else
			{
				use[x]=true;
				break;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		if(fn[i]) continue;
		P p=pos[i];
		if(A[p.first]>=A[p.second])
		{
			printf("%d\n",p.first+1);
			fflush(stdout);
		}
		else
		{
			printf("%d\n",p.second+1);
			fflush(stdout);
		}
		int x;
		scanf("%d",&x);
	}
	while(1)
	{
		P p=P(-1,-1);
		for(int j=0;j<2*n;j++)
		{
			if(!use[j])
			{
				p=max(p,P(A[j],j));
			}
		}
		if(p.second==-1) break;
		printf("%d\n",p.second+1);
		fflush(stdout);
		use[p.second]=true;
		int x;
		scanf("%d",&x);x--;
		use[x]=true;
	}
	return 0;
}