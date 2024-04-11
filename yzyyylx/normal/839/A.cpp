#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,l=0,a,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(a+l<=8)
		{
			m-=a+l;
			l=0;
		}
		else
		{
			m-=8;
			l=a+l-8;
		}
		if(m<=0)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
}