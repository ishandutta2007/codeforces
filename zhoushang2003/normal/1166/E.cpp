#include<bits/stdc++.h>
using namespace std;
const int M=51,N=1e4+1; 
bool v[M][N],b;
int m,n,s,x;
int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>s;
		while(s--&&cin>>x)
			v[i][x]=true;
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
		{
			b=true;
			for(int k=1;k<=n;k++)
				if(v[i][k]&&v[j][k])
					b=false;
			if(b)
			{
				cout<<"impossible";
				return 0;
			}
		}
	cout<<"possible";
	return 0;
}