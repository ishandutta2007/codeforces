#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define int long long
#define ll long long
using namespace std;
ll read()
{
	ll ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=3e5+5;
int n,l;
ll t;
ll x[maxn];int be=1;
int ans[maxn];
struct ant
{
	int num,pos;
	const bool operator <(const ant &x)const{return pos<x.pos;}
}p[maxn];

signed main()
{
	n=read();l=read();t=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read()-1;char opt;cin>>opt;
		p[i].num=i;p[i].pos=x[i];
		x[i]+=opt=='R'?t:-t;
		be+=x[i]/l;
		if(x[i]%l<0)be--;
		be=(be%n+n)%n;
		x[i]=(x[i]%l+l)%l+1;
	}
	sort(x+1,x+n+1);
	sort(p+1,p+n+1);
	if(!be)be=n;
	for(int i=be;i<=n;i++)ans[p[i-be+1].num]=x[i];
	for(int i=1;i<be;i++)ans[p[i+n-be+1].num]=x[i];
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
	return 0;
}