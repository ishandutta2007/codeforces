#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1,I=1e9;
bool v[N];
int n,m,g[N],x,y,M,s[N],A[N];
vector<int>a[N];
void D(int k,int f)
{
	s[k]=1;
	for(int i=0;i<a[k].size();i++)
		if(a[k][i]!=f&&!v[a[k][i]])
			D(a[k][i],k),s[k]+=s[a[k][i]],g[k]=max(g[k],s[a[k][i]]);
}
void S(int k)
{
	v[k]=true;
	for(int i=0;i<a[k].size();i++)
		if(!v[a[k][i]])
			S(a[k][i]);
	g[k]=max(g[k],x-s[k]);
	if(g[k]<g[M])
		M=k;
}
int main()
{
	cin>>n;
	m=n-1,g[0]=I;
	while(m--&&cin>>x>>y)
		a[x].push_back(y),a[y].push_back(x);
	for(int i=1;i<=26;i++)
	{
		for(int j=1;j<=n;j++)
			v[j]=(A[j]>0),g[j]=0;
		for(int j=1;j<=n;j++)
			if(!v[j])
				D(j,0),x=s[j],M=0,S(j),A[M]=i;
	}
	for(int i=1;i<=n;i++)
		cout<<(char)(A[i]-1+'A')<<" ";
	return 0;
}