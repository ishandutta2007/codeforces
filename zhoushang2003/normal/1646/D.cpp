#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,x,y,c[N][2],s[N][2],A[N];
vector<int>a[N];
int C(int x)
{
	if(c[x][0]!=c[x][1])
		return c[x][0]>c[x][1];
	return s[x][0]<s[x][1];
}
void D(int x,int f)
{
	s[x][0]=c[x][1]=1,s[x][1]=a[x].size();
	for(int i=0,y;i<a[x].size();i++)
		if((y=a[x][i])!=f)
		{
			D(y,x),c[x][1]+=c[y][0],s[x][1]+=s[y][0];
			if(C(y))
				c[x][0]+=c[y][0],s[x][0]+=s[y][0];
			else
				c[x][0]+=c[y][1],s[x][0]+=s[y][1];
		}
}
void S(int x,int f,int v)
{
	if(v||C(x))
		A[x]=1,v=0;
	else
		A[x]=a[x].size(),v=1;
	for(int i=0,y;i<a[x].size();i++)
		if((y=a[x][i])!=f)
			S(y,x,v);
}
int main()
{

	cin>>n;
	for(int i=1;i<n;i++)
		cin>>x>>y,a[x].push_back(y),a[y].push_back(x);
	if(n==2)
	{
		cout<<"2 2\n1 1";
		return 0;
	}
	D(1,0),S(1,0,0),C(1)?cout<<c[1][0]<<' '<<s[1][0]<<'\n':cout<<c[1][1]<<' '<<s[1][1]<<'\n';
	for(int i=1;i<=n;i++)
		cout<<A[i]<<' ';
}