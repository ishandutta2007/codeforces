#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long n,m,a[N],A,x,y,z;
map<int,int>p[N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],A+=a[i];
	cin>>m;
	while(m--)
	{
		cin>>x>>y>>z;
		if(p[x].count(y))
		{
			a[p[x][y]]++;
			if(a[p[x][y]]>0)
				A++;
		}
		a[z]--,p[x][y]=z;
		if(a[z]>=0)
			A--;
		cout<<A<<'\n';
	}
	return 0;
}