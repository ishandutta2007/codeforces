#include<iostream>
#include<cstdio>
#include<vector>
#define N 1010
#define ll long long
using namespace std;

ll n;
vector<int>have[N];
bool P[N];

int main()
{
	register int i,j,p;
	cin>>n;
	for(i=1;i<n;i++)
	{
		scanf("%d",&p);
		P[p]=1;
		have[p].push_back(i+1);
	}
	for(i=1;i<=n;i++)
	{
		if(!P[i]) continue;
		int cnt=0;
		for(j=0;j<have[i].size();j++)
		{
			if(!P[have[i][j]]) cnt++;
		}
		if(cnt<3)
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
}