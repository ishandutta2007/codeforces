#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
int n,m,p[N],x,y,f[N],A;
vector<int>a[N];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	while(m--&&scanf("%d%d",&x,&y))
		a[y].push_back(x);
	for(int i=0;i<a[p[n]].size();i++)
		f[a[p[n]][i]]++;
	for(int i=n-1;i>=1;i--)
		if(f[p[i]]==n-i-A)
			A++;
		else
			for(int j=0;j<a[p[i]].size();j++)
				f[a[p[i]][j]]++;
	cout<<A;
	return 0;
}