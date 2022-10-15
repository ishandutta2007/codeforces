#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e3+5;
int n,m;
ll ans;
vector<int>a[maxn];
int s[maxn][maxn];
int p[maxn];
struct point
{
	int x,y;
	ll operator *(const point &a)const{return (ll)x*a.y-(ll)a.x*y;}
	point operator -(const point &a)const{return {x-a.x,y-a.y};}
	int val(int a){return a*x+y;}
};
int main()
{
	n=read();m=read();
	for(int i=0;i<=n;i++)
	{
		string str;cin>>str;
		for(int j=0;j<=m;j++)if(str[j]=='1')a[i].push_back(j);
	}
	memset(s,0x3f,sizeof s);
	for(int i=0;i<=n;i++)p[i]=-1;
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)while(p[j]+1<a[j].size()&&a[j][p[j]+1]<=i)p[j]++;
		vector<point>q;
		for(int j=n;j>=0;j--)
			if(p[j]!=-1)
			{
				point now={-2*j,j*j+(i-a[j][p[j]])*(i-a[j][p[j]])};
				while(q.size()>=2&&(q.back()-q[q.size()-2])*(now-q[q.size()-2])<=0)q.pop_back();
				q.push_back(now);
			}
		if(!q.size())continue;
		for(int j=0;j<=n;j++)
		{
			while(q.size()>=2&q.back().val(j)>=q[q.size()-2].val(j))q.pop_back();
			s[j][i]=min(s[j][i],q.back().val(j)+j*j);			
		}
	}
	for(int i=0;i<=n;i++)p[i]=a[i].size();
	for(int i=m;i>=0;i--)
	{
		for(int j=0;j<=n;j++)while(p[j]&&a[j][p[j]-1]>=i)p[j]--;
		vector<point>q;
		for(int j=n;j>=0;j--)
			if(p[j]!=a[j].size())
			{
				point now={-2*j,j*j+(i-a[j][p[j]])*(i-a[j][p[j]])};
				while(q.size()>=2&&(q.back()-q[q.size()-2])*(now-q[q.size()-2])<=0)q.pop_back();
				q.push_back(now);
			}
		if(!q.size())continue;
		for(int j=0;j<=n;j++)
		{
			while(q.size()>=2&q.back().val(j)>=q[q.size()-2].val(j))q.pop_back();
			s[j][i]=min(s[j][i],q.back().val(j)+j*j);
		}
	}
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)ans+=s[i][j];
	printf("%lld\n",ans);
	return 0;
}