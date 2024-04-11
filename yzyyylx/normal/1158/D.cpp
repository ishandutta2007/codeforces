#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 2010
using namespace std;

ll n,x[N],y[N];
char str[N];
bool vis[N];
struct Node
{
	ll x,y;
	Node operator + (const Node &u) const{return (Node){x+u.x,y+u.y};}
	Node operator - (const Node &u) const{return (Node){x-u.x,y-u.y};}
}node[N],last;

inline ll cj(Node u,Node v){return u.x*v.y-v.x*u.y;}
int main()
{
	ll i,j,t,mn,mx;
	cin>>n;
	t=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&node[i].x,&node[i].y);
		if(node[i].x<node[t].x || node[i].x==node[t].x&&node[i].y>node[t].y) t=i;
	}
	vis[t]=1;
	scanf("%s",str+1);
	cout<<t<<" ";
	last=node[t];
	for(i=1;i<=n-2;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(vis[j]) continue;
			break;
		}
		t=j;
		for(j=t+1;j<=n;j++)
		{
			if(vis[j]) continue;
			if((cj(node[j]-last,node[j]-node[t])<0)^(str[i]=='R')) t=j;
		}
		printf("%lld ",t);
		last=node[t];
		vis[t]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cout<<i;
			return 0;
		}
	}
}