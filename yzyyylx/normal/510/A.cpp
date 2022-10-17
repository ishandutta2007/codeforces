#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,i,j;
	cin>>m>>n;
	for(i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(j=1;j<=n;j++)
			cout<<"#";
			cout<<endl;
		}
		if(i%4==2)
		{
			for(j=1;j<=n-1;j++)
			cout<<".";
			cout<<"#"<<endl;
		}
		if(i%4==0)
		{
			cout<<"#";
			for(j=1;j<=n-1;j++)
			cout<<".";
			cout<<endl;
		}
	}
}