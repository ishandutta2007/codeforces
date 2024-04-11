#include<bits/stdc++.h>
using namespace std;

const int N=1e2+1e3+7;

int T,a[N][N],n,m;

typedef pair<int,int> pii;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		vector<int>v;
		set<pii>s;
		long long ans=0;
		for(int i=1;i<=(n+1)/2;i++)
			for(int j=1;j<=(m+1)/2;j++)
			{
				s.clear();
				s.insert(pii(i,j));
				s.insert(pii(n-i+1,m-j+1));
				s.insert(pii(n-i+1,j));
				s.insert(pii(i,m-j+1));
				v.clear();
				for(auto [x,y]:s)
					v.push_back(a[x][y]);
				sort(v.begin(),v.end());
				for(int i=0;i<v.size()/2;i++)
					ans+=v[v.size()-i-1]-v[i];
			}
		printf("%lld\n",ans);
	}
}