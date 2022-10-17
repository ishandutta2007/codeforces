#include<bits/stdc++.h>
using namespace std;

const int N=5e2+1e1+7;

int n;

int k[N];

vector<pair<int,int> >v;

bool cmp(pair<int,int>a,pair<int,int>b)
{
	return k[a.first]-k[a.second]>k[b.first]-k[b.second];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&k[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j&&k[i]>=k[j])
				v.push_back(make_pair(i,j));
	sort(v.begin(),v.end(),cmp);
	for(auto [x,y]:v)
	{
		printf("? %d %d\n",x,y);
		string chk;
		cin>>chk;
		if(chk=="Yes")
		{
			printf("! %d %d\n",x,y);
			return 0;
		}
	}
	puts("! 0 0\n");
	fflush(stdout);
}