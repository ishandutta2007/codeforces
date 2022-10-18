#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long n,x,c[N],A=1;
vector<int>a[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=2;j*j<=x;j++)
			while(x%j==0)
				x/=j,a[j].push_back(i);
		if(x>1)
			a[x].push_back(i);
	}
	for(int i=1;i<N;i++)
		if(a[i].size()>n-2)
		{
			memset(c,0,sizeof(c));
			for(int j=0;j<a[i].size();j++)
				c[a[i][j]]++;
			sort(c+1,c+n+1);
			for(int j=1;j<=max(c[1],c[2]);j++)
				A*=i;
		}
	cout<<A;
	return 0;
}