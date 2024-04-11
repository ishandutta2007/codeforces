#include<bits/stdc++.h>
using namespace std;
const int N=203,I=1e9;
bool v[N];
int n,m,a[N][N],x,y;
int D(int k,int f)
{
	if(k==202)
		return f;
	if(v[k])
		return 0;
	v[k]=true;
	for(int i=1;i<203;i++)
		if(a[k][i])
		{
			int t=D(i,min(f,a[k][i]));
			if(t)
			{
				a[k][i]-=t,a[i][k]+=t;
				return t;
			}
		}
	return 0;
} 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[201][i];
	for(int i=1;i<=n;i++)
		cin>>a[i+n][202];
	for(int i=1;i<=n;i++)
		a[i][i+n]=I;
	while(m--&&cin>>x>>y)
		a[x][y+n]=a[y][x+n]=I;
	while(D(201,I))
		memset(v,false,sizeof(v));
	for(int i=1;i<=n;i++)
		if(a[201][i]||a[i+n][202])
		{
			cout<<"NO";
			return 0;
		}
	cout<<"YES"<<'\n';
	for(int i=1;i<=n;i++,cout<<'\n')
		for(int j=1;j<=n;j++)
			cout<<a[j+n][i]<<" ";
	return 0;
}