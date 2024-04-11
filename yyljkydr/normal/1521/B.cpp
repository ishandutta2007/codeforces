#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

long long T;

int n,a[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int p=min_element(a+1,a+n+1)-a;
		cout<<n-1<<"\n";		
		for(int i=1;i<=n;i++)
			if(i!=p)
				cout<<p<<" "<<i<<" "<<a[p]<<" "<<a[p]+abs(i-p)<<"\n";
	}
}