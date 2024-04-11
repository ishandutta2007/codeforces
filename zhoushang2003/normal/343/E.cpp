#include<bits/stdc++.h>
using namespace std;
const int N=201,M=1001,I=1e9;
struct E
{
	int v,x,w,f;
};
int n,m,x,y,z,C=1,h[N],c[N][N],r[N],q[N],X,d[N],U,A[N];
E e[2*M];
vector<int>a;
void P(int x,int y,int z)
{
	e[++C]=(E){y,h[x],z,z},h[x]=C;
}
bool B(int s,int t)
{
	memcpy(r,h,sizeof(h)),memset(d,-1,sizeof(d));
	int l=0,r=0;
	q[++r]=s,d[s]=0;
	while(l<r)
	{
		X=q[++l];
		for(int i=h[X],y;i;i=e[i].x)
			if(e[i].w&&d[y=e[i].v]==-1)
				d[y]=d[X]+1,q[++r]=y;
	}
	return d[t]!=-1;
}
int F(int x,int t,int f)
{
	if(x==t||!f)
		return f;
	int p=0,y;
	for(int &i=r[x];i;i=e[i].x)
		if(e[i].w&&d[y=e[i].v]==d[x]+1)
		{
			int w=F(y,t,min(f,e[i].w));
			e[i].w-=w,e[i^1].w+=w,f-=w,p+=w;
			if(!f)
				break;
		}
	if(!f)
		d[x]=-1;
	return p;
}
int D(int s,int t)
{
	for(int i=2;i<=C;i++)
		e[i].w=e[i].f;
	int A=0;
	while(B(s,t))
		A+=F(s,t,I);
	return A;
}
void S(vector<int>v)
{
	if(v.size()==1)
		return;	
	int f=D(v[0],v[1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if((d[i]!=-1)^(d[j]!=-1))
				c[i][j]=min(c[i][j],f);
	vector<int>l,r;
	for(int i=0;i<v.size();i++)
		if(d[v[i]]!=-1)
			l.push_back(v[i]);
		else
			r.push_back(v[i]);
	S(l),S(r);
}
void Q(vector<int>v)
{
	if(v.size()==1)
	{
		A[++A[0]]=v[0];
		return;
	}
	int s=v[0],t=v[1];
	for(int i=2;i<v.size();i++)
		if(c[s][v[i]]<c[s][t])
			t=v[i];
	U+=D(s,t);
	vector<int>l,r;
	for(int i=0;i<v.size();i++)
		if(d[v[i]]!=-1)
			l.push_back(v[i]);
		else
			r.push_back(v[i]);
	Q(l),Q(r);
}
int main()
{
	cin>>n>>m;
	while(m--&&cin>>x>>y>>z)
		P(x,y,z),P(y,x,z);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			c[i][j]=I;
	for(int i=1;i<=n;i++)
		a.push_back(i);
	S(a),Q(a);
	cout<<U<<'\n';
	for(int i=1;i<=n;i++)
		cout<<A[i]<<' ';
	return 0;
}