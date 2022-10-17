#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=301;

int n;

vector<int>a[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		{
			for(int j=1;j<=n;j++)
				a[j].push_back((i-1)*n+j);
		}
		else
		{
			for(int j=n;j>=1;j--)
				a[n-j+1].push_back((i-1)*n+j); 
		}	
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=0;j<n;j++,putchar(' '))
			printf("%d",a[i][j]);
}