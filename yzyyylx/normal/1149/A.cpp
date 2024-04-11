#include<bits/stdc++.h>
#define N 400100
#define MN 400000
using namespace std;

int n,zz,sum,zs[N],num[N],cnt[3];
bool P[N];
vector<int>ans;

inline void get()
{
	int i,j;
	P[1]=1;
	for(i=2;i<=MN;i++)
	{
		if(!P[i]) zs[++zz]=i;
		for(j=1;j<=zz;j++)
		{
			int t=zs[j]*i;
			if(t>MN) break;
			P[t]=1;
			if(i%zs[j]==0) break;
		}
	}
}

int main()
{
	get();
	int i,j,t;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		cnt[num[i]]++;
	}
	if(cnt[2]) ans.push_back(2);
	if(cnt[1]) ans.push_back(1);
	for(i=2;i<=cnt[2];i++) ans.push_back(2);
	for(i=2;i<=cnt[1];i++) ans.push_back(1);
	for(i=0;i<ans.size();i++) printf("%d ",ans[i]);
}