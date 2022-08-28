#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define SIZE 2205
#define INF 1000000005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <int,P> PP;

int A[SIZE],B[SIZE];
bool na[SIZE],nb[SIZE];
int tg[SIZE];
P mn[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int j=0;j<n;j++) scanf("%d",&B[j]);
	vector <int> va,vb;
	ll ret=0;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
		{
			mn[j]=P(INF,j);
			if(!na[j]) mn[j]=P(A[j],j);
			if(j>0) mn[j]=min(mn[j],mn[j-1]);
		}
		for(int j=0;j<n;j++) tg[j]=j;
		sort(va.begin(),va.end());
		sort(vb.begin(),vb.end());
		for(int j=0;j<i;)
		{
			int now=va[j];
			int to=vb[j];
			for(;j<i&&va[j]<=to;j++) to=vb[j];
			for(int k=now;k<=to;k++) tg[k]=to;
		}
		PP add=PP(INF*2,P(-1,-1));
		for(int j=0;j<n;j++)
		{
			if(!nb[j])
			{
				P p=mn[tg[j]];
				if(p.first!=INF)
				{
					int to=p.second;
					add=min(add,PP(A[to]+B[j],P(to,j)));
				}
			}
		}
		ret+=add.first;
		int a=add.second.first,b=add.second.second;
		va.push_back(a);
		vb.push_back(b);
		na[a]=nb[b]=true;
	}
	printf("%lld\n",ret);
	return 0;
}