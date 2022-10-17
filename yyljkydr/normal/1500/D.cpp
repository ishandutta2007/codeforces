#include<bits/stdc++.h>
using namespace std;

const int N=1507;

int n,a[N][N],k;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii> g[N];

int ans[N];

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	for(int i=n;i>=1;i--)
	{
		vector<pii>f;
		for(int j=n;j>=1;j--)
		{
			int fd=0;
			for(int w=0;w<f.size();w++)
			{
				auto t=f[w];
				if(a[t.fs][t.sd]==a[i][j])
				{
					f[w].fs=i,f[w].sd=j,fd=1;
					break;
				}
			}
			if(!fd)
			{
				if(f.size()<k+1)
					f.push_back(mp(i,j));
				else
				{
					auto p=max_element(f.begin(),f.end());
					*p=mp(i,j);
				}
			}
			for(int w=0;w<g[j+1].size();w++)
			{
				auto t=g[j+1][w];
				int fd=0;
				for(int r=0;r<g[j].size();r++)
				{
					auto s=g[j][r];
					if(a[s.fs][s.sd]==a[t.fs][t.sd])
					{
						if(max(s.fs-i,s.sd-j)>max(t.fs-i,t.sd-j))
							g[j][r]=t;
						else if(max(s.fs-i,s.sd-j)==max(t.fs-i,t.sd-j)&&s.fs>t.fs)
							g[j][r]=t;
						fd=1;
						break;
					}
				}
				if(!fd)
				{
					if(g[j].size()<k+1)
						g[j].push_back(t);
					else
					{
						int p=0;
						for(int r=1;r<g[j].size();r++)
						{
							if(max(g[j][r].fs-i,g[j][r].sd-j)>max(g[j][p].fs-i,g[j][p].sd-j))
								p=r;
							else if(max(g[j][r].fs-i,g[j][r].sd-j)==max(g[j][p].fs-i,g[j][p].sd-j)&&g[j][r].fs>g[j][p].fs)
								p=r;
						}
						if(max(g[j][p].fs-i,g[j][p].sd-j)>max(t.fs-i,t.sd-j))
							g[j][p]=t;
						else if(max(g[j][p].fs-i,g[j][p].sd-j)==max(t.fs-i,t.sd-j)&&t.fs<g[j][p].fs)
							g[j][p]=t;
					}
				}
			}
			for(int w=0;w<f.size();w++)
			{
				auto t=f[w];
				int fd=0;
				for(int r=0;r<g[j].size();r++)
				{
					auto s=g[j][r];
					if(a[s.fs][s.sd]==a[t.fs][t.sd])
					{
						if(max(s.fs-i,s.sd-j)>max(t.fs-i,t.sd-j))
							g[j][r]=t;
						else if(max(s.fs-i,s.sd-j)==max(t.fs-i,t.sd-j)&&s.fs>t.fs)
							g[j][r]=t;
						fd=1;
						break;
					}
				}
				if(!fd)
				{
					if(g[j].size()<k+1)
						g[j].push_back(t);
					else
					{
						int p=0;
						for(int r=1;r<g[j].size();r++)
						{
							if(max(g[j][r].fs-i,g[j][r].sd-j)>max(g[j][p].fs-i,g[j][p].sd-j))
								p=r;
							else if(max(g[j][r].fs-i,g[j][r].sd-j)==max(g[j][p].fs-i,g[j][p].sd-j)&&g[j][r].fs>g[j][p].fs)
								p=r;
						}
						if(max(g[j][p].fs-i,g[j][p].sd-j)>max(t.fs-i,t.sd-j))
							g[j][p]=t;
						else if(max(g[j][p].fs-i,g[j][p].sd-j)==max(t.fs-i,t.sd-j)&&t.fs<g[j][p].fs)
							g[j][p]=t;
					}
				}
			}
			int ran=min(n-i+1,n-j+1);
			if(g[j].size()==k+1)
			{
				int p=0;
				for(int r=1;r<g[j].size();r++)
				{
					if(max(g[j][r].fs-i,g[j][r].sd-j)>max(g[j][p].fs-i,g[j][p].sd-j))
						p=r;
				}
				ran=min(ran,max(g[j][p].fs-i,g[j][p].sd-j));
			}
			ans[ran+1]--;
			ans[1]++;
		}
	}
	for(int i=1;i<=n;i++)
		ans[i]+=ans[i-1],printf("%d\n",ans[i]);
}