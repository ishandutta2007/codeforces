#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e6;
int n,k;
int id(int x,int y){return (x-1)*(k+1)+y;}
struct graph
{
	vector<pair<int,int>>e[maxn];
	void add(int x,int y,int z){e[x].push_back({y,z});e[y].push_back({x,z});}
	void clear(){for(int i=0;i<=(k+1)*(k+1);i++)e[i].clear();}
	struct node{int x,d;bool operator >(const node &a)const{return d>a.d;}};
	priority_queue<node,vector<node>,greater<node>>q;
	int dis[maxn];
	int dijkstra(int s,int t)
	{
		memset(dis,0x3f,sizeof(int)*((k+1)*(k+1)));
		dis[s]=0;q.push({s,0});
		while(!q.empty())
		{
			node now=q.top();q.pop();
			if(now.d>dis[now.x])continue;
			for(auto &i:e[now.x])
				if(dis[i.first]>now.d+i.second)
				{
					dis[i.first]=now.d+i.second;
					q.push({i.first,dis[i.first]});
				}
		}
		return dis[t];
	}
}o;
map<pair<int,int>,int>val;
int main()
{
	T=read();
	while(T--)
	{
		n=read();k=read();
		val.clear();
		o.clear();
		for(int i=1;i<=n;i++)
		{
			int x1=read(),y1=read(),x2=read(),y2=read();
			if(x1>x2)swap(x1,x2);if(y1>y2)swap(y1,y2);
			if(x1==x2)val[{id(x1,y2),id(x1+1,y2)}]++;
			else val[{id(x2,y1),id(x2,y1+1)}]++;
			x1=k+1-x1;x2=k+1-x2;
			y1=k+1-y1;y2=k+1-y2;
			if(x1>x2)swap(x1,x2);if(y1>y2)swap(y1,y2);
			if(x1==x2)val[{id(x1,y2),id(x1+1,y2)}]++;
			else val[{id(x2,y1),id(x2,y1+1)}]++;
		}
		for(auto &i:val)o.add(i.first.first,i.first.second,i.second);
		for(int i=1;i<=k+1;i++)
			for(int j=1;j<=k+1;j++)
			{
				if(i!=k+1&&val.find({id(i,j),id(i+1,j)})==val.end())o.add(id(i,j),id(i+1,j),0);
				if(j!=k+1&&val.find({id(i,j),id(i,j+1)})==val.end())o.add(id(i,j),id(i,j+1),0);
				if(i==1||i==k+1||j==1||j==k+1)o.add(id(i,j),0,0);
			}
		printf("%d\n",n-o.dijkstra(id(k/2+1,k/2+1),0));
	}
	return 0;
}