#import<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+1;
int n,x,q[N][3],c[N],v[N],s;
vector<int>a[N];
void D(int x,int y)
{
	v[x]=y;
	for(int i=0;i<a[x].size();i++)
		if(!v[a[x][i]])
			D(a[x][i],3-y);
}
main()
{
	cin>>n;
	if(n%2==0)
	{
		cout<<"First\n";
		for(int i=1;i<=2*n;i++)
			cout<<i%n+1<<' ';
		exit(0);
	}
	cout<<"Second\n";
	for(int i=1;i<=2*n;i++)
		cin>>x,q[x][++c[x]]=i;
	for(int i=1;i<=n;i++)
		a[i].push_back(i+n),a[i+n].push_back(i),a[q[i][1]].push_back(q[i][2]),a[q[i][2]].push_back(q[i][1]);
	for(int i=1;i<=2*n;i++)
		if(!v[i])
			D(i,1);
	for(int i=1;i<=2*n;i++)
		if(v[i]==1)
			s+=i;
	if(s%(2*n)==0)
	{
		for(int i=1;i<=2*n;i++)
			if(v[i]==1)
				cout<<i<<' ';
		exit(0);
	}
	for(int i=1;i<=2*n;i++)
		if(v[i]==2)
			cout<<i<<' ';
}