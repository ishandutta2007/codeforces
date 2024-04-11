#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define MX 10005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

bool can(P p,P q,P r)//1/p.first<1/q.first<1/r.first,1/p.second>1/q.second>1/r.second
{
	return (ll) (p.second-q.second)*(ll) (p.first-r.first)*(ll) r.second*(ll) q.first>(ll) (p.second-r.second)*(ll) (p.first-q.first)*(ll) q.second*(ll) r.first;
}
int S[SIZE],R[SIZE];
int mx[MX],ans[MX];
P pos[MX];

int main()
{
	int n;
	scanf("%d",&n);
	memset(mx,-1,sizeof(mx));
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&S[i],&R[i]);
		mx[S[i]]=max(mx[S[i]],R[i]);
	}
	int sz=0;
	for(int i=MX-1;i>=1;i--)
	{
		if(mx[i]==-1) continue;
		P p=P(i,mx[i]);
		if(sz==0) pos[sz++]=p;
		else if(pos[sz-1].second<mx[i])
		{
			while(sz>=2&&can(pos[sz-2],pos[sz-1],p)) sz--;
			pos[sz++]=p;
		}
	}
	memset(ans,-1,sizeof(ans));
	for(int i=0;i<sz;i++) ans[pos[i].first]=pos[i].second;
	//vector <int> vec;
	for(int i=0;i<n;i++)
	{
		if(ans[S[i]]==R[i])
		{
			printf("%d ",i+1);
		}
	}
	puts("");
	return 0;
}