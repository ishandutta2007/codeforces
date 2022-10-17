#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n;

int a[N];

int m,q;

int main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cout<<(i<<1)+n*2<<" ";
		cout<<endl;
	}
}