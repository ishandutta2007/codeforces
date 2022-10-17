#include<bits/stdc++.h>
#define N 200005
using namespace std;

queue<int>wa;
map<int,bool>P;
int a[N],ji,ou,n,m,ans;

int main()
{
	int i,j,p,q;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p);
		a[i]=p;
		if(P[p]!=false||ji==n/2&&p%2==1||ou==n/2&&p%2==0)
		{
			wa.push(i);
			ans++;
		}
		else
		{
			if(p%2==0) ou++;
			else ji++;
			P[p]=true;
		}
	}
	for(i=1;i<=m&&wa.empty()==false;i++)
	{
		if(P[i]==false&&i%2==0&&ou<n/2||P[i]==false&&i%2==1&&ji<n/2)
		{
			if(i%2==0) ou++;
			else ji++;
			a[wa.front()]=i;
			wa.pop();
		}
	}
	if(wa.empty()==false)
	{
		cout<<-1;
		return 0;
	}
	else
	{
		cout<<ans<<endl;
		for(i=1;i<=n;i++)
		{
			cout<<a[i]<<" ";
		}
	}
}