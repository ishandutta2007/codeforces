#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n;

vector<pair<int,int> >ans;

#define mp make_pair

int main()
{
	scanf("%d",&n);
	int m=1;
	while(m*2<n)
		m<<=1;
	int bias=0;
	for(int i=2;i<=m;i<<=1)
	{
		for(int j=1;j<=m;j+=i)
			for(int k=j;k<=j+i/2-1;k++)
				ans.push_back(mp(k+bias,k+i/2+bias));
	}
	bias=n-m;
	for(int i=2;i<=m;i<<=1)
	{
		for(int j=1;j<=m;j+=i)
			for(int k=j;k<=j+i/2-1;k++)
				ans.push_back(mp(k+bias,k+i/2+bias));
	}
	printf("%d\n",ans.size());
	for(auto [x,y]:ans)
		printf("%d %d\n",x,y);
}