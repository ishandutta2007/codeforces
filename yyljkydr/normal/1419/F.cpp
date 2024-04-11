#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

int n,fa[N],x[N],y[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

vector<int>v,s[4];

int mxd(int a,int b)
{
	return max(abs(x[a]-x[b]),abs(y[a]-y[b]));
}

int mnd(int a,int b)
{
	return min(abs(x[a]-x[b]),abs(y[a]-y[b]));
}

struct SET{
	int lsx[N],lsy[N];
	int rx[N],ry[N];
	int vis[N][N];
	void init()
	{
		for(int i=1;i<=n;i++)
			rx[i]=lsx[i],ry[i]=lsy[i];
		sort(lsx+1,lsx+n+1);
		sort(lsy+1,lsy+n+1);
		for(int i=1;i<=n;i++)
		{
			rx[i]=lower_bound(lsx+1,lsx+n+1,rx[i])-lsx;
			ry[i]=lower_bound(lsy+1,lsy+n+1,ry[i])-lsy;
		}
	}
	void clear()
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				vis[i][j]=0;
	}
	void insert(pii a)
	{
		vis[rx[a.fs]][ry[a.sd]]=1;
	}
	int count(pii a)
	{
		return vis[rx[a.fs]][ry[a.sd]];
	}
}ts;

bool chk(int w)
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(mnd(i,j)==0&&mxd(i,j)<=w)
				fa[find(i)]=find(j);
	v.clear();
	for(int i=1;i<=n;i++)
		if(find(i)==i)
			v.push_back(i);
	if(v.size()>4)
		return 0;
	for(int i=0;i<v.size();i++)
	{
		s[i].clear();
		for(int j=1;j<=n;j++)
			if(find(j)==v[i])
				s[i].push_back(j);
	}
	if(v.size()==1)
		return 1;
	else if(v.size()==2)
	{
		for(int i=0;i<s[0].size();i++)
			for(int j=0;j<s[1].size();j++)
			{
				if(mxd(s[0][i],s[1][j])<=w||(mnd(s[0][i],s[1][j])==0&&mxd(s[0][i],s[1][j])<=2*w))
					return 1;
			}
		return 0;
	}
	else if(v.size()==3)
	{
		ts.clear();
		for(int i=0;i<s[0].size();i++)
			for(int j=0;j<s[1].size();j++)
				if(mxd(s[0][i],s[1][j])<=w)
				{
					ts.insert(mp(s[0][i],s[1][j]));
					ts.insert(mp(s[1][j],s[0][i]));
				}
		for(int i=0;i<s[0].size();i++)
			for(int j=0;j<s[2].size();j++)
				if(mxd(s[0][i],s[2][j])<=w)
				{
					if(ts.count(mp(s[0][i],s[2][j])))
						return 1;
					if(ts.count(mp(s[2][j],s[0][i])))
						return 1;
				}
		ts.clear();
		for(int i=0;i<s[1].size();i++)
			for(int j=0;j<s[2].size();j++)
				if(mxd(s[1][i],s[2][j])<=w)
				{
					ts.insert(mp(s[1][i],s[2][j]));
					ts.insert(mp(s[2][j],s[1][i]));
				}
		for(int i=0;i<s[0].size();i++)
			for(int j=0;j<s[1].size();j++)
				if(mxd(s[0][i],s[1][j])<=w)
				{
					if(ts.count(mp(s[0][i],s[1][j])))
						return 1;
					if(ts.count(mp(s[1][j],s[0][i])))
						return 1;
				}
		ts.clear();
		for(int i=0;i<s[0].size();i++)
			for(int j=0;j<s[2].size();j++)
				if(mxd(s[0][i],s[2][j])<=w)
				{
					ts.insert(mp(s[0][i],s[2][j]));
					ts.insert(mp(s[2][j],s[0][i]));
				}
		for(int i=0;i<s[1].size();i++)
			for(int j=0;j<s[2].size();j++)
				if(mxd(s[1][i],s[2][j])<=w)
				{
					if(ts.count(mp(s[1][i],s[2][j])))
						return 1;
					if(ts.count(mp(s[2][j],s[1][i])))
						return 1;
				}
		return 0;
	}
	else if(v.size()==4)
	{
		for(int t=1;t<=2;t++)
		{
			ts.clear();
			for(int i=0;i<s[0].size();i++)
				for(int j=0;j<s[t].size();j++)
					if(mxd(s[0][i],s[t][j])<=w)
					{
						ts.insert(mp(s[0][i],s[t][j]));
						ts.insert(mp(s[t][j],s[0][i]));
					}
			int p=(t==1?2:1),q=p^t;
			for(int i=0;i<s[p].size();i++)
				for(int j=0;j<s[q].size();j++)
					if(mxd(s[p][i],s[q][j])<=w)
					{
						if(ts.count(mp(s[p][i],s[q][j])))
							return 1;
						if(ts.count(mp(s[q][j],s[p][i])))
							return 1;
					}
		}
		return 0;
	}
	return 0;
}

signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i],ts.lsx[i]=x[i],ts.lsy[i]=y[i];
	ts.init();
	int l=0,r=2e9+1;
	while(r-l>1)
	{
		int mid=(1ll*l+r)>>1;
		if(chk(mid))
			r=mid;
		else
			l=mid;
	}
	if(r<=2e9)
		printf("%d\n",r);
	else
		puts("-1");
}