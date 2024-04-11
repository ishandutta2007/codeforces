#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 32
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;

int B[SIZE],K[SIZE],P[SIZE];
ll mx;
int n,u,r;

void dfs(int pos,bool flip,vector <int> N)
{
	if(pos<=u&&(u-pos)%2==0)
	{
		ll score=0;
		for(int i=0;i<n;i++) score+=(ll) N[i]*(ll) K[i];
		mx=max(mx,score);
	}
	if(pos==u) return;
	vector <int> M;
	for(int i=0;i<n;i++) M.push_back(N[P[i]]+r);
	dfs(pos+1,true,M);
	if(flip)
	{
		for(int i=0;i<n;i++) M[i]=N[i]^B[i];
		dfs(pos+1,false,M);
	}
}
int main()
{
	scanf("%d %d %d",&n,&u,&r);
	vector <int> A;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		A.push_back(a);
	}
	for(int i=0;i<n;i++) scanf("%d",&B[i]);
	for(int i=0;i<n;i++) scanf("%d",&K[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&P[i]);
		P[i]--;
	}
	mx=-INF;
	dfs(0,true,A);
	printf("%I64d\n",mx);
	return 0;
}