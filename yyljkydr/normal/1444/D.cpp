#include<bits/stdc++.h>
using namespace std;

const int N=1e3+1e2+7;

bitset<N*N>f[N];

int calc(int *x,int n,vector<int> &v0,vector<int>&v1)
{
	v0.clear(),v1.clear();
	int s=0;
	for(int i=1;i<=n;i++)
		s+=x[i];
	if(s&1)
		return 0;
	s>>=1;
	for(int i=1;i<=n;i++)
		f[i].reset();
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]|(f[i-1]<<x[i]);
	if(!f[n][s])
		return 0;
	for(int i=n;i>=1;i--)
	{
		if(s>=x[i]&&f[i-1][s-x[i]])
			v1.push_back(x[i]),s-=x[i];
		else
			v0.push_back(x[i]);
	}
	assert(s==0);
	return 1;
}

int T;

int nx,x[N],ny,y[N];

vector<int>cx[2],cy[2];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>ans;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&nx);
		for(int i=1;i<=nx;i++)
			scanf("%d",&x[i]);
		scanf("%d",&ny);
		for(int i=1;i<=ny;i++)
			scanf("%d",&y[i]);
		if(nx!=ny)
		{
			puts("No");
			continue;
		}
		int ok=1;
		ok&=calc(x,nx,cx[0],cx[1]);
		ok&=calc(y,ny,cy[0],cy[1]);
		if(!ok)
		{
			puts("No");
			continue;
		}
		puts("Yes");
		if(cx[0].size()>cx[1].size())
			swap(cx[0],cx[1]);
		if(cy[0].size()<cy[1].size())
			swap(cy[0],cy[1]);
		sort(cx[0].begin(),cx[0].end(),greater<int>());
		sort(cy[0].begin(),cy[0].end());
		sort(cx[1].begin(),cx[1].end());
		sort(cy[1].begin(),cy[1].end(),greater<int>());
		int X=0,Y=0;
		ans.clear();
		ans.push_back(mp(X,Y));
		for(int i=0;i<cx[0].size();i++)
		{
			X+=cx[0][i];
			ans.push_back(mp(X,Y));
			Y+=cy[0][i];
			ans.push_back(mp(X,Y));
		}
		for(int i=0;i<=(int)cx[1].size()-(int)cy[1].size()-1;i++)
		{
			X-=cx[1][i+cy[1].size()];
			ans.push_back(mp(X,Y));
			Y+=cy[0][i+cx[0].size()];
			ans.push_back(mp(X,Y));
		}
		for(int i=cy[1].size()-1;i>=0;i--)
		{
			X-=cx[1][i];
			ans.push_back(mp(X,Y));
			Y-=cy[1][i];
			ans.push_back(mp(X,Y));
		}
		assert(ans.back()==mp(0,0));
		ans.pop_back();
		for(auto [x,y]:ans)
			printf("%d %d\n",x,y);
	}
}