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
const int maxn=105,mod=1e9+7;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n;
map<int,pair<int,int>>factor[maxn];
vector<int>exi,aexi;
vector<int>getfactor(int x)
{
	vector<int>ret;
	for(int i=2;i*i<=x;i++)
		while(x%i==0)ret.push_back(i),x/=i;
	if(x!=1)ret.push_back(x);
	return ret;
}
void fail(){puts("-1");exit(0);}
void check(int id,ll pos)
{
	if(pos<0)fail();
	static ll p[maxn];
	for(int i=1;i<=n;i++)p[i]=0;
	p[id]=pos;
	for(int i=1;i<=n;i++)
	{
		if(i==id)continue;
		for(int &j:exi)
			if(factor[i][j].second)
			{
				if(p[id]*factor[id][j].second+factor[id][j].first-factor[i][j].first<0)fail();
				if((p[id]*factor[id][j].second+factor[id][j].first-factor[i][j].first)%factor[i][j].second)fail();
				p[i]=(p[id]*factor[id][j].second+factor[id][j].first-factor[i][j].first)/factor[i][j].second;
			}
	}
	int ret=1;
	for(int &i:exi)
	{
		ll val=factor[1][i].first+factor[1][i].second*p[1];
		ret=(ll)ret*qpow(i,val%(mod-1))%mod;
		for(int j=2;j<=n;j++)if(factor[j][i].first+factor[j][i].second*p[j]!=val)fail();
	}
	printf("%d\n",ret);
	exit(0);
}
void exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0){x=1;y=0;return;}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
void gauss(vector<vector<int>>a,vector<int>b)
{
	if(a[0][0]*a[1][1]==a[0][1]*a[1][0])
	{
		if(b[0]*a[1][0]!=b[1]*a[0][0])fail();
		return;
	}
	if((b[0]*a[1][1]-b[1]*a[0][1])%(a[0][0]*a[1][1]-a[0][1]*a[1][0]))fail();
	check(1,(b[0]*a[1][1]-b[1]*a[0][1])/(a[0][0]*a[1][1]-a[0][1]*a[1][0]));
}
int getinv(int a,int b)
{
	for(int i=0;i<b;i++)if(a*i%b==1)return i;
	return -1;
}
pair<ll,ll>crt(vector<int>a,vector<int>b)
{
	ll na=a[0],nb=b[0];
	for(int i=1;i<a.size();i++)
	{
		ll d=__gcd(nb,(ll)b[i]);
		if((na-a[i])%d)fail();
		ll x,y;
		exgcd(nb/d,(ll)b[i]/d,x,y);
		swap(x,y);
		nb=nb/d*b[i];
		x=(__int128)x*((na-a[i])/d)%nb;
		na=(a[i]+x*b[i]%nb)%nb;
		na=(na%nb+nb)%nb;
	}
	return {na,nb};
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int a=read(),b=read();
		for(int &j:getfactor(a))
		{
			exi.push_back(j);
			factor[i][j].first++;
		}
		for(int &j:getfactor(b))
		{
			exi.push_back(j);
			factor[i][j].second++;
		}
	}
	sort(exi.begin(),exi.end());exi.erase(unique(exi.begin(),exi.end()),exi.end());
	for(int &i:exi)
	{
		int C=-1;
		for(int j=1;j<=n;j++)if(factor[j][i].second==0)C=factor[j][i].first;
		if(C!=-1)
		{
			for(int j=1;j<=n;j++)
			{
				if(factor[j][i].second==0&&factor[j][i].first!=C)fail();
				if(factor[j][i].second)
				{
					if(factor[j][i].first>C||(C-factor[j][i].first)%factor[j][i].second)fail();
					check(j,(C-factor[j][i].first)/factor[j][i].second);
				}
			}
		}
		else aexi.push_back(i);
	}
	if(aexi.empty())check(1,0);
	for(int &i:aexi)
		for(int j=1;j<=n;j++)
		{
			gauss({{factor[1][aexi[0]].second,-factor[j][aexi[0]].second},{factor[1][i].second,-factor[j][i].second}},
			{factor[j][aexi[0]].first-factor[1][aexi[0]].first,factor[j][i].first-factor[1][i].first});
		}
	vector<int>a,b;
	for(int i=1;i<=n;i++)
	{
		int na=factor[i][aexi[0]].first-factor[1][aexi[0]].first,nb=factor[i][aexi[0]].second,b0=factor[1][aexi[0]].second;
		int d=__gcd(b0,nb);
		if(d!=1)
		{
			if(na%d)fail();
			na/=d;b0/=d;nb/=d;
		}
		na*=getinv(b0,nb);
		a.push_back(na);
		b.push_back(nb);
	}
	pair<ll,ll>now=crt(a,b);
	ll ans=now.first;
	for(int i=1;i<=n;i++)while(ans*factor[1][aexi[0]].second+factor[1][aexi[0]].first-factor[i][aexi[0]].first<0)ans+=now.second;
	check(1,ans);
	return 0;
}