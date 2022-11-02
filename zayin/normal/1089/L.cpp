#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

typedef long long LL;

const int maxn=1e5+5;

int n,k,a[maxn],b[maxn];
vector<int> V[maxn];
priority_queue<int> Q;

int main()
{
	scanf("%d %d",&n,&k);
	fo(i,1,n) scanf("%d",&a[i]);
	fo(i,1,n) scanf("%d",&b[i]), V[a[i]].push_back(b[i]);
	
	fo(i,1,k)
	{
		sort(V[i].begin(),V[i].end());
		for(int j=0; j+1<V[i].size(); j++) Q.push(-V[i][j]);
	}
	
	LL ans=0;
	fo(i,1,k) if (V[i].empty())
	{
		ans+=-Q.top();
		Q.pop();
	}
	
	printf("%lld\n",ans);
}