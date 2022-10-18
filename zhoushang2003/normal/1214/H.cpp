#import<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n,k,d[N],f[N],x,y,A[N],u;
vector<int>a[N];
vector<pair<int,int>>v[N];
void P(int x,int y)
{
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=y)
			f[a[x][i]]=x,d[a[x][i]]=d[x]+1,P(a[x][i],x);
}
int D(int x,int y)
{
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=y)
			v[x].push_back({D(a[x][i],x),a[x][i]});
	if(!v[x].size())
		return 1;
	sort(v[x].begin(),v[x].end());
	return v[x][v[x].size()-1].first+1;
}
void S(int x,int y)
{
	if(v[f[x]].size())
	{
		if(v[f[x]].size()==1)
			v[x].push_back({1,0});
		else if(v[f[x]][v[f[x]].size()-1].second!=x)
			v[x].push_back({v[f[x]][v[f[x]].size()-1].first+1,0});
		else
			v[x].push_back({v[f[x]][v[f[x]].size()-2].first+1,0});
	}
	sort(v[x].begin(),v[x].end());
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=y)
			S(a[x][i],x);
}
main()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
		cin>>x>>y,a[x].push_back(y),a[y].push_back(x);
	if(k==2)
		for(int i=1;i<=n;i++)
			if(a[i].size()==1)
			{
				puts("Yes"),P(i,0);
				for(int j=1;j<=n;j++)
					cout<<d[j]%k+1<<' ';
				exit(0);
			}
	P(1,0),D(1,0),S(1,0);
	for(int i=1;i<=n;i++)
		if(v[i].size()>2&&v[i][v[i].size()-2].first+v[i][v[i].size()-3].first>=k-1)
			cout<<"No",exit(0);
	puts("Yes"),u=0;
	for(int i=1;i<=n;i++)
		u=max(u,d[i]);
	for(int i=1;i<=n;i++)
		if(d[i]==u)
		{
			d[i]=0,P(i,0),u=0;
			for(int j=1;j<=n;j++)
				u=max(u,d[j]);
			for(int j=1;j<=n;j++)
				if(d[j]==u)
				{
					x=j;
					for(int k=1;k<=u/2;k++)
						x=f[x];
					memset(d,0,sizeof(d)),d[x]=1,P(x,f[x]);
					for(int l=1;l<=n;l++)
						if(d[l])
							A[l]=(d[l]-1)%k+1;
					memset(d,0,sizeof(d)),d[f[x]]=1,P(f[x],x);
					for(int l=1;l<=n;l++)
						if(d[l])
							A[l]=k-(d[l]-1)%k;
					for(int k=1;k<=n;k++)
						cout<<A[k]<<' ';
					exit(0);
				}
		}
}