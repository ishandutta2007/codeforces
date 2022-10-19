#include<bits/stdc++.h>
using namespace std;

const int N=1e3+7;

int T,n,a[N][N];

bool isprime(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		int m=n;
		while(!isprime(m)||isprime(m-n+1))
			m++;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				printf("%d%c",1+(i==j)*(m-n)," \n"[j==n]);
	}
}