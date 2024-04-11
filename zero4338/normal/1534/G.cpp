#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=8e5+5;
int n;
ll ans;
struct point
{
	int x,y;
	const bool operator <(const point &a)const{return x+y<a.x+a.y;}
}p[maxn];
priority_queue<ll>L;
priority_queue<ll,vector<ll>,greater<ll> >R;ll delr;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)p[i].x=read(),p[i].y=read();
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)L.push(0),R.push(0);
	for(int i=1;i<=n;i++)
	{
		int t=p[i].x+p[i].y-p[i-1].x-p[i-1].y;delr+=t;
		if(p[i].x<L.top()){ans+=L.top()-p[i].x;L.push(p[i].x);L.push(p[i].x);R.push(L.top()-delr);L.pop();}
		else if(p[i].x>R.top()+delr){ans+=p[i].x-R.top()-delr;R.push(p[i].x-delr);R.push(p[i].x-delr);L.push(R.top()+delr);R.pop();}
		else{L.push(p[i].x);R.push(p[i].x-delr);}
	}
	printf("%lld",ans);
	return 0;
}