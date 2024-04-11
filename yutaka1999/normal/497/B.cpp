#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <functional>
#include <set>
#include <queue>
#include <stack>
#define SIZE 100005

using namespace std;
typedef pair <int,int> P;

int sumA[SIZE],sumB[SIZE];
P pos[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	int last=-1;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		last=a;
		if(a==1) sumA[i]=1;
		else sumB[i]=1;
		if(i>0)
		{
			sumA[i]+=sumA[i-1];
			sumB[i]+=sumB[i-1];
		}
	}
	int sz=0;
	for(int t=1;t<=n;t++)
	{
		int A=0,B=0;
		int now=0;
		bool up=true;
		while(now<n)
		{
			int l=now-1,r=n;
			while(r-l>1)
			{
				int m=(l+r)/2;
				int mx=max(sumA[m]-(now==0?0:sumA[now-1]),sumB[m]-(now==0?0:sumB[now-1]));
				if(mx<t) l=m;
				else r=m;
			}
			if(r==n)
			{
				up=false;
				break;
			}
			int vA=sumA[r]-(now==0?0:sumA[now-1]);
			int vB=sumB[r]-(now==0?0:sumB[now-1]);
			if(vA!=t&&vB!=t)
			{
				up=false;
				break;
			}
			if(vA==t) A++;
			else B++;
			now=r+1;
		}
		if(!up) continue;
		if(last==1)
		{
			if(A>B)
			{
				pos[sz++]=P(A,t);
			}
		}
		else
		{
			if(A<B)
			{
				pos[sz++]=P(B,t);
			}
		}
	}
	sort(pos,pos+sz);
	printf("%d\n",sz);
	for(int i=0;i<sz;i++) printf("%d %d\n",pos[i].first,pos[i].second);
	return 0;
}