#include<bits/stdc++.h>
using namespace std;
const int N=3e3+1;
bool v[N];
int n,m,x,y,S,T,L,P,Q,R,q[N],s,t,X,d[N][N],A;
vector<int>a[N];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		a[x].push_back(y),a[y].push_back(x);
	}
	cin>>S>>T>>L>>P>>Q>>R;
	for(int i=1;i<=n;i++)
	{
		memset(v,false,sizeof(v)),s=t=0,q[++t]=i,v[i]=true;
		while(s<t)
		{
			X=q[++s];
			for(int j=0;j<a[X].size();j++)
				if(!v[a[X][j]])
					d[i][a[X][j]]=d[i][X]+1,q[++t]=a[X][j],v[a[X][j]]=true;
		}
	}
	if(d[S][T]>L||d[P][Q]>R)
	{
		cout<<-1;
		return 0;
	}
	A=d[S][T]+d[P][Q];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			x=min(d[S][i]+d[i][j]+d[j][T],d[T][i]+d[i][j]+d[j][S]),y=min(d[P][i]+d[i][j]+d[j][Q],d[Q][i]+d[i][j]+d[j][P]);
			if(x<=L&&y<=R)
				A=min(A,x+y-d[i][j]);
		}
	cout<<m-A;
	return 0;
}