#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int T,n;

char s[N][N];

int b[2][N][N];

vector<pair<int,int> >ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				s[i][j]-='0';
		int a=0;
		a+=s[1][2]^0;
		a+=s[2][1]^0;
		a+=s[n-1][n]^1;
		a+=s[n][n-1]^1;
		if(a<=2)
		{
			if(s[1][2]==1)
				ans.push_back(pair<int,int>(1,2));
			if(s[2][1]==1)
				ans.push_back(pair<int,int>(2,1));
			if(s[n-1][n]==0)
				ans.push_back(pair<int,int>(n-1,n));
			if(s[n][n-1]==0)
				ans.push_back(pair<int,int>(n,n-1));
		}
		else
		{
			if(s[1][2]==0)
				ans.push_back(pair<int,int>(1,2));
			if(s[2][1]==0)
				ans.push_back(pair<int,int>(2,1));
			if(s[n-1][n]==1)
				ans.push_back(pair<int,int>(n-1,n));
			if(s[n][n-1]==1)
				ans.push_back(pair<int,int>(n,n-1));
		}
		printf("%d\n",ans.size());
		for(auto [x,y]:ans)
			printf("%d %d\n",x,y);
	}
}