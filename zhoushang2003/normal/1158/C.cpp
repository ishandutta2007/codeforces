#include<iostream>
using namespace std;
const int N=5e5+2;
int t,n,a[N],x[N],C;
int D(int k)
{
	int i=k;
	while(i>1&&(x[i-1]==k||x[i-1]==-1))
		i=D(i-1);
	a[k]=++C;
	return i;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--&&cin>>n)
	{
		C=0;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		if(D(n+1)>1)
			cout<<-1<<'\n';
		else
		{
			for(int i=1;i<=n;i++)
				cout<<a[i]<<" ";
			cout<<'\n';
		}
	}
	return 0;
}