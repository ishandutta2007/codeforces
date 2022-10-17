#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,m,k;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>can;

vector<pii>b,r,y;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&m,&k);
		can.resize(k);
		r.clear(),b.clear(),y.clear();
		for(int i=0;i<k;i++)
			scanf("%d",&can[i].fs),can[i].sd=i+1;
		sort(can.begin(),can.end(),greater<pii>());
		int mx=max_element(can.begin(),can.end())->first;
		for(n=1;n*n-(n/2)*(n/2)<m||n*n-n*(n/2)<mx;n++);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(i%2==0&&j%2==0)
					b.push_back(mp(i,j));
				if(i%2==0&&j%2==1)
					r.push_back(mp(i,j));
				if(i%2==1&&j%2==0)
					y.push_back(mp(i,j));
			}
		vector<vector<int> >ans(n);
		for(int i=0;i<ans.size();i++)
			ans[i].resize(n);
		for(int i=0;i<k;i++)
		{
			while(can[i].first--)
			{
				vector<pii> &v=(!r.empty()?r:(!b.empty()?b:y));
				ans[v.back().fs][v.back().sd]=can[i].second;
				v.pop_back();
			}
		}
		printf("%d\n",n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				printf("%d%c",ans[i][j]," \n"[j+1==n]);
	}
}